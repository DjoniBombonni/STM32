#include "../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
//#include "../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

int main(void) {

    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    GPIOB->CRL &= GPIO_CRL_CNF2_0;
    GPIOB->CRL |= GPIO_CRL_MODE2_1;

    while(1) {
        GPIOB->ODR ^= GPIO_ODR_ODR2;
        for(int i = 0; i < 3000000; i++);
    }
    
}