# --- Path to directory with toolchain ---
set(TOOLCHAIN_PATH "${CMAKE_CURRENT_LIST_DIR}/.compiler/riscv32-esp-elf")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/bin/riscv32-esp-elf-gcc.exe")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/bin/riscv32-esp-elf-g++.exe")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/bin/riscv32-esp-elf-gcc.exe")

# --- Flags for esp32c6 ---
# -march=rv32imac: multiplification, atomic operations, short instructions
# -mabi=ilp32: Standard ABI interface for 32-bit riscv
set(ARCH_FLAGS "-march=rv32imac -mabi=ilp32 -mcmodel=medany")

set(CMAKE_C_FLAGS "${ARCH_FLAGS} -ffunction-sections -fdata-sections" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${ARCH_FLAGS} -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections" CACHE STRING "" FORCE)

# --- Directory rules for find in toolchain ---
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
