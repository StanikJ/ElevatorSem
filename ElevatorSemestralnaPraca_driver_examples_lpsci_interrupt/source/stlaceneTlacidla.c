/*
 * stlaceneTlacidla.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file stlaceneTlacidla.c
* @brief Funkcia na čítanie stlačených tlačidiel
* @details Funkcia číta stlačené tlačidlá, a nastavuje globálne premenné
*
*/

#include "Variables.h"
#include "stlaceneTlacidla.h"
#include "Led.h"

/*!
 * Funkcia, ktorá má za úlohu, po stlačení ľubovolného tlačidla zasvietiť prislúšné ledky a nastaviť
 * hodnotu prislúšného poschodia na true
 *
 */
void stlaceneTlacidla(uint8_t stlaceneTlacidlo){
		if(stlaceneTlacidlo == 0xc0 || stlaceneTlacidlo == 0xb0){
			poschodie0 = true;
			led0OUT();
			led0IN();
		}
		if(stlaceneTlacidlo == 0xc1 || stlaceneTlacidlo == 0xb1){
			poschodie1 = true;
			led1OUT();
			led1IN();
		}
		if(stlaceneTlacidlo == 0xc2 || stlaceneTlacidlo == 0xb2){
			poschodie2 = true;
			led2OUT();
			led2IN();
		}
		if(stlaceneTlacidlo == 0xc3 || stlaceneTlacidlo == 0xb3){
			poschodie3 = true;
			led3OUT();
			led3IN();
		}
		if(stlaceneTlacidlo == 0xc4 || stlaceneTlacidlo == 0xb4){
			poschodie4 = true;
			led4OUT();
			led4IN();
		}
}
