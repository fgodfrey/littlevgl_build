#include <unistd.h>
#include <lvgl/lvgl.h>
#include <lvgl/lv_misc/lv_font.h>
#include <lvgl/lv_themes/lv_theme_night.h>
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

	/* Set screen base style */
	base_theme = lv_theme_night_init(255, &lv_font_dejavu_20);	/* Hu, font */
	lv_theme_set_current(base_theme);
}

static void
create_status_bar(void) {
	base_status_bar = lv_obj_create(lv_scr_act(), NULL);

	lv_obj_set_size(base_status_bar, 320, 20);
	lv_style_copy(&base_status_style_txt, &lv_style_plain);
	base_status_style_txt.text.font = &lv_font_symbol_20;
	base_status_style_txt.text.letter_space = 2;
	base_status_style_txt.text.line_space = 1;
	base_status_style_txt.text.color = LV_COLOR_GREEN;
	base_status_style_txt.body.main_color = LV_COLOR_HEX(0x808080);
	lv_obj_set_style(base_status_bar, &base_status_style_txt);
	lv_obj_align(base_status_bar, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

	base_status_battery = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_battery, SYMBOL_BATTERY_FULL);
	lv_obj_align(base_status_battery, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 0);

	base_status_charge = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_charge, SYMBOL_CHARGE);
	lv_style_copy(&base_status_style_charge, &base_status_style_txt);
	base_status_style_charge.text.color = LV_COLOR_HEX(0x0000ff);
	lv_obj_set_style(base_status_charge, &base_status_style_charge);
	lv_obj_align(base_status_charge, NULL, LV_ALIGN_IN_TOP_RIGHT, -35, 0);

	base_status_wifi = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_wifi, SYMBOL_WIFI);
	lv_obj_align(base_status_wifi, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 0);

	base_status_gps = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_gps, SYMBOL_GPS);
	lv_obj_align(base_status_gps, NULL, LV_ALIGN_IN_TOP_RIGHT, -80, 0);

	base_status_carrier = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_carrier, "Carrier");
	lv_style_copy(&base_status_style_carrier, &base_status_style_txt);
	base_status_style_carrier.text.font = &lv_font_dejavu_20;
	base_status_style_carrier.text.color = LV_COLOR_BLACK;
	lv_label_set_style(base_status_carrier, &base_status_style_carrier);
	lv_obj_align(base_status_carrier, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 0);

	base_status_cell_strength = lv_label_create(base_status_bar, NULL);
	lv_label_set_text(base_status_cell_strength, SYMBOL_CALL);
	lv_obj_align(base_status_cell_strength, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 0);
}

static void
create_tabs(void) {
	/* Create tabs */
	base_tabs = lv_tabview_create(lv_scr_act(), NULL);
	lv_obj_align(base_tabs, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 20);
	base_tab_main = lv_tabview_add_tab(base_tabs, "Status");
	base_tab_network = lv_tabview_add_tab(base_tabs, "Network");
}

int
main(int argc, char *argv[]) {
	/* LittlevGL init */
	lv_init();

	init_drivers();
	create_status_bar();
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
