cmake_minimum_required(VERSION 3.20)

# Bootloader (Phase 1 - Mode réel)
add_custom_target(bootloader ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Building bootloader..."
    SOURCES boot.asm
)

# Boot sector (512 bytes)
set_target_properties(bootloader PROPERTIES
    LINKER_LANGUAGE C
)
