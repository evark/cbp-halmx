#include <cmsis.h>

/*

 Simple Blink Test with HAL_Delay (Systick working) and IRQ SysTick vector relocation in RAM

*/

#ifdef STM32F103xB
/* BLUE PILL */
#define LEDPORT GPIOC
#define LEDPIN  GPIO_PIN_13
#else
/* NUCLEO */
#define LEDPORT GPIOA
#define LEDPIN  GPIO_PIN_5
#endif

void newSysTick_Handler(void) {
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    /* Relocate Vectors in Ram and assign SysTick to new function */
    NVIC_SetVector(SysTick_IRQn, (uint32_t)newSysTick_Handler);

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LEDPORT, LEDPIN, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = LEDPIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LEDPORT, &GPIO_InitStruct);
    while (1)
        {
            HAL_GPIO_TogglePin(LEDPORT, LEDPIN);
            HAL_Delay(500);
        }
}
