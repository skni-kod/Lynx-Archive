cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.0)

if(NOT DEFINED ${CMAKE_GENERATOR_PLATFORM})
  set(CMAKE_GENERATOR_PLATFORM "Win32")
  message("Not defined architecture - using default x86")
endif(NOT DEFINED ${CMAKE_GENERATOR_PLATFORM})

set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 14)
project("Lynx engine" VERSION 1.0)


include(${CMAKE_SOURCE_DIR}/CMake/RedirectOutputTo.cmake)
include(${CMAKE_SOURCE_DIR}/CMake/CompileFlags.cmake)
include(${CMAKE_SOURCE_DIR}/CMake/CreateSymlink.cmake)
include(${CMAKE_SOURCE_DIR}/CMake/GroupSources.cmake)
include(${CMAKE_SOURCE_DIR}/CMake/VisualStudioVersionCheck.cmake)

file(MAKE_DIRECTORY "bin")
RedirectOutputTo("bin")


option(BUILD_EXAMPLES "Build examples" ON)

### TODO:
# May we use it in the future
set(ROOT_DIR "${PROJECT_SOURCE_DIR}")
# configure a header file to pass some of the CMake settings to header
configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/configuration.h.in"
  "${PROJECT_SOURCE_DIR}/headers/common/configuration.h"
)
###

### Engine
set(ENGINE_DIR ${PROJECT_SOURCE_DIR}/src/engine)

file(GLOB_RECURSE SRC_FILES 
  ${ENGINE_DIR}/*.cpp
  ${ENGINE_DIR}/*.cxx
  ${ENGINE_DIR}/*.c
)

foreach(FILE ${SRC_FILES})
  message("[Engine]Found source file: ${FILE}")
  set(ENGINE_SRC ${LAUNCHER_SRC}  ${FILE})
endforeach(FILE)

add_library(Engine MODULE ${ENGINE_SRC})

set(EngineHeaders 
  ${PROJECT_SOURCE_DIR}/headers/engine
  ${PROJECT_SOURCE_DIR}/headers/common
)

target_include_directories(Engine PRIVATE ${EngineHeaders})

set(ENGINE_DIR ${PROJECT_SOURCE_DIR}/headers)

file(GLOB_RECURSE SRC_FILES 
  ${ENGINE_DIR}/common/*.h
  ${ENGINE_DIR}/common/*.hpp
  ${ENGINE_DIR}/common/*.hxx
  ${ENGINE_DIR}/engine/*.h
  ${ENGINE_DIR}/engine/*.hpp
  ${ENGINE_DIR}/engine/*.hxx
)

foreach(FILE ${SRC_FILES})
  message("[Engine]Found header file: ${FILE}")
  set(ENGINE_SRC ${ENGINE_SRC}  ${FILE})
endforeach(FILE)

target_sources(Engine PRIVATE ${ENGINE_SRC})
GroupSources("src/engine" "src/engine" "Source Files")


### Launcher
#one executable - launcher for engine and game(s)
set(LAUNCHER_DIR ${PROJECT_SOURCE_DIR}/src/launcher)

file(GLOB_RECURSE SRC_FILES 
  ${LAUNCHER_DIR}/*.cpp
  ${LAUNCHER_DIR}/*.cxx
  ${LAUNCHER_DIR}/*.c
)

foreach(FILE ${SRC_FILES})
  message("[Launcher]Found source file: ${FILE}")
  set(LAUNCHER_SRC ${LAUNCHER_SRC}  ${FILE})
endforeach(FILE)

add_executable(Launcher ${SRC_FILES})

set(LauncherHeaders 
  ${PROJECT_SOURCE_DIR}/headers/launcher
  ${PROJECT_SOURCE_DIR}/headers/common
)

target_include_directories(Launcher PRIVATE ${LauncherHeaders})
target_include_directories(Launcher PRIVATE ${EngineHeaders})

set(LAUNCHER_DIR ${PROJECT_SOURCE_DIR}/headers)

file(GLOB_RECURSE SRC_FILES 
  ${LAUNCHER_DIR}/common/*.h
  ${LAUNCHER_DIR}/common/*.hpp
  ${LAUNCHER_DIR}/common/*.hxx
  ${LAUNCHER_DIR}/launcher/*.h
  ${LAUNCHER_DIR}/launcher/*.hpp
  ${LAUNCHER_DIR}/launcher/*.hxx
)

foreach(FILE ${SRC_FILES})
  message("[Launcher]Found header file: ${FILE}")
  set(LAUNCHER_SRC ${LAUNCHER_SRC}  ${FILE})
endforeach(FILE)

target_sources(Launcher PRIVATE ${LAUNCHER_SRC})
GroupSources("src/launcher" "src/launcher" "Source Files")


message("Creating symbolic link to resources directory")
#Create symlink to resources in binary dir
CreateSymlink(${PROJECT_SOURCE_DIR}/bin/resources ${PROJECT_SOURCE_DIR}/resources)


message("Copy external library to bin")
#copy external dlls to bin folder
file(GLOB_RECURSE DLLS RELATIVE ${PROJECT_SOURCE_DIR}/dll
  ${PROJECT_SOURCE_DIR}/dll/*.dll
  ${PROJECT_SOURCE_DIR}/dll/*.lib
  ${PROJECT_SOURCE_DIR}/dll/*.obj
)

foreach(DLL ${DLLS})
  if(WIN32)
    file(COPY ${PROJECT_SOURCE_DIR}/dll/${DLL}
        DESTINATION ${PROJECT_SOURCE_DIR}/bin/)
  elseif(UNIX AND NOT APPLE)
    file(COPY ${DLL} DESTINATION ${PROJECT_SOURCE_DIR}/bin/)
  endif(WIN32)
endforeach(DLL)
