cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(synth C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${synth}
    src/main.c
    # add other .c/.cpp files
)

target_link_libraries(${synth} pico_stdlib)  # Add other libraries as needed

pico_add_extra_outputs(${synth})  # Generates .uf2, .elf, etc.
