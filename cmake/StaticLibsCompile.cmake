macro(StaticLibsCompile TARGET)
    set(DIRNAME_SRC ${PROJECT_SOURCE_DIR}/src/lib)
    set(DIRNAME_HEADER ${PROJECT_SOURCE_DIR}/headers/lib)
    
    file(GLOB LIBS_DIR RELATIVE "${DIRNAME_SRC}" "${DIRNAME_SRC}/*")

    foreach(LIB ${LIBS_DIR})
        if(IS_DIRECTORY ${DIRNAME_SRC}/${LIB} AND IS_DIRECTORY ${DIRNAME_HEADER}/${LIB})
            message("Found static lib: ${LIB}")
            file(GLOB_RECURSE LIB_SRC
                ${DIRNAME_SRC}/${LIB}/*.cpp
                ${DIRNAME_SRC}/${LIB}/*.cxx
                ${DIRNAME_SRC}/${LIB}/*.c
            )

            file(GLOB_RECURSE LIB_HEADER
                ${DIRNAME_HEADER}/${LIB}/*.h
                ${DIRNAME_HEADER}/${LIB}/*.hpp
                ${DIRNAME_HEADER}/${LIB}/*.hxx
            )

            set(LIB_HEADER_FILES)
            set(LIB_SRC_FILES)

            foreach(LIB_SRC_FILE ${LIB_SRC})
                set(LIB_SRC_FILES ${LIB_SRC_FILES} ${LIB_SRC_FILE})
                message(${LIB_SRC_FILE})
            endforeach(LIB_SRC_FILE)

            foreach(LIB_HEADER_FILE ${LIB_HEADER})
                set(LIB_HEADER_FILES ${LIB_HEADER_FILES} ${LIB_HEADER_FILE})
                message(${LIB_HEADER_FILE})
            endforeach(LIB_HEADER_FILE)

            
            add_library(${LIB} STATIC ${LIB_SRC_FILES})
            target_include_directories(${LIB} PRIVATE ${DIRNAME_HEADER}/${LIB})
            target_sources(${LIB} PRIVATE ${LIB_HEADER_FILES})

            target_include_directories(${TARGET} PRIVATE ${DIRNAME_HEADER}/${LIB})
            target_sources(${TARGET} PRIVATE ${LIB_HEADER_FILES}) 
            target_link_libraries(${TARGET} ${LIB})

        endif()
    endforeach(LIB)

endmacro(StaticLibsCompile)