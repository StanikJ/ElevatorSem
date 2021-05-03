/*
 * Komunikacia.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

#include "Headers/Definitions.h"
#include "Headers/Komunikacia.h"
#include "Headers/Crc8.h"

void acknowledgmentSprava (uint8_t Adresa_Prijatej_Spravy){
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = Adresa_Prijatej_Spravy,
			dataPreCRC[1] = doskaADDR
	};

	uint8_t ackMessage[] = {
			ackMessage[0] = acknowledgeMSG,
			ackMessage[1] = Adresa_Prijatej_Spravy,
			ackMessage[2] = doskaADDR,
			ackMessage[3] = 0x00,
			ackMessage[4] = crc8_calc(dataPreCRC, sizeof(dataPreCRC)) };
	LPSCI_WriteBlocking(DEMO_LPSCI, ackMessage, sizeof(ackMessage));
}
