#ifndef DRIVERS_UART_H
#define DRIVERS_UART_H

#include <stdint.h>

/**
 * Since this project is using only one UART for command line interface and log output,
 * This is created to operate onlu on UART0
 */

/// @brief Uart error codes
typedef enum
{
    UART_STATUS_OK = 0U,
    UART_STATUS_ERROR = 1U,
    UART_STATUS_TIMEOUT = 2U,
} uart_st_e;

/// @brief UART0 register mapping
typedef struct
{
    volatile uint32_t fifo;
    volatile uint32_t int_raw;
    volatile uint32_t int_st;
    volatile uint32_t int_en;
    volatile uint32_t int_clr;
    volatile uint32_t clk_div;
    volatile uint32_t rx_filt;
    volatile uint32_t status;
    volatile uint32_t conf0;
    volatile uint32_t conf1;
    /* There is no need for more registers for now... */
} uart_regs_t;

#define UART0_BASE_ADDR (0x60000000UL) /* Implementation of register offset in esp32c6 */
#define UART0 ((uart_regs_t*)UART0_BASE_ADDR)

/* --- Public driver's API --- */
#ifdef __cplusplus
extern "C"
{
#endif

    uart_st_e UART_Init(void);
    uart_st_e UART_DeInit(void);
    uart_st_e UART_WriteChar(const char c);
    uart_st_e UART_WriteString(const char* const str);

#ifdef __cplusplus
}
#endif

#endif /* DRIVERS_UART_H */