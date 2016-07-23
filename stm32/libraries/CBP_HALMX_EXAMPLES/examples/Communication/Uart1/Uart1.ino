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
/******************************************************************/
UART_HandleTypeDef huart2;


void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
        ;
  }

}

// This is a call back from HAL_UART_Init
//
void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(uartHandle->Instance==USART2)
  {
    __HAL_RCC_USART2_CLK_ENABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
}


/******************************************************************/

int main(void)
{
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    gpio_setup_output(LEDPORT, LEDPIN);
    MX_USART2_UART_Init();
    while (1)
        {
            uint8_t buf[]="A";
            HAL_UART_Transmit(&huart2,buf,1,100);
            gpio_toggle(LEDPORT, LEDPIN);
            HAL_Delay(50);
        }
}
