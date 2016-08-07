#include<Arduino.h>
#include "usart.h"

uint8_t buf[]="HELLO\n";

void setup()
{
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    MX_USART2_UART_Init();
}

/******************************************************************/

void loop()
{
    HAL_UART_Transmit(&huart2,buf,strlen((const char*)buf),100);
}
