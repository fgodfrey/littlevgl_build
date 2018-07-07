#ifndef _TRACKER_UI_ELEMENTS_H
#define _TRACKER_UI_ELEMENTS_H

/*
 * Objects on all screens
 */
extern lv_disp_drv_t base_disp_drv;
extern lv_indev_drv_t base_indev_touch;
extern lv_indev_drv_t base_indev_keys;

extern lv_obj_t *base_tabs;
extern lv_obj_t *base_tab_main;
extern lv_obj_t *base_tab_network;
extern lv_obj_t *base_wifi;
extern lv_obj_t *base_cell_carrier;
extern lv_obj_t *base_cell_strength;

/*
 * Objects in the main "summary" tab.
 */
extern lv_obj_t *main_gfx;
extern lv_obj_t *main_gps_lat_label;
extern lv_obj_t *main_gps_lat_value;
extern lv_obj_t *main_gps_lon_label;
extern lv_obj_t *main_gps_lon_value;

#endif /* _TRACKER_UI_ELEMENTS_H */
