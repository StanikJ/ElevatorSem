/*
 * poschodieSet.c
 *
 *  Created on: 3. 5. 2021
 *      Author: Jojo
 */

/**
* @file poschodieSet.c
* @brief Funkcie na manipulovanie s poschodiami
* @details Nasledujúce funkcie riešia zastavovanie výťahu na konkrétnom poschodí a nastavovanie smeru výťahu
*
*/

#include "Variables.h"
#include "Motor.h"
#include "Dvere.h"
#include "Led.h"
#include "Delay.h"

/*!
* Funkcia, ktorá má za úlohu čítať aktualné switche výťahu. Popri čítaní nastavuje
* aktuálne poschodie na výpis na display a ak je prislúšné poschodie nastavene na true,
* tak na danom poschodí zastaví, otvorí dvere a vypne ledky.
*/

void zastavNaPoschodi(){
	if(message[2] == 0xe0){
		aktualnePoschodie = 0xe0;
		if(poschodie0==true){
			motorStop();
			delay(30);
			zhasniLed();
			dvereOtvor();
			poschodie0 = false;
			ideHore=false;
			ideDole=false;
		}
	}
	if(message[2] == 0xe1){
		aktualnePoschodie = 0xe1;
		if(poschodie1==true){
			motorStop();
			delay(30);
			zhasniLed();
			dvereOtvor();
			poschodie1 = false;
			ideHore=false;
			ideDole=false;
		}
	}
	if(message[2] == 0xe2){
		aktualnePoschodie = 0xe2;
		if(poschodie2==true){
			motorStop();
			delay(30);
			zhasniLed();
			dvereOtvor();
			poschodie2 = false;
			ideHore=false;
			ideDole=false;
		}
	}
	if(message[2] == 0xe3){
		aktualnePoschodie = 0xe3;
		if(poschodie3==true){
			motorStop();
			delay(30);
			zhasniLed();
			dvereOtvor();
			poschodie3 = false;
			ideHore=false;
			ideDole=false;
		}
	}
	if(message[2] == 0xe4){
		aktualnePoschodie = 0xe4;
		if(poschodie4==true){
			motorStop();
			delay(30);
			zhasniLed();
			dvereOtvor();
			poschodie4 = false;
			ideHore=false;
			ideDole=false;
		}
	}
}

/*!
*Funkcia, ktorá nastavuje požadované(cielové) poschodie podľa toho, či bolo stlačené tlačidlo a či bolo na hodnotu
* true nastavené jemu prislúchajúce poschodie. Následne rozpozná akým smerom sa má výťah vybrať.
*/

void nastavDest(){
	if(aktualnePoschodie == pozadovanePoschodie){
		if(poschodie4 == true){
			pozadovanePoschodie = 0xe4;
			if(pozadovanePoschodie> aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorHore();
				ideHore=true;
				ideDole=false;
			}
			if(pozadovanePoschodie < aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorDole();
				ideHore=false;
				ideDole=true;
			}
		}
		if(poschodie3 == true){
			pozadovanePoschodie = 0xe3;
			if(pozadovanePoschodie> aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorHore();
				ideHore=true;
				ideDole=false;
			}
			if(pozadovanePoschodie < aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorDole();
				ideHore=false;
				ideDole=true;
			}
		}
		if(poschodie2 == true){
			pozadovanePoschodie = 0xe2;
			if(pozadovanePoschodie> aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorHore();
				ideHore=true;
				ideDole=false;
			}
			if(pozadovanePoschodie < aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorDole();
				ideHore=false;
				ideDole=true;
			}
		}
		if(poschodie1 == true){
			pozadovanePoschodie = 0xe1;
			if(pozadovanePoschodie> aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorHore();
				ideHore=true;
				ideDole=false;
			}
			if(pozadovanePoschodie < aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorDole();
				ideHore=false;
				ideDole=true;
			}
		}
		if(poschodie0 == true){
			pozadovanePoschodie = 0xe0;
			if(pozadovanePoschodie> aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorHore();
				ideHore=true;
				ideDole=false;
			}
			if(pozadovanePoschodie < aktualnePoschodie){
				dvereZatvor();
				delay(30);
				motorDole();
				ideHore=false;
				ideDole=true;
			}
		}
	}
}
