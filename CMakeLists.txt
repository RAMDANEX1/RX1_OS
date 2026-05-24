cmake_minimum_required(VERSION 3.20)
project(RX1_OS C CXX ASM)

# Configuration de la compilation
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Répertoires sources
add_subdirectory(bootloader)
add_subdirectory(kernel)
add_subdirectory(drivers)
add_subdirectory(filesystem)
add_subdirectory(libs)

# Target pour le kernel image
add_custom_target(kernel_image ALL
    DEPENDS kernel
    COMMAND ${CMAKE_COMMAND} -E echo "Building kernel image..."
)

# Target de nettoyage
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} --build . --target clean
)
