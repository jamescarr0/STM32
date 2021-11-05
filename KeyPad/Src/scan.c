#include <stdio.h>

#include "main.h"


void scanColumn(GPIOx_IDR_t volatile *const pCol_pPortD_InReg, char const keyPadPinNum) {

	switch (keyPadPinNum) {

	// Pin 8 (orange) of Matrix Keypad Connections [1,2,3,A]
	case 8:
		if (!pCol_pPortD_InReg->pin_0) {
			printf("Button 1 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_1) {
			printf("Button 2 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_2) {
			printf("Button 3 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_3) {
			printf("Button A pressed\n");
		}
		break;

		// Pin 7 (green) of Matrix Keypad Connections [4,5,6,B]
	case 7:
		if (!pCol_pPortD_InReg->pin_0) {
			printf("Button 4 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_1) {
			printf("Button 5 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_2) {
			printf("Button 6 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_3) {
			printf("Button B pressed\n");
		}
		break;

		// Pin 6 (purple) of Matrix Keypad Connections [7,8,9,C]
	case 6:
		if (!pCol_pPortD_InReg->pin_0) {
			printf("Button 7 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_1) {
			printf("Button 8 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_2) {
			printf("Button 9 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_3) {
			printf("Button C pressed\n");
		}
		break;

		// Pin 5 (blue) of Matrix Keypad Connections [*,0,#,D]
	case 5:
		if (!pCol_pPortD_InReg->pin_0) {
			printf("Button * pressed\n");
		} else if (!pCol_pPortD_InReg->pin_1) {
			printf("Button 0 pressed\n");
		} else if (!pCol_pPortD_InReg->pin_2) {
			printf("Button # pressed\n");
		} else if (!pCol_pPortD_InReg->pin_3) {
			printf("Button D pressed\n");
		}
		break;
	}

}
