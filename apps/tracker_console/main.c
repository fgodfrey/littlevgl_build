#include <unistd.h>
#include <lvgl/lvgl.h>
#include <lv_drivers/display/fbdev.h>
#include <lv_drivers/indev/evdev.h>


#include "tracker_ui_elements.h"

extern void lv_init(void);

static void
init_drivers(void) {
	/* Linux frame buffer device init */
	fbdev_init();

	/* Add a display the LittlevGL using the frame buffer driver */
	lv_disp_drv_init(&base_disp_drv);
	base_disp_drv.disp_flush = fbdev_flush;      /* flush the internal graphical buffer to the frame buffer */
	lv_disp_drv_register(&base_disp_drv);

	/* Initialize input drivers */
	evdev_init();
	base_indev_touch.type = LV_INDEV_TYPE_POINTER;
	base_indev_touch.read = evdev_read;
	lv_indev_drv_register(&base_indev_touch);     /* Register the driver in LittlevGL */

}

static void
create_tabs(void) {
	/* Create tabs */
	base_tabs = lv_tabview_create(lv_scr_act(), NULL);
	base_tab_main = lv_tabview_add_tab(base_tabs, "Status");
	base_tab_network = lv_tabview_add_tab(base_tabs, "Network");
}

int
main(int argc, char *argv[]) {
	/* LittlevGL init */
	lv_init();

	init_drivers();
	create_tabs();

	/* Create a "Hello world!" label */
	lv_obj_t * label = lv_label_create(base_tab_main, NULL);
	lv_label_set_text(label, "Hello world!");
	lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

	/* Handle LitlevGL tasks (tickless mode) */
	while(1) {
		lv_tick_inc(5);
		lv_task_handler();
		usleep(5000);
	}

	return 0;
}
