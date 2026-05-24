cmake_minimum_required(VERSION 3.20)

# Kernel source files
set(KERNEL_SOURCES
    core/main.cpp
    core/cpu.cpp
    memory/memory.cpp
    memory/paging.cpp
    interrupt/idt.cpp
    interrupt/irq.cpp
)

# Add kernel library
add_library(kernel STATIC ${KERNEL_SOURCES})

# Include directories
target_include_directories(kernel PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Subdirectories
add_subdirectory(core)
add_subdirectory(memory)
add_subdirectory(interrupt)
