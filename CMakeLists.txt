# ChatGPT generated. CMakeLists.txt is EDITED but not WRITTEN by us.
cmake_minimum_required(VERSION 3.18)
project(Blunder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Add external libraries
add_subdirectory(${LIB_DIR}/glm)

# Source and header files
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h)
file(GLOB_RECURSE TEST_FILES tests/*.cpp tests/*.h)

# Create shared library for project source
add_library(blunder_core ${SRC_FILES})
target_include_directories(blunder_core PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(blunder_core PUBLIC glm)

# Main executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE blunder_core)

# Test executable
add_executable(${PROJECT_NAME}Tests ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}Tests PRIVATE blunder_core)

# Include dirs for tests (optional since blunder_core is PUBLIC)
target_include_directories(${PROJECT_NAME}Tests PRIVATE ${LIB_DIR})

# Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

    add_dependencies(${PROJECT_NAME} doc)
else()
    message(WARNING "Doxygen not found on your system. Doxygen docs will not be generated.")
endif()
