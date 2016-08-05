//
// This file is part of the µOS++ III distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include "cmsis.h"

// ----------------------------------------------------------------------------

extern unsigned int __vectors_start;

// Forward declarations.

void __initialize_hardware_early(void);
void __initialize_hardware(void);

// ----------------------------------------------------------------------------

// This is the early hardware initialisation routine, it can be
// redefined in the application for more complex cases that
// require early inits (before BSS init).
//
// Called early from _start(), right before data & bss init.
//
// After Reset the Cortex-M processor is in Thread mode,
// priority is Privileged, and the Stack is set to Main.

void __attribute__((weak)) __initialize_hardware_early(void)
{
  // Call the CSMSIS system initialisation routine.
  SystemInit();

#if defined(OS_DEBUG_SEMIHOSTING_FAULTS)
  SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;
#endif
}


void __attribute__((weak)) SystemClock_Config(void)
{
}

// This is the second hardware initialisation routine, it can be
// redefined in the application for more complex cases that
// require custom inits (before constructors), otherwise these can
// be done in main().
//
// Called from _start(), right after data & bss init, before
// constructors.

void __attribute__((weak)) __initialize_hardware(void)
{
  // Initialise the HAL Library; it must be the first function
  // to be executed before the call of any HAL function.
  HAL_Init();
  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_AFIO_REMAP_SWJ_NOJTAG();

  // Enable HSE Oscillator and activate PLL with HSE as source
  SystemClock_Config();

  // Call the CSMSIS system clock routine to store the clock frequency
  // in the SystemCoreClock global RAM location.
  SystemCoreClockUpdate();
  // Initialize Again Tick after Clock Update
  HAL_InitTick(TICK_INT_PRIORITY);
}

// ----------------------------------------------------------------------------
