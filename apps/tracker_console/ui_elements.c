#include "lvgl/lvgl.h"
#include "tracker_ui_elements.h"

/*
 * Objects here are used globally by the other parts of this program.
 * This allows asynchronous updates of UI elements
 */

/*
 * Drivers/Themes/etc...
 */
lv_disp_drv_t base_disp_drv;	/* Display driver */
lv_indev_drv_t base_indev_touch;
lv_indev_drv_t base_indev_keys;
lv_theme_t *base_theme;
lv_style_t base_status_style_txt;
lv_style_t base_status_style_carrier;
lv_style_t base_status_style_charge;

/*
 * Objects on all screens
 */
lv_obj_t *base_tabs;
lv_obj_t *base_tab_main;
lv_obj_t *base_tab_network;
lv_obj_t *base_status_bar;
lv_obj_t *base_status_charge;
lv_obj_t *base_status_battery;
lv_obj_t *base_status_wifi;
lv_obj_t *base_status_gps;
lv_obj_t *base_status_carrier;
lv_obj_t *base_status_cell_strength;


/*
 * Objects in the main "summary" tab.
 */
lv_obj_t *main_gfx;
lv_obj_t *main_gps_lat_label;
lv_obj_t *main_gps_lat_value;
lv_obj_t *main_gps_lon_label;
lv_obj_t *main_gps_lon_value;
