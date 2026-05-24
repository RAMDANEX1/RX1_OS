cmake_minimum_required(VERSION 3.20)

set(LIBS_SOURCES
    string.cpp
    stdlib.cpp
)

add_library(os_libs STATIC ${LIBS_SOURCES})

target_include_directories(os_libs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
