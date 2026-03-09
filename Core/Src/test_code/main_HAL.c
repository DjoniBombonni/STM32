#include "main.h"
//#include "../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"
//#include "../../../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"
//#include "stm32f1xx_hal_conf.h"

int main(void) {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    GPIO_InitTypeDef GPIOB_Init;
    GPIOB_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIOB_Init.Pin = GPIO_PIN_2;
    GPIOB_Init.Pull = GPIO_NOPULL;
    GPIOB_Init.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &GPIOB_Init);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);

    while(1) {
        for(int i = 0; i < 10000000; i += 2);
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
    }
}