#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

int main(void) {

    RCC_APB2PheriphClockCmd(RCC_APB2Pheriph_GPIOB, ENABLE);
    
    GPIO_InitTypDef BLINK;
    BLINK.GPIO_Mode = GPIO_Mode_Out_PP;
    BLINK.GPIO_Speed = GPIO_Speed_2MHz;
    BLINK.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOB, &BLINK);

    while(1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_2);
        for(int i = 0; i < 300000; i++);
        GPIO_ResetBits(GPIOB, GPIO_Pin_2);
        for(int i = 0; i < 300000; i++);
    }
}