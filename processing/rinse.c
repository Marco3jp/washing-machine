#include "../main.h"
#include "rinse.h"
#include "../hardware/lcd_disp.h"
#include "../hardware/practice_box.h"

void rinse() {
    locate(0, 0);
    write_str("rinse   ");
    move_Box_Motor(1, 0);
    move_Box_Motor(2, 0);

    light_rinsing();
}

void light_rinsing() {
    // light_Box_LED(light_num, 0);
    if (light_num == 5) {
        light_num = 1;
    } else {
        light_num++;
    }
    light_Box_LED(light_num, 1);
}