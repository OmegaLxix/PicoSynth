cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT ON)

include(pico_sdk_import.cmake)


project(synth C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

pico_enable_stdio_usb(synth 1)
pico_enable_stdio_uart(synth 1)

# Use the name "synth" directly (no ${} needed here)
add_executable(synth
    main.c
)

target_link_libraries(synth pico_stdlib)

pico_add_extra_outputs(synth)

set_target_properties(synth PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
