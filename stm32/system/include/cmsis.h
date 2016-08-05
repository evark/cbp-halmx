#ifndef CMSIS_H
#define CMSIS_H

#if defined (STM32F103xB) 
#include "stm32f1xx.h"
#define NVIC_NUM_VECTORS      59
#define NVIC_USER_IRQ_OFFSET  16
#define NVIC_RAM_VECTOR_ADDRESS   (0x20000000)  // Vectors positioned at start of RAM
#define NVIC_FLASH_VECTOR_ADDRESS (0x08000000)  // Initial vector position in flash
#endif

#if defined (STM32F401xE)
#include "stm32f4xx.h"
#define NVIC_NUM_VECTORS      101
#define NVIC_USER_IRQ_OFFSET  16
#define NVIC_RAM_VECTOR_ADDRESS   (0x20000000)  // Vectors positioned at start of RAM
#define NVIC_FLASH_VECTOR_ADDRESS (0x08000000)  // Initial vector position in flash
#endif

#if defined (STM32F411xE)
#include "stm32f4xx.h"
#define NVIC_NUM_VECTORS      102
#define NVIC_USER_IRQ_OFFSET  16
#define NVIC_RAM_VECTOR_ADDRESS   (0x20000000)  // Vectors positioned at start of RAM
#define NVIC_FLASH_VECTOR_ADDRESS (0x08000000)  // Initial vector position in flash
#endif

#if defined (STM32L476xx)
#include "stm32l4xx.h"
#define NVIC_NUM_VECTORS      98
#define NVIC_USER_IRQ_OFFSET  16
#define NVIC_RAM_VECTOR_ADDRESS   (0x10000000)  // Vectors positioned at start of SRAM2
#define NVIC_FLASH_VECTOR_ADDRESS (0x08000000)  // Initial vector position in flash
#endif

#include "cmsis_nvic.h"

#endif
