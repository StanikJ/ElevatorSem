/*
 * Definitions.h
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

#ifndef HEADERS_DEFINITIONS_H_
#define HEADERS_DEFINITIONS_H_

#include "board.h"
#include "fsl_lpsci.h"
#include "pin_mux.h"
#include "clock_config.h"

#define DEMO_LPSCI UART0
#define DEMO_LPSCI_CLKSRC kCLOCK_CoreSysClk
#define DEMO_LPSCI_CLK_FREQ CLOCK_GetFreq(kCLOCK_CoreSysClk)
#define DEMO_LPSCI_IRQn UART0_IRQn
#define DEMO_LPSCI_IRQHandler UART0_IRQHandler
#define BUFFER_SIZE 20

#define doskaADDR 0x00
#define acknowledgeMSG 0xa1
#define dataMSG 0xa0

#define smerVypnuty 0x03
#define smerDole 0x02
#define smerHore 0x01

#endif /* HEADERS_DEFINITIONS_H_ */
