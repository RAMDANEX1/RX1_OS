cmake_minimum_required(VERSION 3.20)

set(INTERRUPT_SOURCES
    idt.cpp
    irq.cpp
)

add_library(kernel_interrupt STATIC ${INTERRUPT_SOURCES})

target_include_directories(kernel_interrupt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
