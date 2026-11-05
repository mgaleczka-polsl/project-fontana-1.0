#include "uart.h"
#include "pcr_regs.h"

extern void esp_rom_delay_us(uint32_t us);

/* --- Variables & Definitions --- */

/* --- Helpers --- */

/* --- API --- */
uart_st_e UART_Init(void)
{
    /* Turn the CLK on */
    PCR->uart0_conf |= PCR_UART0_CLK_EN_BIT_MSK;

    /* Hardware reset of uart0 module */
    PCR->uart0_conf |= PCR_UART0_RST_EN_BIT_MSK;

    /* Waiting some time for reset to happen */
    for (volatile uint8_t i = 0U; i < 10U; i++)
    {
    }

    /* Turning back RST mask to 0 */
    PCR->uart0_conf &= ~PCR_UART0_RST_EN_BIT_MSK;

    /* Setting Baudrate */
    PCR->uart0_sclk_conf &= ~(PCR_UART0_SCLK_DIV_A_BIT_MSK | PCR_UART0_SCLK_DIV_B_BIT_MSK |
                              PCR_UART0_SCLK_DIV_NUM_BIT_POS | PCR_UART0_SCLK_SEL_BIT_POS | PCR_UART0_SCLK_EN_BIT_POS);

    PCR->uart0_sclk_conf |= ((uint32_t)3U << PCR_UART0_SCLK_SEL_BIT_POS);
    
    /* Setting CLK origin */
    /* Enabling UART0 */

    return UART_STATUS_OK;
}
