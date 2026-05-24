cmake_minimum_required(VERSION 3.20)

set(DRIVERS_SOURCES
    # Ajoutez les fichiers source des drivers ici
)

add_library(drivers STATIC ${DRIVERS_SOURCES})

target_include_directories(drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
