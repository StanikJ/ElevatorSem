/*
 * Variables.h
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

#ifndef HEADERS_VARIABLES_H_
#define HEADERS_VARIABLES_H_

#include "Definitions.h"

extern volatile uint8_t message[BUFFER_SIZE];
extern volatile uint8_t rxIndex;
extern volatile bool messageComplete;
extern volatile uint8_t pozadovanePoschodie;
extern volatile uint8_t aktualnePoschodie;
extern volatile bool ideHore;
extern volatile bool ideDole;
extern volatile bool stoji;
extern volatile bool poschodie0;
extern volatile bool poschodie1;
extern volatile bool poschodie2;
extern volatile bool poschodie3;
extern volatile bool poschodie4;
extern volatile uint32_t t;


#endif /* HEADERS_VARIABLES_H_ */
