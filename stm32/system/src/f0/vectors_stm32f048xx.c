//
// Copyright (c) 2015 Liviu Ionescu.
// This file was automatically generated by the xPacks scripts.
//

// The list of external handlers is from the ARM assembly startup files.

// ----------------------------------------------------------------------------

#include "cortexm/ExceptionHandlers.h"

// ----------------------------------------------------------------------------

void __attribute__((weak))
Default_Handler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions

void __attribute__ ((weak, alias ("Default_Handler")))
WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
VDDIO2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RCC_CRS_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_15_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TSC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel2_3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel4_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ADC1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_BRK_UP_TRG_COM_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM14_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM16_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM17_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CEC_CAN_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_IRQHandler(void);

// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The table of interrupt handlers. It has an explicit section name
// and relies on the linker script to place it at the correct location
// in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] =
  {
    // Cortex-M Core Handlers
    (pHandler) &_estack,               // The initial stack pointer
    Reset_Handler,                     // The reset handler

    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    MemManage_Handler,                 // The MPU fault handler
    BusFault_Handler,                  // The bus fault handler
    UsageFault_Handler,                // The usage fault handler
#else
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    DebugMon_Handler,                  // Debug monitor handler
#else
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // ----------------------------------------------------------------------
    // External Interrupts
    WWDG_IRQHandler,                // Window Watchdog
    VDDIO2_IRQHandler,              // VDDIO2 Monitor through EXTI Line 31
    RTC_IRQHandler,                 // RTC through EXTI Line
    FLASH_IRQHandler,               // FLASH
    RCC_CRS_IRQHandler,             // RCC and CRS
    EXTI0_1_IRQHandler,             // EXTI Line 0 and 1
    EXTI2_3_IRQHandler,             // EXTI Line 2 and 3
    EXTI4_15_IRQHandler,            // EXTI Line 4 to 15
    TSC_IRQHandler,                 // TS
    DMA1_Channel1_IRQHandler,       // DMA1 Channel 1
    DMA1_Channel2_3_IRQHandler,     // DMA1 Channel 2 and Channel 3
    DMA1_Channel4_5_IRQHandler,     // DMA1 Channel 4 and Channel 5
    ADC1_IRQHandler,                // ADC1
    TIM1_BRK_UP_TRG_COM_IRQHandler, // TIM1 Break, Update, Trigger and Commutation
    TIM1_CC_IRQHandler,             // TIM1 Capture Compare
    TIM2_IRQHandler,                // TIM2
    TIM3_IRQHandler,                // TIM3
    0,                              // Reserved
    0,                              // Reserved
    TIM14_IRQHandler,               // TIM14
    0,                              // Reserved
    TIM16_IRQHandler,               // TIM16
    TIM17_IRQHandler,               // TIM17
    I2C1_IRQHandler,                // I2C1
    0,                              // Reserved
    SPI1_IRQHandler,                // SPI1
    SPI2_IRQHandler,                // SPI2
    USART1_IRQHandler,              // USART1
    USART2_IRQHandler,              // USART2
    0,                              // Reserved
    CEC_CAN_IRQHandler,             // CEC and CAN
    USB_IRQHandler,                 // USB
};

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a
// specific handler is not present in the application code.
// When in DEBUG, trigger a debug exception to clearly notify
// the user of the exception and help identify the cause.

void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
#if defined(DEBUG)
__DEBUG_BKPT();
#endif
while (1)
  {
  }
}

// ----------------------------------------------------------------------------
