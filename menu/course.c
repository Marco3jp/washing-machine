#include "course.h"

void set_course(enum course_name name) {
    course = name;
}

void increment_course() {
    if (course == course_name.HEAVY) {
        course = course_name.NORMAL;
    } else {
        course++;
    }
}