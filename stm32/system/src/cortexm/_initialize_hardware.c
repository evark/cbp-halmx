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
  HAL_Init();
  SystemCoreClockUpdate();
  HAL_InitTick(TICK_INT_PRIORITY);

  SystemClock_Config();
  SystemCoreClockUpdate();
  HAL_InitTick(TICK_INT_PRIORITY);
}

// ----------------------------------------------------------------------------
