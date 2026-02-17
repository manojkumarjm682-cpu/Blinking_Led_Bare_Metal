#include <stdint.h>

/* Register addresses for STM32F103 */

#define RCC_APB2ENR   (*(volatile uint32_t*)0x40021018)
#define GPIOA_CRL     (*(volatile uint32_t*)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t*)0x4001080C)

void delay(void)
{
    for(volatile uint32_t i = 0; i < 300000; i++);
}

int main(void)
{
    /* 1. Enable clock for GPIOA */
    RCC_APB2ENR |= (1 << 2);

    /* 2. Configure PA0 as Output Push-Pull 2MHz */
    GPIOA_CRL &= ~(0xF << 0);   // Clear bits for pin 0
    GPIOA_CRL |=  (0x2 << 0);   // MODE0=10, CNF0=00

    while(1)
    {
        GPIOA_ODR ^= (1 << 0);  // Toggle PA0
        delay();
    }
}
