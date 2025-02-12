cmake_minimum_required(VERSION 3.21)

project(
        rvx
        VERSION 0.1
        DESCRIPTION "Minimalistic CLI/TUI RISC-V execution emulator"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Include external libraries setup
include(cmake/IncludeExternalLibraries.cmake)

add_subdirectory(bin)
add_subdirectory(lib)

enable_testing()
add_subdirectory(tests)
