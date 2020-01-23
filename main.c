/*
 * File:   main.c
 * Author: marco
 *
 * Created on December 20, 2019, 12:07 PM
 */


#include <pic.h>
#include "init.h"
#include "hardware/lcd_disp.h"
#include "hardware/practice_box.h"
#include "menu/course.h"
#include "menu/process.h"

enum course_name course = course_name.NORMAL;
enum process_type process = process_type.WASH_RINS_SPIN;
unsigned int process_timer = {0, 0, 0, 0, 0}; // wash, rins, rins, rins, spin
int current_process = -1; // -1 means isProcessing === false, other value means process_timer index.

void main(void) {
    init_pic(); /* PIC kit board initilize */
    init_lcd(); /* LCD unit initilize */
    init_practice_Box(); /* Practice BOX initilize */

    write_str("Hello World!");

    char sw_stat;

    while (1) {
        sw_stat = PORTB;

        if ((sw_stat & 0b01000000) == 0 && !is_processing()) { // sw6
            increment_process_type();
        }

        if ((sw_stat & 0b10000000) == 0 && !is_processing()) { // sw7
            increment_course();
        }
    }
}
