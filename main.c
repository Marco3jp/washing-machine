/*
 * File:   main.c
 * Author: marco
 *
 * Created on December 20, 2019, 12:07 PM
 */


#include <pic.h>
#include "hardware/lcd_disp.h"
#include "hardware/practice_box.h"

static void init_pic() {
    // OSCCON = 0x70; // INTOSC 8MHz
    PSTRCON = 0x00; // assigned to port pin

    /* Set Port B*/
    ANSELH = 0x00; // AN Disable (RB5-RB0)
    WPUB = 0x00; // Pull-up disable
    INTCON = 0x00; // Intrauppt disable
    IOCB = 0x00; // Intrauppt charge disable
    CCP1CON = 0x00;
    CM2CON1 = 0x02;
    OPTION_REG = 0xFF; // Pull-up disable

    TRISB = 0xFF; // IN
    // PORTB = 0x11; // High


    /* Set Port C */
    RCSTA = 0x00; // Serial disable (RC7-6)
    SSPCON = 0x00; // Serial disable (RC5-4)

    TRISC = 0x00; // OUT
    PORTC = 0x00; // Low

    /* Set Port D config */
    TRISD = 0xC0; // bit 0-5 OUT, bit6-7 IN
}

void main(void) {
    init_pic(); /* PIC kit board initilize */
    init_lcd(); /* LCD unit initilize */
    init_practice_Box(); /* Practice BOX initilize */

    write_str("Hello World!");

    while (1) {

    }
}
