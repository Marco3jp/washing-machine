#include "wash.h"
#include "../hardware/lcd_disp.h"
#include "../hardware/practice_box.h"

void wash(){
    locate(0, 0);
    write_str("wash    ");
    move_Box_Motor(1, 1);
    move_Box_Motor(2, 1);
}