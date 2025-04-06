# ChatGPT generated. CMakeLists.txt is EDITED but not WRITTEN by us.
cmake_minimum_required(VERSION 3.19)
project(Blunder LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add lib/ as a directory for external libraries
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

# Add bin/ as a directory for compiled binaries
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# ADD SOURCE FILES
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h)

# Create executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# ADD TEST FILES
file(GLOB_RECURSE TEST_FILES tests/*.cpp tests/*.h)

# Create executable
add_executable(${PROJECT_NAME}Tests ${TEST_FILES})

# Link external libraries to tests
target_link_libraries(${PROJECT_NAME}Tests PRIVATE glm)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)  # Your source files
include_directories(${LIB_DIR})  # External libraries

# Link external libraries (e.g., GLM)
add_subdirectory(${LIB_DIR}/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)  # If GLM needs to be linked, otherwise remove this line
target_include_directories(${PROJECT_NAME}Tests PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${LIB_DIR}
)

# Find Doxygen as a system package
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
