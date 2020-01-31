#include <stdio.h>
#include "course.h"
#include "../main.h"

void set_course(enum course_name name) {
    course = name;
}

void increment_course() {
    if (course == HEAVY) {
        course = NORMAL;
    } else {
        course++;
    }
}

const char* get_course_name() {
    switch (course) {
        case NORMAL:
            return "Normal";
        case QUICK:
            return "Quick ";
        case HEAVY:
            return "Heavy ";
    }
}