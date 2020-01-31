#include <stdio.h>

#ifndef COURSE_H
#define COURSE_H

enum course_name {
    NORMAL,
    QUICK,
    HEAVY
};

void set_course(enum course_name);
void increment_course();
const char* get_course_name();

#endif