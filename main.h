/* 
 * File:   main.h
 * Author: marco
 *
 * Created on January 24, 2020, 12:00 PM
 */
#include "menu/process.h"
#include "menu/course.h"

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

extern enum course_name course = NORMAL;
extern enum process_type process = WASH_RINSE_SPIN;
extern unsigned int process_timer[] = {10, 10, 10, 10, 10}; // wash, rinse, rinse, rinse, spin
extern signed int current_process = -1; // -1 means is_processing === false, other value means process_timer index.
extern int sec = 0;
extern int light_num = 1;

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

