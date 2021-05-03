/*
 * Motor.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file Motor.c
* @brief Funkcie na ovládanie pohybu výťahu
* @details Pomocou nasledujúcich funkcií ovládame pohyb výťahu, pohyb hore, dole a zastav motor.
*
*/

#include "Headers/Definitions.h"
#include "Headers/Motor.h"

void motorHore() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0xf1,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x02,
			dataPreCRC[3] = 0x64,
			dataPreCRC[4] = 0x00,
			dataPreCRC[5] = 0x00,
			dataPreCRC[6] = 0x00
	};

	uint8_t motorHoreMSG[] = {
			motorHoreMSG[0] = dataMSG,
			motorHoreMSG[1] = 0xf1,
			motorHoreMSG[2] = doskaADDR,
			motorHoreMSG[3] = 0x05,
			motorHoreMSG[4] = 0x02,
			motorHoreMSG[5] = 0x64,
			motorHoreMSG[6] = 0x00,
			motorHoreMSG[7] = 0x00,
			motorHoreMSG[8] = 0x00,
			motorHoreMSG[9] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
	LPSCI_WriteBlocking(DEMO_LPSCI, motorHoreMSG, sizeof(motorHoreMSG));
}


void motorDole() {
	uint8_t dataPreCRC[] = {
				dataPreCRC[0] = 0xf1,
				dataPreCRC[1] = 0x00,
				dataPreCRC[2] = 0x02,
				dataPreCRC[3] = 0x9C,
				dataPreCRC[4] = 0xFF,
				dataPreCRC[5] = 0xFF,
				dataPreCRC[6] = 0xFF
		};

		uint8_t motorDoleMSG[] = {
				motorDoleMSG[0] = dataMSG,
				motorDoleMSG[1] = 0xf1,
				motorDoleMSG[2] = doskaADDR,
				motorDoleMSG[3] = 0x05,
				motorDoleMSG[4] = 0x02,
				motorDoleMSG[5] = 0x9C,
				motorDoleMSG[6] = 0xFF,
				motorDoleMSG[7] = 0xFF,
				motorDoleMSG[8] = 0xFF,
				motorDoleMSG[9] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
		LPSCI_WriteBlocking(DEMO_LPSCI, motorDoleMSG, sizeof(motorDoleMSG));
}


void motorStop() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0xf1,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t motorStopMSG[] = {
			motorStopMSG[0] = dataMSG,
			motorStopMSG[1] = 0xf1,
			motorStopMSG[2] = doskaADDR,
			motorStopMSG[3] = 0x01,
			motorStopMSG[4] = 0x01,
			motorStopMSG[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
	LPSCI_WriteBlocking(DEMO_LPSCI, motorStopMSG, sizeof(motorStopMSG));
}
