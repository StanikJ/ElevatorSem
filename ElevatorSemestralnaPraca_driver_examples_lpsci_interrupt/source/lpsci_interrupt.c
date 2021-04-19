/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "fsl_lpsci.h"

#include "clock_config.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_LPSCI UART0
#define DEMO_LPSCI_CLKSRC kCLOCK_CoreSysClk
#define DEMO_LPSCI_CLK_FREQ CLOCK_GetFreq(kCLOCK_CoreSysClk)
#define DEMO_LPSCI_IRQn UART0_IRQn
#define DEMO_LPSCI_IRQHandler UART0_IRQHandler
#define doskaADDR 0x00
#define acknowledgeMSG 0xa1
#define dataMSG 0xa0


/*! @brief Ring buffer size (Unit: Byte). */
#define BUFFER_SIZE 20

/*! @brief Ring buffer to save received data. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint8_t message[BUFFER_SIZE];
volatile uint8_t rxIndex = 0;
volatile bool messageComplete = false;
volatile bool destinacia = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

void DEMO_LPSCI_IRQHandler(void)
{
    uint8_t data;

    /* If new data arrived. */
    if ((kLPSCI_RxDataRegFullFlag)&LPSCI_GetStatusFlags(DEMO_LPSCI))
    {
        data = LPSCI_ReadByte(DEMO_LPSCI);

        /* If ring buffer is not full, add data to ring buffer. */
            message[rxIndex] = data;
            if(rxIndex == 4){
            	messageComplete = true;
            }
            else {
            	rxIndex++;
            }
    }
}

void delay(int millis) {
	int i = 0;
	while(i==millis * 10000) {
		i++;
	}
	__asm("nop");
}


unsigned char crc8_calc(unsigned char *data, const unsigned int elements){

static unsigned char crc8_table[] = { 0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32,
			163, 253, 31, 65, 157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227,
			189, 62, 96, 130, 220, 35, 125, 159, 193, 66, 28, 254, 160, 225,
			191, 93, 3, 128, 222, 60, 98, 190, 224, 2, 92, 223, 129, 99, 61,
			124, 34, 192, 158, 29, 67, 161, 255, 70, 24, 250, 164, 39, 121, 155,
			197, 132, 218, 56, 102, 229, 187, 89, 7, 219, 133, 103, 57, 186,
			228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154, 101, 59, 217, 135,
			4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36, 248, 166, 68,
			26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185, 140, 210,
			48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205, 17,
			79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14,
			80, 175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82,
			176, 238, 50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18,
			145, 207, 45, 115, 202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180,
			234, 105, 55, 213, 139, 87, 9, 235, 181, 54, 104, 138, 212, 149,
			203, 41, 119, 244, 170, 72, 22, 233, 183, 85, 11, 136, 214, 52, 106,
			43, 117, 151, 201, 74, 20, 246, 168, 116, 42, 200, 150, 21, 75, 169,
			247, 182, 232, 10, 84, 215, 137, 107, 53};

	unsigned char crc=0x00;
	for(int i = 0; i < elements; i++){
		crc = crc8_table[data[i] ^ crc];
	}
	return crc;
}


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
			dvereZatvorMSG[4] = 0x00,
			dvereZatvorMSG[5] = crc8_calc(dataPreCRC, sizeof(dataPreCRC))
	};
		LPSCI_WriteBlocking(DEMO_LPSCI, dvereZatvorMSG, sizeof(dvereZatvorMSG));
}

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

/*!
 * smerom na dol
 */
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

/*!
 * zastavenie motora
 */
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
 * @brief Main function
 */
int main(void)
{
    lpsci_config_t config;

    BOARD_InitPins();
    BOARD_BootClockRUN();
    CLOCK_SetLpsci0Clock(0x1U);

    LPSCI_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx = true;
    config.enableRx = true;

    LPSCI_Init(DEMO_LPSCI, &config, DEMO_LPSCI_CLK_FREQ);

    /* Enable RX interrupt. */
    LPSCI_EnableInterrupts(DEMO_LPSCI, kLPSCI_RxDataRegFullInterruptEnable);
    EnableIRQ(DEMO_LPSCI_IRQn);


       while (1)
       {
       	    	if(messageComplete == true) {
       	    		acknowledgmentSprava(message[2]);
       	    		delay(150);
       	    		if(message[2] == 0xc0){
       	    			led0IN();
       	    			delay(20);
       	    			led0OUT();
       	    		}
       	    		if(message[2] == 0xb0){
       	    			led0INZhasni();
       	    			delay(20);
       	         	    led0OUTZhasni();
       	    		}
       	    		if(message[2] == 0xc1){
       	    			led1IN();
       	    			delay(20);
       	    			led1OUT();
       	    		}
       	    		if(message[2] == 0xb1){
       	    			led1INZhasni();
       	    			delay(20);
       	    			led1OUTZhasni();
       	    		}
       	    		if(message[2] == 0xc2){
       	    			led2IN();
       	    			delay(20);
       	    			led2OUT();
       	    		}
       	    		if(message[2] == 0xb2){
       	    			led2INZhasni();
       	    			delay(20);
       	    			led2OUTZhasni();
       	    		}
       	    		if(message[2] == 0xc3){
       	    		    led3IN();
       	    		    delay(20);
       	    		    led3OUT();
       	    		}
       	    		if(message[2] == 0xb3){
       	    		    led3INZhasni();
       	    		    delay(20);
       	    		    led3OUTZhasni();
       	    		}
       	    		if(message[2] == 0xc4){
       	    		     led4IN();
       	    		     delay(20);
       	    		     led4OUT();
       	    		}
       	    		if(message[2] == 0xb4){
       	    		     led4INZhasni();
       	    		     delay(20);
       	    		     led4OUTZhasni();
       	    		}
       	    		rxIndex=0;
       	    		messageComplete = false;
       	    		destinacia = false;
       	    	}
       }
}
