# Enviroment architecture

## IDE & Extensions
My choice of IDE was VSCode, because it is free, reliant, and has many useful extensions. Also i was most familiar with that one. 

List of extensions needed for full experience with this project and it's development:
- C/C++ (Microsoft)
- CMake Tools
- Cortex-Debug
- RTOS Views
- Test Explorer UI
- TestMate C++

## Cross-Toolchain RISC-V
The compiler is chosen by a processor architecture (RV32IMAC) used in ESP32-C6.

## CMake & Toolchain File
Files CMakeLists.txt and esp32c6-toolchain.cmake implement configuration of this project.

## Ninja Build Engine
It was chosen because of its speed, compatibility with CMake Tools and it can be run in any enviroment.

## FreeRTOS Integration
Because ESP-IDF is not MISRA compliant this project use from clean FreeRTOS.
It was added to project as an external submodule and configured in `src/common/FreeRTOSConfig.h`.
It was configured to work on 160 Mhz with heap size of 48 KB. Also low-level assembly port was connected.
