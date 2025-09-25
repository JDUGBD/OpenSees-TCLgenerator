cmake_minimum_required(VERSION 3.16)
project(TCLgenerator LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# ----------------------------------------------------------------------
# Gmsh configuration
# ----------------------------------------------------------------------
set(GMSH_SDK_PATH "/home/master/gmsh-4.11.1-Linux64-sdk")

find_path(GMSH_INCLUDE_DIR gmsh.h
    HINTS ${GMSH_SDK_PATH}/include
)

find_library(GMSH_LIB gmsh
    HINTS ${GMSH_SDK_PATH}/lib
)

if (NOT GMSH_INCLUDE_DIR OR NOT GMSH_LIB)
    message(FATAL_ERROR "Gmsh not found in ${GMSH_SDK_PATH}. Please check path.")
endif()

include_directories(${GMSH_INCLUDE_DIR})
message(STATUS "Gmsh include: ${GMSH_INCLUDE_DIR}")
message(STATUS "Gmsh library: ${GMSH_LIB}")

# ----------------------------------------------------------------------
# Source files
# ----------------------------------------------------------------------
set(SOURCES
    src/AnalysisWriter.cpp
    src/BCWriter.cpp
    src/ElementWriter.cpp
    src/TCLGenerator.cpp
    src/NodeWriter.cpp
    src/MaterialWriter.cpp
    src/RecorderWriter.cpp
    src/utils.cpp
    src/TimeSeriesWriter.cpp
    src/LoadPatternWriter.cpp
    src/SectionWriter.cpp
)

set(HEADERS
    include/TCLGenerator.h
    include/BCWriter.h
    include/ElementWriter.h
    include/AnalysisWriter.h
    include/NodeWriter.h
    include/MaterialWriter.h
    include/Config.h
    include/RecorderWriter.h
    include/utils.h
    include/TimeSeriesWriter.h
    include/LoadPatternWriter.h
    include/SectionWriter.h
)

# ----------------------------------------------------------------------
# Library
# ----------------------------------------------------------------------
add_library(TCLgenerator STATIC ${SOURCES} ${HEADERS})
target_link_libraries(TCLgenerator PRIVATE ${GMSH_LIB})

# ----------------------------------------------------------------------
# Examples
# ----------------------------------------------------------------------
add_executable(example_basic examples/example_basic.cpp)
target_link_libraries(example_basic PRIVATE TCLgenerator ${GMSH_LIB})

add_executable(ex_1 examples/ex_1.cpp)
target_link_libraries(ex_1 PRIVATE TCLgenerator ${GMSH_LIB})

# ----------------------------------------------------------------------
# Enable testing (optional)
# ----------------------------------------------------------------------
# enable_testing()
# add_subdirectory(tests)
