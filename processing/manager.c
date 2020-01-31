#include "../main.h"
#include "../hardware/lcd_disp.h"
#include "manager.h"
#include "wash.h"
#include "spin.h"
#include "rinse.h"

void start_processing() {
    current_process = 0;
}

// continue processing for other layer functions.

int continue_processing() {
    if (is_complete_current_processing()) {
        if (is_continuable()) {
            disp_number(current_process, 0, 2);
            current_process++;
        } else {
            locate(0, 0);
            write_str("Finish    ");
        }
    } else {
        char timer[2];
        sprintf(timer, "%2d", process_timer[current_process]);
        locate(0, 1);
        write_str(timer);
        run_processing();
    }
}

// is there next process? for continueProcessing();

int is_continuable() {
    if (current_process == 4) {
        return 0;
    } else {
        int i;
        for (i = current_process; i < 5; i++) {
            if (process_timer[i] != 0) {
                current_process = i;
                return 1;
            }
        }

        return 0;
    }
}

// do washing machine complete current processing? for continueProcessing();

int is_complete_current_processing() {
    return process_timer[current_process] == 0;
}

// operate hardware. wash, rinse, spin. for continueProcessing();

void run_processing() {
    switch (current_process) {
        case 0:
            wash();
            break;
        case 1:
            rinse();
            break;
        case 2:
            rinse();
            break;
        case 3:
            rinse();
            break;
        case 4:
            spin();
    }
}