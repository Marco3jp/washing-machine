#include <stdio.h>
#include "process.h"
#include "../main.h"

int is_processing() {
    if (current_process == -1) {
        return 0;
    } else {
        return 1;
    }
}

void set_process_type(enum process_type type) {
    process = type;
}

void increment_process_type() {
    if (process == _SPIN) {
        // move top
        process = WASH_RINSE_SPIN;
    } else {
        process++;
    }
}

const char* get_process_type_name() {
    switch (process) {
        case WASH_RINSE_SPIN:
            return "W-R-S";
        case RINSE_SPIN:
            return "R-S  ";
        case _RINSE:
            return "R    ";
        case _SPIN:
            return "S    ";
    }
}