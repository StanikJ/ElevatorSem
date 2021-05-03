/*
 * Dvere.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file Dvere.c
* @brief Funkcie na otváranie a zatváranie dverí výťahu
* @details Pomocou nasledujúcich funkcií otvárame a zatvárame dvere výťahu
*
*/

#include "Headers/Definitions.h"
#include "Headers/Dvere.h"

void dvereOtvor(){
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0xf0,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};

	uint8_t dvereOtvorMSG[] = {
			dvereOtvorMSG[0] = dataMSG,
			dvereOtvorMSG[1] = 0xf0,
			dvereOtvorMSG[2] = doskaADDR,
			dvereOtvorMSG[3] = 0x01,
			dvereOtvorMSG[4] = 0x00,
			dvereOtvorMSG[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
	LPSCI_WriteBlocking(DEMO_LPSCI, dvereOtvorMSG, sizeof(dvereOtvorMSG));
}

void dvereZatvor(){
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0xf0,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};

	uint8_t dvereZatvorMSG[] = {
			dvereZatvorMSG[0] = dataMSG,
			dvereZatvorMSG[1] = 0xf0,
			dvereZatvorMSG[2] = doskaADDR,
			dvereZatvorMSG[3] = 0x01,
			dvereZatvorMSG[4] = 0x01,
			dvereZatvorMSG[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
		LPSCI_WriteBlocking(DEMO_LPSCI, dvereZatvorMSG, sizeof(dvereZatvorMSG));
}
