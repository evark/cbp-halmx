#include <cmsis.h>

/*

 Simple Blink Test with HAL_Delay (Systick working)

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


int main(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

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
    HAL_Delay(50);
  }
}
