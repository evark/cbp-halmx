#include<Arduino.h>

#ifdef STM32F103xB
/* BLUE PILL */
#define LEDPORT GPIOC
#define LEDPIN  GPIO_PIN_13
#else
/* NUCLEO */
#define LEDPORT GPIOA
#define LEDPIN  GPIO_PIN_5
#endif

/// GPIO macros for maximum speed
///
#define gpio_toggle(GPIOx, GPIO_Pin)		((GPIOx)->ODR ^= (GPIO_Pin))
#define gpio_clear(GPIOx, GPIO_Pin)			((GPIOx)->BSRR = (uint32_t)(((uint32_t)GPIO_Pin) << 16))
#define gpio_set(GPIOx, GPIO_Pin)			((GPIOx)->BSRR = (uint32_t)(GPIO_Pin))
#define gpio_write(GPIOx, GPIO_Pin, val)	((val) ? gpio_set(GPIOx, GPIO_Pin) : gpio_clear(GPIOx, GPIO_Pin)

void gpio_setup_output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
  GPIO_InitStruct.Pin = GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void setup()
{
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    gpio_setup_output(LEDPORT, LEDPIN);
}

/******************************************************************/

void loop()
{
    gpio_toggle(LEDPORT, LEDPIN);
    HAL_Delay(50);
}
