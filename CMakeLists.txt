cmake_minimum_required(VERSION 3.16)
project(NES LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) #places built binary at the root of build

add_subdirectory(vendor)
add_subdirectory(src)
