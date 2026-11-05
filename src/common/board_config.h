#ifndef COMMON_BOARD_CONFIG_H
#define COMMON_BOARD_CONFIG_H

/* --- Configuration of system tick --- */
#define BOARD_CPU_CLOCK_HZ 160000000ULL /* 160 MHz for esp32c6*/

/* --- UART driver configuration --- */
#define BOARD_UART0_BAUDRATE 115200ULL
#define BOARD_UART0_DATA_BITS 8U
#define BOARD_UART0_STOP_BITS 1U

/* --- GPIO mapping --- */
#define BOARD_UART0_TX_PIN 16U
#define BOARD_UART0_RX_PIN 17U

/* --- Safety Timeouts --- */
#define BOARD_UART_TIMEOUT_COUNT 100000U /* Count, because it will be needed even before RTOS starts its work */

#endif /* COMMON_BOARD_CONFIG_H */