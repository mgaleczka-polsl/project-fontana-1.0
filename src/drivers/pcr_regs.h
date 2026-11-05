#ifndef DRIVERS_PCR_REGS_H
#define DRIVERS_PCR_REGS_H

#include <stdint.h>

/// @brief Partial map of esp32c6 PCR (Peripherial Clock Receiver) registers.
/// Base for global Clock settings and Reset functions.
typedef struct
{
    volatile uint32_t uart0_conf;
    volatile uint32_t uart0_sclk_conf;
    volatile uint32_t uart0_pd_ctrl;
    /* NOTE In the future there will be more */
} pcr_regs_t;

/// Base address of controler's pcr block
#define PCR_BASE_ADDR (0x60096000UL)

/// Safe pointer projection
#define PCR ((pcr_regs_t*)PCR_BASE_ADDR)

/* PCR_UART0_CONF_REG (Offset 0x0000) */
#define PCR_UART0_CLK_EN_BIT_POS (0U)
#define PCR_UART0_RST_EN_BIT_POS (1U)

#define PCR_UART0_CLK_EN_BIT_MSK ((uint32_t)(uint32_t)0x1U << PCR_UART0_CLK_EN_BIT_POS) /* Turn the CLK on bit */
#define PCR_UART0_RST_EN_BIT_MSK ((uint32_t)(uint32_t)0x1U << PCR_UART0_RST_EN_BIT_POS) /* Reset UART0 bit */

/* PCR_UART0_SCLK_CONF_REG (Offset 0x0004) */
#define PCR_UART0_SCLK_DIV_A_BIT_POS (0U)
#define PCR_UART0_SCLK_DIV_B_BIT_POS (6U)
#define PCR_UART0_SCLK_DIV_NUM_BIT_POS (12U)
#define PCR_UART0_SCLK_SEL_BIT_POS (20U)
#define PCR_UART0_SCLK_EN_BIT_POS (22U)

#define PCR_UART0_SCLK_DIV_A_BIT_MSK ((uint32_t)(uint32_t)0x3FU << PCR_UART0_SCLK_DIV_A_BIT_POS)
#define PCR_UART0_SCLK_DIV_B_BIT_MSK ((uint32_t)(uint32_t)0x3FU << PCR_UART0_SCLK_DIV_B_BIT_POS)
#define PCR_UART0_SCLK_DIV_NUM_BIT_MSK ((uint32_t)(uint32_t)0xFFU << PCR_UART0_SCLK_DIV_NUM_BIT_POS)
#define PCR_UART0_SCLK_SEL_BIT_MSK ((uint32_t)(uint32_t)0x03U << PCR_UART0_SCLK_SEL_BIT_POS)
#define PCR_UART0_SCLK_EN_BIT_MSK ((uint32_t)(uint32_t)0x01U << PCR_UART0_SCLK_EN_BIT_POS)

#endif /* DRIVERS_PCR_REGS_H */