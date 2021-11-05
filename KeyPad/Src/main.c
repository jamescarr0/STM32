#include <stdint.h>

#include "main.h"

static void pullAllRowsHigh(GPIOx_ODR_t volatile* const);
extern void scanColumn(GPIOx_IDR_t volatile* const, char);

int main(void) {

	// Create and initiliase AHB1ENR peripheral clock.
	RCC_AHB1ENR_t volatile *const pClkCtrlReg = ADDR_REG_AHB1ENR;

	// Enable general purpose input/output (GPIO) ports B & D.
	pClkCtrlReg->GPIOB_EN = CLOCK_ENABLE;
	pClkCtrlReg->GPIOD_EN = CLOCK_ENABLE;

	// Create and initialise GPIO pointers to mode registers B & D.
	GPIO_MODER_t volatile *const pPortB_ModeReg = GPIOB_MODE_REG;
	GPIO_MODER_t volatile *const pPortD_ModeReg = GPIOD_MODE_REG;

	// GPIO_B: Set Row I/O to Output mode [0b01]
	pPortB_ModeReg->pin_4 = MODE_OUTPUT;
	pPortB_ModeReg->pin_5 = MODE_OUTPUT;
	pPortB_ModeReg->pin_7 = MODE_OUTPUT;
	pPortB_ModeReg->pin_8 = MODE_OUTPUT;

	// GPIO_D: Set Column I/O to Input mode [0b00]
	pPortD_ModeReg->pin_0 = MODE_INPUT;
	pPortD_ModeReg->pin_1 = MODE_INPUT;
	pPortD_ModeReg->pin_2 = MODE_INPUT;
	pPortD_ModeReg->pin_3 = MODE_INPUT;

	// Enable pull-up resistors for all column I/O's (GPIO_D)
	// Create and initialise pointer to pull up/pull down register address
	// Offset 0x0C
	GPIO_PUPDR_t volatile *const pPortD_PUPDR = GPIOD_PUPD_REG;
	pPortD_PUPDR->pin_0 = PULL_UP_RES_HIGH;
	pPortD_PUPDR->pin_1 = PULL_UP_RES_HIGH;
	pPortD_PUPDR->pin_2 = PULL_UP_RES_HIGH;
	pPortD_PUPDR->pin_3 = PULL_UP_RES_HIGH;

	// Create an initialise pointer to the ROWS output data register (GPIO_B).
	// Offset 0x14
	GPIOx_ODR_t volatile *const pRow_PortB_OutReg = GPIOB_OUTPUT_REG;

	// Create an initialise pointer to the COLUMNS input data register.
	// Offset 0x10
	GPIOx_IDR_t volatile *const pCol_PortD_InReg = GPIOD_INPUT_REG;

	// Set all ROW pins HIGH.
	pullAllRowsHigh(pRow_PortB_OutReg);

	while (1) {

		pRow_PortB_OutReg->pin_8 = PIN_STATE_LOW; // Pull KeyPad Pin 8 low.
		scanColumn(pCol_PortD_InReg, 8); // Scan columns for button sinking current.
		pullAllRowsHigh(pRow_PortB_OutReg); // Reset state:  Pull all rows high.

		pRow_PortB_OutReg->pin_7 = PIN_STATE_LOW; // Pull KeyPad Pin 7 low.
		scanColumn(pCol_PortD_InReg, 7);
		pullAllRowsHigh(pRow_PortB_OutReg);

		pRow_PortB_OutReg->pin_5 = PIN_STATE_LOW; // Pull KeyPad Pin 6 low.
		scanColumn(pCol_PortD_InReg, 6);
		pullAllRowsHigh(pRow_PortB_OutReg);

		pRow_PortB_OutReg->pin_4 = PIN_STATE_LOW; // Pull KeyPad Pin 5 low.
		scanColumn(pCol_PortD_InReg, 5);
		pullAllRowsHigh(pRow_PortB_OutReg);
	}
}

static void pullAllRowsHigh(GPIOx_ODR_t volatile *const pRow_PortB_OutReg) {
	pRow_PortB_OutReg->pin_4 = PIN_STATE_HIGH;
	pRow_PortB_OutReg->pin_5 = PIN_STATE_HIGH;
	pRow_PortB_OutReg->pin_7 = PIN_STATE_HIGH;
	pRow_PortB_OutReg->pin_8 = PIN_STATE_HIGH;
}
