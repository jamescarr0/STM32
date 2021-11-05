#include <stdint.h>
#include <stdio.h>

#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	// Enable GPIO clock(s).
	RCC_AHB1ENR_t volatile *const ptrClkCtrlReg = (RCC_AHB1ENR_t *) 0x40023830;
	ptrClkCtrlReg->GPIOD_EN = ON;
	ptrClkCtrlReg->GPIOA_EN = ON;

	// Set Pin PD-12 - GPIO_D Mode register to general purpose output mode (01).
	GPIO_MODER_t volatile *const pPortD_ModeReg = (GPIO_MODER_t *) 0x40020C00;
	pPortD_ModeReg->pin_12 = ON;

	// Set Pin PA0 - GPIO_A Mode register to input mode (00)
	GPIO_MODER_t volatile *const pPortA_ModeReg = (GPIO_MODER_t *) 0x40020000;
	pPortA_ModeReg->pin_0 = 0;

	// Pointer to Pin PD12 (Green LED) output data register.
	GPIOx_ODR_t volatile *const pPortD_OutReg = (GPIOx_ODR_t *) 0x40020C14;

	// Pointer to Pin PA0 Input register
	GPIOx_IDR_t volatile *const pPortA_InReg = (GPIOx_IDR_t *) 0x40020010;

	/* Loop forever */
	while (1) {
		if (pPortA_InReg->pin_0) {
			pPortD_OutReg->pin_12 = ON;
		} else {
			pPortD_OutReg->pin_12 = OFF;
		}
	}
}
