#ifndef COMMON_FREERTOS_CONFIG_H
#define COMMON_FREERTOS_CONFIG_H

#include <stdint.h>

// --- Main kernel settings ---
#define configUSE_PREEMPTION 1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configUSE_TICKLESS_IDLE 0
#define configCPU_CLOCK_HZ ((unsigned long)160000000U) // ESP32 has 160 MHz
#define configTICK_RATE_HZ ((TickType_t)1000)         // Context switch every 1ms
#define configMAX_PRIORITIES 5
#define configMINIMAL_STACK_SIZE ((unsigned short)256) // 4 bytes on risc-v
#define configMAX_TASK_NAME_LEN 16

// --- Memory managmenet ---
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION 0
#define configTOTAL_HEAP_SIZE ((size_t)(48 * 1024)) // 48 KB RAM assigned to RTOS HEAP

// --- Diagnostics ---
#define configUSE_TRACE_FACILITY 1
#define configUSE_STATS_FORMATTING_FUNCTIONS 1

// --- Hooks ---
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configUSE_MUTEXES 1
#define configUSE_RECURSIVE_MUTEXES 1
#define configUSE_COUNTING_SEMAPHORES 1

// --- FreeRTOS API mapping ---
#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1

// --- ISR defini ---
#define configISR_STACK_SIZE_WORDS 512

#endif /* COMMON_FREERTOS_CONFIG_H */