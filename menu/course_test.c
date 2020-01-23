/*
 * File:   course_test.c
 * Author: marco
 *
 * Created on January 23, 2020, 10:29 PM
 */

#include <pic.h>
#include "course.h"
#include "../hardware/lcd_disp.h"
#include "../hardware/practice_box.h"

enum course_name course = course_name.NORMAL;

void main(void) {
    init_pic(); /* PIC kit board initialize */
    init_lcd(); /* LCD unit initialize */
    init_practice_Box(); /* Practice BOX initialize */

    write_str("Hello World!");

    char sw_stat;
    char has_new_course = 0;
    
    while (1) {
        sw_stat = PORTB;
        
        if( (sw_stat& 0b10000000) == 0 && !is_processing() ) { // sw7
            increment_course();
            has_new_course = 1;
        }
        
        if (has_new_course == 1) {
            write_str("course_id: " + course);
            has_new_course = 0;
        }
    }
}
