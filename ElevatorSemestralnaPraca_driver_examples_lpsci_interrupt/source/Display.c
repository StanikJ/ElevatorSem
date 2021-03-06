/*
 * Display.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file Display.c
* @brief Zobrazovanie pohybu výťahu
* @details Nasldujúce funkcie vypisujú na display smer pohybu a aktuálne poschodie
*
*/

#include "Definitions.h"
#include "Variables.h"
#include "Display.h"
#include "Crc8.h"

/*!
 * Funkcia, ktorá vypisuje na display, aktuálne číslo poschodia a smer pohybu výťahu
 */

void Display(uint8_t smer, uint8_t poschodie) {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x30,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = smer,
			dataPreCRC[3] = poschodie
	};
	uint8_t displayMSG[] = {
			displayMSG[0] = dataMSG,
			displayMSG[1] = 0x30,
			displayMSG[2] = doskaADDR,
			displayMSG[3] = 0x02,
			displayMSG[4] = smer,
			displayMSG[5] = poschodie,
			displayMSG[6] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
	LPSCI_WriteBlocking(DEMO_LPSCI, displayMSG, sizeof(displayMSG));
}

/*!
 * Funkcia, ktorá zisťuje smer pohybu pomocou čítania hodnoty globálných premenných ako ideHore, ideDole.
 * Následne číta aktuálný switch, okolo ktorého práve výťah prešiel a podľa toho vypíše číslo poschodia.
 */

void displaySmerSet(uint8_t poschodie){
	if(ideHore == true){
		if(poschodie == 0xe0){
			Display(smerHore, 'P');
		}
		if(poschodie == 0xe1){
			Display(smerHore, '1');
		}
		if(poschodie == 0xe2){
			Display(smerHore, '2');
		}
		if(poschodie == 0xe3){
			Display(smerHore, '3');
		}
		if(poschodie == 0xe4){
			Display(smerHore, '4');
		}
	}
	if(ideDole == true){
		if(poschodie == 0xe0){
			Display(smerDole, 'P');
		}
		if(poschodie == 0xe1){
			Display(smerDole, '1');
		}
		if(poschodie == 0xe2){
			Display(smerDole, '2');
		}
		if(poschodie == 0xe3){
			Display(smerDole, '3');
		}
		if(poschodie == 0xe4){
			Display(smerDole, '4');
		}
	}
	if(ideHore == false && ideDole == false){
		if(poschodie == 0xe0){
			Display(smerVypnuty, 'P');
		}
		if(poschodie == 0xe1){
			Display(smerVypnuty, '1');
		}
		if(poschodie == 0xe2){
			Display(smerVypnuty, '2');
		}
		if(poschodie == 0xe3){
			Display(smerVypnuty, '3');
		}
		if(poschodie == 0xe4){
			Display(smerVypnuty, '4');
		}
	}
}
