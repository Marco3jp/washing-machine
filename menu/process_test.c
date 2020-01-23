/*
 * File:   manager_test.c
 * Author: marco
 *
 * Created on January 10, 2020, 11:38 AM
 */


#include <pic.h>
#include "../init.h"
#include "../hardware/lcd_disp.h"
#include "course.h"
#include "process.h"

enum process_type process = process_type.WASH_RINS_SPIN;
unsigned int process_timer = {0, 0, 0, 0, 0}; // wash, rins, rins, rins, spin
int current_process = -1; // -1 means isProcessing === false, other value means process_timer index.

void main(void) {
    init_pic(); /* PIC kit board initialize */
    init_lcd(); /* LCD unit initialize */
    init_practice_Box(); /* Practice BOX initialize */

    char sw_stat;
    char hasNewProcess = 0;

    while (1) {
        sw_stat = PORTB;

        if ((sw_stat & 0b01000000) == 0 && !is_processing()) { // sw6
            increment_process_type();
            hasNewProcess = 1;
        }

        if (hasNewProcess == 1) {
            write_str("process_id: " + process);
            hasNewProcess = 0;
        }
    }
}
