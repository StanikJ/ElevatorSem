/*
 * Variables.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

#include "Headers/Variables.h"

volatile uint8_t message[BUFFER_SIZE];
volatile uint8_t rxIndex = 0;
volatile bool messageComplete = false;
volatile uint8_t pozadovanePoschodie = 0;
volatile uint8_t aktualnePoschodie = 0;
volatile bool ideHore = false;
volatile bool ideDole = false;
volatile bool stoji = false;
volatile bool poschodie0 = false;
volatile bool poschodie1 = false;
volatile bool poschodie2 = false;
volatile bool poschodie3 = false;
volatile bool poschodie4 = false;
volatile uint32_t t = 0;
