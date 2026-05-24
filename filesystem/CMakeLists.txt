cmake_minimum_required(VERSION 3.20)

set(FILESYSTEM_SOURCES
    # Ajoutez les fichiers source du système de fichiers ici
)

add_library(filesystem STATIC ${FILESYSTEM_SOURCES})

target_include_directories(filesystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
