#include "Headers/Crc8.h"
#include "Headers/Komunikacia.h"
#include "Headers/Definitions.h"
#include "Headers/Variables.h"
#include "Headers/Delay.h"
#include "Headers/Dvere.h"
#include "Headers/Led.h"
#include "Headers/Motor.h"
#include "Headers/Display.h"
#include "Headers/poschodieSet.h"
#include "Headers/stlaceneTlacidla.h"
#include "Headers/Variables.h"

/*!
 * Funkcia, ktorá pomocou interruptov napĺňa komunikačný buffer. Akonáhle rxIndex dosiahne hodnotu 4, tak sa
 * nastaví premenná messageComplete na hodnotu 1, čo znamená, že správa je kompletná. Táto správa sa následne ďalej
 * spracováva v main funkcii.
 */


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

    dvereZatvor();
    delay(30);
    motorDole();
    poschodie0 = true;
    ideDole = true;
    pozadovanePoschodie = 0xe0;
       while (1)
       {
       	    	if(messageComplete == true) {
       	    		acknowledgmentSprava(message[2]);
       	    		delay(3);

       	    		stlaceneTlacidla(message[2]);
       	    		zastavNaPoschodi();
       	    		nastavDest();
       	    		displaySmerSet(message[2]);

       	    		rxIndex=0;
       	    		messageComplete = false;
       	    	}
       }

}
