/*7 segment display using STM32F407 Discovery and SN74HC595N shift register
 * PA0 as data pin, PA1 as storage "clock" and PA3 as output "clock"
 *
 * By default, the digits do not use the decimal point on the display
 * modify dec to use the point
 */
#include <stdint.h>
#include "defines.h"

void board_init();

void write_data(uint8_t data);
uint8_t dec = 1; //If 0, no decimal point on display


int main(void){
	uint8_t nums[NUMS_AMOUNT] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	board_init();
	while(1){
		for(uint8_t i = 0; i < NUMS_AMOUNT; i++){
			write_data(nums[i]);
			for(int i = 0; i < 0xFFFFF; i++); //Delay, should implement a real delay based on hw clock
		}
	};
}
void board_init(){
	//GPIOA clock and PA0,1 and 3 as outputs
	*GPIOA_CLK_REG |= (1 << 0);
	*GPIOA_MODE_REG |= (1 << 0) | (1 << 2) | (1 << 6);
}

void write_data(uint8_t data){
	uint8_t shifted = 0;
	if(dec == 1){
		data++;
	}
	for(uint8_t i = 0; i < 8; i++){
		shifted = (data & 0x01); //Extract the LSB from the given value
		*GPIOA_OUT_DATA_REG = (shifted << 0); //Write the bit to the data pin
		*GPIOA_OUT_DATA_REG |= (1 << 1); //Pulse the storage clock
		*GPIOA_OUT_DATA_REG &= ~(1 << 1);
		data = data >> 1; //Shift the data to the right to extract the next bit
	}
	*GPIOA_OUT_DATA_REG |= (1 << 3); //Pulse the output clock to send the byte to the segment display
	*GPIOA_OUT_DATA_REG &= ~(1 << 3);
}

