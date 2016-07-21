#include <cmsis.h>
#include <PortNames.h>
#include <PinNames.h>


/******************************************************************/
// Enable GPIO clock and return GPIO base address
uint32_t Set_GPIO_Clock(uint32_t port_idx)
{
    uint32_t gpio_add = 0;
    switch (port_idx) {
        case PortA:
            gpio_add = GPIOA_BASE;
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        case PortB:
            gpio_add = GPIOB_BASE;
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        case PortC:
            gpio_add = GPIOC_BASE;
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;
#if defined(GPIOD_BASE)
        case PortD:
            gpio_add = GPIOD_BASE;
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;
#endif
#if defined(GPIOE_BASE)
        case PortE:
            gpio_add = GPIOE_BASE;
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;
#endif
#if defined(GPIOF_BASE)
        case PortF:
            gpio_add = GPIOF_BASE;
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;
#endif
#if defined(GPIOG_BASE)
        case PortG:
            gpio_add = GPIOG_BASE;
            __HAL_RCC_GPIOG_CLK_ENABLE();
            break;
#endif
#if defined(GPIOH_BASE)
        case PortH:
            gpio_add = GPIOH_BASE;
            __HAL_RCC_GPIOH_CLK_ENABLE();
            break;
#endif
#if defined(GPIOI_BASE)
        case PortI:
            gpio_add = GPIOI_BASE;
            __HAL_RCC_GPIOI_CLK_ENABLE();
            break;
#endif
        default:
            break;
    }
    return gpio_add;
}
/******************************************************************/


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

  Set_GPIO_Clock(PortA);
  Set_GPIO_Clock(PortB);
  Set_GPIO_Clock(PortC);
  Set_GPIO_Clock(PortD);

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
