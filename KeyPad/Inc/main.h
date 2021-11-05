/*
 * main.h
 *
 *  Created on: Jun 10, 2021
 *      Author: James Carr
 */

#ifndef MAIN_H_
#define MAIN_H_

// AHB1ENR Address register
#define ADDR_REG_AHB1ENR ((RCC_AHB1ENR_t*) (0x40023800 + 0x30))

#define GPIOB_MODE_REG ((GPIO_MODER_t*) 0x40020400)
#define GPIOD_MODE_REG ((GPIO_MODER_t*) 0x40020C00)

#define GPIOD_PUPD_REG ((GPIO_PUPDR_t*) (0x40020C00 + 0x0C))

#define GPIOB_OUTPUT_REG ((GPIOx_ODR_t*) (0x40020400 + 0X14))

#define GPIOD_INPUT_REG ((GPIOx_IDR_t*) (0x40020C00 + 0X10))

#define CLOCK_ENABLE (1)
#define MODE_OUTPUT (1)
#define PIN_STATE_HIGH (1)
#define PULL_UP_RES_HIGH (1)

#define MODE_INPUT (0)
#define PIN_STATE_LOW (0)


typedef struct RCC_AHB1ENR_t {
	uint32_t GPIOA_EN :1;
	uint32_t GPIOB_EN :1;
	uint32_t GPIOC_EN :1;
	uint32_t GPIOD_EN :1;
	uint32_t GPIOE_EN :1;
	uint32_t GPIOF_EN :1;
	uint32_t GPIOG_EN :1;
	uint32_t GPIOH_EN :1;
	uint32_t GPIOI_EN :1;
	uint32_t RESERVED_1 :3;
	uint32_t CRC_EN :1;
	uint32_t RESERVED_2 :3;
	uint32_t RESERVED_3 :2;
	uint32_t BKPSRAM_EN :1;
	uint32_t RESERVED_4 :2;
	uint32_t DMA1_EN :1;
	uint32_t DMA2_EN :1;
	uint32_t RESERVED_5 :2;
	uint32_t ETH_MAC_CLK_EN :1;
	uint32_t ETH_MAC_TX_EN :1;
	uint32_t ETH_MAC_RX_EN :1;
	uint32_t ETH_MAC_PTP_EN :1;
	uint32_t OTG_HS_CLK_EN :1;
	uint32_t OTG_HSULPI_CLK_EN :1;
	uint32_t RESERVED_6 :1;
} RCC_AHB1ENR_t;

typedef struct GPIOx_MODER_t {
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIO_MODER_t, GPIO_PUPDR_t;

typedef struct {
	uint32_t pin_0 :1;
	uint32_t pin_1 :1;
	uint32_t pin_2 :1;
	uint32_t pin_3 :1;
	uint32_t pin_4 :1;
	uint32_t pin_5 :1;
	uint32_t pin_6 :1;
	uint32_t pin_7 :1;
	uint32_t pin_8 :1;
	uint32_t pin_9 :1;
	uint32_t pin_10 :1;
	uint32_t pin_11 :1;
	uint32_t pin_12 :1;
	uint32_t pin_13 :1;
	uint32_t pin_14 :1;
	uint32_t pin_15 :1;
	uint32_t reserved :16;
} GPIOx_ODR_t, GPIOx_IDR_t;


#endif /* MAIN_H_ */
