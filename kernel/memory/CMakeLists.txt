cmake_minimum_required(VERSION 3.20)

set(MEMORY_SOURCES
    memory.cpp
    paging.cpp
)

add_library(kernel_memory STATIC ${MEMORY_SOURCES})

target_include_directories(kernel_memory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
