cmake_minimum_required(VERSION 3.25)

project(Fraction VERSION 0.0.1.0 LANGUAGES CXX)

include(cmake/utilities.cmake)

option(BUILD_EXAMPLES "Build example programs" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable `__cplusplus` macro to reflect the actual C++ standard version
if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

convert_pascalcase_to_upper_snakecase(
    ${PROJECT_NAME}
    PROJECT_NAME_UPPER_SNAKECASE
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/matho/config.hpp
)

# Build library
add_library(fraction)
add_library(matho::Fraction ALIAS fraction)

target_sources(fraction
    PRIVATE
        library/fraction.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/matho/fraction_exception.hpp
            include/matho/fraction.hpp
)
target_include_directories(fraction PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Build examples
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
