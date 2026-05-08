cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT ON)
include(pico_sdk_import.cmake)

project(synth C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(synth
    main.c
    usb_descriptors.c
)

target_include_directories(synth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(synth 
    pico_stdlib 
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(synth)
