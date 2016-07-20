#include <cmsis.h>

/// LED on Bluepill and Nucleo

#ifdef STM32F103xB
    #define LEDPORT GPIOC
    #define LEDPIN  GPIO_PIN_13
#else
    #define LEDPORT GPIOA
    #define LEDPIN  GPIO_PIN_5
#endif

int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

   __HAL_RCC_GPIOC_CLK_ENABLE();
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
  }
}
