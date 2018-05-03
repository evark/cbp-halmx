/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

void pinMode( uint32_t ulPin, uint32_t ulMode )
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    // Handle the case the pin isn't usable as PIO
    if ( digitalPinToPort(ulPin) == NULL )
        return;

    // Find port and enable CLOCK
    if ( digitalPinToPort(ulPin) == GPIOA )
        __HAL_RCC_GPIOA_CLK_ENABLE();

    if ( digitalPinToPort(ulPin) == GPIOB )
        __HAL_RCC_GPIOB_CLK_ENABLE();

    if ( digitalPinToPort(ulPin) == GPIOC )
        __HAL_RCC_GPIOC_CLK_ENABLE();

#if defined GPIOD_BASE
    if ( digitalPinToPort(ulPin) == GPIOD )
        __HAL_RCC_GPIOD_CLK_ENABLE();
#endif
#if defined GPIOE_BASE
    if ( digitalPinToPort(ulPin) == GPIOE )
        __HAL_RCC_GPIOE_CLK_ENABLE();
#endif
#if defined GPIOF_BASE
    if ( digitalPinToPort(ulPin) == GPIOF )
        __HAL_RCC_GPIOF_CLK_ENABLE();
#endif
#if defined GPIOG_BASE
    if ( digitalPinToPort(ulPin) == GPIOG )
        __HAL_RCC_GPIOG_CLK_ENABLE();
#endif
#if defined GPIOH_BASE
    if ( digitalPinToPort(ulPin) == GPIOH )
        __HAL_RCC_GPIOH_CLK_ENABLE();
#endif
#if defined GPIOI_BASE
    if ( digitalPinToPort(ulPin) == GPIOH )
        __HAL_RCC_GPIOI_CLK_ENABLE();
#endif

    GPIO_InitStruct.Pin = digitalPinToBitMask(ulPin);

    switch ( ulMode ) {
    case INPUT:
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        break ;

    case INPUT_PULLUP:
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        break ;

    case INPUT_PULLDOWN:
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        break ;

    case OUTPUT:
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        break ;
    }
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(digitalPinToPort(ulPin), &GPIO_InitStruct);
}

void digitalWrite( uint32_t ulPin, uint32_t ulVal )
{
    if ( digitalPinToPort(ulPin) == NULL ) {
        return ;
    }
    switch ( ulVal ) {
    case LOW:
        HAL_GPIO_WritePin(digitalPinToPort(ulPin), digitalPinToBitMask(ulPin),GPIO_PIN_RESET);
        break;
    case HIGH:
        HAL_GPIO_WritePin(digitalPinToPort(ulPin), digitalPinToBitMask(ulPin),GPIO_PIN_SET);
        break ;
    }
    return ;
}

int digitalRead( uint32_t ulPin )
{
    // Handle the case the pin isn't usable as PIO
    if ( digitalPinToPort(ulPin) == NULL ) {
        return LOW ;
    }
    if(HAL_GPIO_ReadPin(digitalPinToPort(ulPin), digitalPinToBitMask(ulPin)) == GPIO_PIN_RESET)
        return LOW ;
    else
        return HIGH;
}


void digitalToggle( uint32_t ulPin )
{
    if ( digitalPinToPort(ulPin) == NULL ) {
        return ;
    }
    HAL_GPIO_TogglePin(digitalPinToPort(ulPin), digitalPinToBitMask(ulPin));
}

#ifdef __cplusplus
}
#endif

