cmake_minimum_required(VERSION 3.16)

# Project definition
project(fontana LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FreeRTOS configuration
set(FREERTOS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/FreeRTOS-Kernel")
set(FREERTOS_PORT_DIR "${FREERTOS_DIR}/portable/GCC/RISC-V")

set(FREERTOS_SOURCES
    ${FREERTOS_DIR}/tasks.c
    ${FREERTOS_DIR}/queue.c
    ${FREERTOS_DIR}/list.c
    ${FREERTOS_DIR}/timers.c
    ${FREERTOS_DIR}/portable/MemMang/heap_4.c
    ${FREERTOS_PORT_DIR}/port.c
    ${FREERTOS_PORT_DIR}/portasm.S
)

# Application files configuration
set(APP_SOURCES
    src/main.cpp
    src/drivers/uart.c
)

add_executable(esp32c6 src/main.cpp)
target_link_options(esp32c6 PRIVATE "-T" "${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/link.ld")
set_target_properties(esp32c6 PROPERTIES SUFFIX ".elf")

target_include_directories(esp32c6 PRIVATE
    src/common
    ${FREERTOS_DIR}/include
    ${FREERTOS_PORT_DIR}
)

# BIN file generation
get_filename_component(COMPILER_DIR ${CMAKE_C_COMPILER} DIRECTORY)
set(OBJCOPY_PATH "${COMPILER_DIR}/riscv32-esp-elf-objcopy.exe")

add_custom_command(TARGET esp32c6 POST_BUILD
    COMMAND ${OBJCOPY_PATH} -O binary $<TARGET_FILE:esp32c6> ${CMAKE_BINARY_DIR}/esp32c6.bin
    COMMENT "Generating BIN file: ${CMAKE_BINARY_DIR}/esp32c6.bin"
)
