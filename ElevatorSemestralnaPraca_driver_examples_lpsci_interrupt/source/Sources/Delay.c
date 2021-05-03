/*
 * Delay.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

#include "Headers/Variables.h"
#include "Headers/Delay.h"

void delay(uint32_t t){
	volatile uint32_t i = 0;
	for(i=0; i<150000 * t; i++){
		__asm("NOP");
	}
}

