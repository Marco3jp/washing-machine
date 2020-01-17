#include <manager.h>

int is_processing(){
    if (current_process == -1){
        return 0;
    } else {
        return 1;
    }
}

void set_process_type(enum process_type type){
    process = type;
}

void increment_process_type(){
    if(process == process_type.SPIN){
        // move top
        process = process.WASH_RINS_SPIN;
    }else {
        process++;
    }
}