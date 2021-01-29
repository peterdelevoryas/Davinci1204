cmake_minimum_required(VERSION 3.19)
project(Davinci1204)

set(COMPILER Davinci1204c)

add_executable(${COMPILER} main.cpp)
target_compile_options(${COMPILER} PRIVATE -Wall -g -Og)

enable_testing()
add_test(NAME Sanity COMMAND ${COMPILER} ${CMAKE_SOURCE_DIR}/test.dv)
