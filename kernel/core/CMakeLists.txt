cmake_minimum_required(VERSION 3.20)

set(CORE_SOURCES
    main.cpp
    cpu.cpp
)

add_library(kernel_core STATIC ${CORE_SOURCES})

target_include_directories(kernel_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
