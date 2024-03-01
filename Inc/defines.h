/*
 * defines.h
 *
 *  Created on: Mar 1, 2024
 *      Author: Pyry
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define GPIOA_CLK_REG ((uint32_t*)0x40023830)
#define GPIOA_MODE_REG ((uint32_t*)0x40020000)
#define GPIOA_OUT_DATA_REG ((uint32_t*)0x40020014)

#define NUMS_AMOUNT 10

#define ZERO ((uint8_t)0xFC) //0b11111100
#define ONE ((uint8_t)0x60) //0b01100000
#define TWO ((uint8_t)0xDA) //0b11011010
#define THREE ((uint8_t)0xF2) //0b11110010
#define FOUR ((uint8_t)0x66) //0b01100110
#define FIVE ((uint8_t)0xB6) //0b10110110
#define SIX ((uint8_t)0xBE) //0b10111110
#define	SEVEN ((uint8_t)0xE0) //0b11100000
#define EIGHT ((uint8_t)0xFE) //0b11111110
#define NINE ((uint8_t)0xF6) //0b11110110

#endif /* DEFINES_H_ */
