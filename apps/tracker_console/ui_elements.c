#include "lvgl/lvgl.h"
#include "tracker_ui_elements.h"

/*
 * Objects here are used globally by the other parts of this program.
 * This allows asynchronous updates of UI elements
 */

/*
 * Drivers
 */
lv_disp_drv_t base_disp_drv;	/* Display driver */
lv_indev_drv_t base_indev_touch;
lv_indev_drv_t base_indev_keys;

/*
 * Objects on all screens
 */
lv_obj_t *base_tabs;
lv_obj_t *base_tab_main;
lv_obj_t *base_tab_network;
lv_obj_t *base_wifi;
lv_obj_t *base_cell_carrier;
lv_obj_t *base_cell_strength;

/*
 * Objects in the main "summary" tab.
 */
lv_obj_t *main_gfx;
lv_obj_t *main_gps_lat_label;
lv_obj_t *main_gps_lat_value;
lv_obj_t *main_gps_lon_label;
lv_obj_t *main_gps_lon_value;
