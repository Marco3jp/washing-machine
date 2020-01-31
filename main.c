/*
 * File:   main.c
 * Author: marco
 *
 * Created on December 20, 2019, 12:07 PM
 */

#include <stdio.h>
#include <pic.h>
#include "init.h"
#include "hardware/lcd_disp.h"
#include "hardware/practice_box.h"
#include "hardware/sensor.h"
#include "menu/course.h"
#include "menu/process.h"
#include "processing/manager.h"
#include "processing/rinse.h"
#include "main.h"

/* CONFIG 1 */
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF

/* CONFIG 2 */
#pragma config WRT = OFF
#pragma config BOR4V = BOR40V

#define DEBUG 1

void light_LED(char data) {
    PORTD = (data >> 1) & 0x3F;
}

#define     SEC_MAX     16  /* 0.6107usx256x64=10ms */

static void interrupt rtcc_isr(void) /* for Standalone */ {
    T0IF = 0; /* Timer Interrupt Flag CLS */
    sec++;

    if (sec == SEC_MAX) {
        sec = 0;
        if (process_timer[current_process] > 0) {
            process_timer[current_process]--;
        }
    }
}

void main(void) {
    init_pic(); /* PIC kit board initialize */
    init_lcd(); /* LCD unit initialize */
    init_practice_Box(); /* Practice BOX initialize */

    timer0_init();

    char sw_stat;

    while (1) {
        sw_stat = PORTB;
        light_LED(~sw_stat);

        if ((sw_stat & 0b00000100) == 0 && is_processing() == 0) { // sw6
            increment_process_type();
            locate(0, 0);
            write_str(get_process_type_name());
        }

        if ((sw_stat & 0b00000010) == 0 && is_processing() == 0) { // sw7
            increment_course();
            locate(0, 0);
            write_str(get_course_name());
        }

        if ((sw_stat & 0b00010000) == 0 && is_processing() == 0) {
            start_processing();
        }

        if (is_processing()) {
            continue_processing();
        }
    }

}
