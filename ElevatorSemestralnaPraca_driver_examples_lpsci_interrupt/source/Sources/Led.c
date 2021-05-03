/*
 * Led.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file Led.c
* @brief Základné funkcie pre led
* @details Pomocou nasledujúcich funkcií riešime zapínanie a vypínanie lediek.
*
*/

#include "Headers/Definitions.h"
#include "Headers/Led.h"

void led0OUT() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x10,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x10,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x01,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led0IN() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x20,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x20,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x01,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led1OUT() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x11,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x11,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x01,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led1IN() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x21,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x21,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x01,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led2OUT() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x12,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x12,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x01,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led2IN() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x22,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x22,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x01,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led3OUT() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x13,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x13,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x01,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led3IN() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x23,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x23,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x01,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led4OUT() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x14,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x14,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x01,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led4IN() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x24,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x01
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x24,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x01,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}


void led0OUTZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x10,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x10,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x00,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led0INZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x20,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x20,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x00,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led1OUTZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x11,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x11,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x00,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led1INZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x21,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x21,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x00,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led2OUTZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x12,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x12,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x00,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led2INZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x22,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x22,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x00,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led3OUTZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x13,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x13,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x00,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led3INZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x23,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x23,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x00,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

void led4OUTZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x14,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0O[] = {
			LED0O[0] = dataMSG,
			LED0O[1] = 0x14,
			LED0O[2] = doskaADDR,
			LED0O[3] = 0x01,
			LED0O[4] = 0x00,
			LED0O[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
			LPSCI_WriteBlocking(DEMO_LPSCI, LED0O, sizeof(LED0O));
}

void led4INZhasni() {
	uint8_t dataPreCRC[] = {
			dataPreCRC[0] = 0x24,
			dataPreCRC[1] = 0x00,
			dataPreCRC[2] = 0x00
	};
	uint8_t LED0I[] = {
			LED0I[0] = dataMSG,
			LED0I[1] = 0x24,
			LED0I[2] = doskaADDR,
			LED0I[3] = 0x01,
			LED0I[4] = 0x00,
			LED0I[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
		};
				LPSCI_WriteBlocking(DEMO_LPSCI, LED0I, sizeof(LED0I));
}

/*!
 * funkcia, pomocou ktorej zhasneme všetky led
 */

void zhasniLed(){
	led0INZhasni();
	led0OUTZhasni();
	led1INZhasni();
	led1OUTZhasni();
	led2INZhasni();
	led2OUTZhasni();
	led3INZhasni();
	led3OUTZhasni();
	led4INZhasni();
	led4OUTZhasni();
}
