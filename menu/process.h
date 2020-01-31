#include <stdio.h>

#ifndef PROCESS_H
#define PROCESS_H

enum process_name {
    WASH,
    RINSE,
    SPIN
};

enum process_type {
    WASH_RINSE_SPIN,
    RINSE_SPIN,
    _RINSE,
    _SPIN
};

int is_processing();
void set_process_type(enum process_type);
void increment_process_type();
const char* get_process_type_name();

#endif