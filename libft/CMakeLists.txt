project(ft C)
cmake_minimum_required(VERSION 3.9)

file(GLOB_RECURSE HDRS ${HDRS} *.h)
file(GLOB_RECURSE SRCS ${SRCS} *.c)
add_library(ft ${SRCS} ${HDRS})
target_include_directories(ft PUBLIC ${CMAKE_CURRENT_LIST_DIR})
