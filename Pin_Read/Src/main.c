#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialised, but the project is compiling for an FPU. Please initialise the FPU before use."
#endif


int main(void) {
	// Address of the clock control registers (AHB1ENR Bus)
	// RCC Base address = 0x40023800
	// Offset = 0x30

	uint32_t volatile *pClkCtrlReg = (uint32_t*)0x40023830;

	// Address of the GPIOD mode register (Sets mode input/output)
	// GPIOD Base Address 0x40020C00
	// Address of the GPIOA mode register (Sets mode input/output)
	// GPIOA Base Address 0x40020000
	// Offset = 0x00

	uint32_t volatile *const pPortD_ModeReg = (uint32_t*) 0x40020C00;
	uint32_t volatile *const pPortA_ModeReg = (uint32_t*) 0x40020000;

	// Address of the GPIOD output data register (Writing data)
	// GPIOD Base Address 0x40020C00
	// Offset = 0x14
	uint32_t volatile *const pPortD_OutReg = (uint32_t*) 0x40020C14;

	// Address of GPIOA input data register
	// GPIOA Base address
	// Offset = 0x10
	// Const Pointer, pointing to volatile const data.  Volatile const data can be changed by the user
	// such as a button press, but cannot be changed by the programmer.
	// eg. Reading from read-only buffer or address which can change such as input data register.
	uint32_t const volatile *const pPortA_InReg = (uint32_t*) 0x40020010;

	// Enable the D clock, Set the third bit position to 1.
	// Binary position for Bit 3 is b1000 = 0x08

	//*pClkCtrlReg |= 0x08;
	// GPIOD Bit 3 enable/disable clock.
	// GPIOA Bit 1 enable/disable clock.
	*pClkCtrlReg |= (1 << 3); // GPIOD
	*pClkCtrlReg |= (1 << 0); // GPIOA


	// Set D Port Mode Pin 12 to Output - Bit positions 25 & 24.
	// Clear bit positions 25 & 24.
	*pPortD_ModeReg &= ~(3 << 24);// 3 = 0b11. shift left 24 bits will clear bits 24 and 25 - (1)[pos25] (1)[post24].

	// Set A Port Mode Pin 0 to Input (reset state 00).
	// Clear bit positions 1 & 0.
	*pPortA_ModeReg &= ~(3 << 0);

	// Set Bit position 24 to 1.
	*pPortD_ModeReg |= (1 << 24);


	/* Loop forever */
	while(1) {
			if (*pPortA_InReg & 0x1) {
				*pPortD_OutReg |= (1 << 12);
			} else {
				*pPortD_OutReg &= ~(1 << 12);
			}
	}
}
