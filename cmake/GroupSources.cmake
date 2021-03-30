 # I then wrote this Macro, which organize the files in visual studio folders,
 # according to the organization in the file systems

macro(GroupSources curdir basedir dirname )
        file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir}
                ${PROJECT_SOURCE_DIR}/${curdir}/*
        )
        foreach(child ${children})
                if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
                        GroupSources("${curdir}/${child}" "${basedir}" "${dirname}")
                else()
                        string(REPLACE "${basedir}" "${dirname}" groupname ${curdir})
                        string(REPLACE "/" "\\" groupname ${groupname})
                        
                        source_group(${groupname} FILES
                                ${PROJECT_SOURCE_DIR}/${curdir}/${child})
                endif()
        endforeach(child)
endmacro()