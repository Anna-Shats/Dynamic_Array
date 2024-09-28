# Top-Level CMakeLists.txt

cmake_minimum_required(VERSION 3.14)
project(DynamicArrayProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(DynamicArray STATIC src/dynamic.cpp)
target_include_directories(DynamicArray PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)


find_package(Doxygen REQUIRED)

if(DOXYGEN_FOUND)
    # Set input and output directories
    set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/tests)
    set(DOXYGEN_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/docs)

    # Configure Doxyfile using the template
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    # Add custom target for documentation
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

else()
    message(FATAL_ERROR "Doxygen is needed to generate the documentation. Please install it.")
endif()