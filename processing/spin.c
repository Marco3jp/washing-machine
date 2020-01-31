#include "spin.h"
#include "../hardware/lcd_disp.h"

void spin(){
    locate(0, 0);
    write_str("spin    ");
}