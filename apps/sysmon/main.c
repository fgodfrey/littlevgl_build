#include <unistd.h>
#include <lvgl/lvgl.h>
#include <lv_drivers/display/fbdev.h>
#include <lv_drivers/indev/evdev.h>
#include "sysmon.h"

int main(void)
{
    lv_disp_drv_t disp_drv;
    lv_indev_drv_t indev_drv;

    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*Add a display the LittlevGL sing the frame buffer driver*/
    lv_disp_drv_init(&disp_drv);
    disp_drv.disp_flush = fbdev_flush;      /*It flushes the internal graphical buffer to the frame buffer*/
    lv_disp_drv_register(&disp_drv);

    evdev_init();
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = evdev_read;
    lv_indev_drv_register(&indev_drv);     /*Register the driver in LittlevGL*/

    sysmon_create();

    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_tick_inc(5);
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}
