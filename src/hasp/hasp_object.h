/* MIT License - Copyright (c) 2019-2021 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

#ifndef HASP_OBJECT_H
#define HASP_OBJECT_H

#include "hasplib.h"

const char FP_PAGE[] PROGMEM     = "page";
const char FP_ID[] PROGMEM       = "id";
const char FP_OBJ[] PROGMEM      = "obj";
const char FP_OBJID[] PROGMEM    = "objid";
const char FP_PARENTID[] PROGMEM = "parentid";
const char FP_GROUPID[] PROGMEM  = "groupid";

typedef struct
{
    uint8_t pageid;
    uint8_t objid;
    uint16_t interval;
} hasp_task_user_data_t;

enum lv_hasp_obj_type_t {
    /* Containers */
    LV_HASP_SCREEN    = 1,
    LV_HASP_CONTAINER = 2,
    LV_HASP_WINDOW    = 3, // placeholder
    LV_HASP_MSGBOX    = 4, // placeholder
    LV_HASP_TILEVIEW  = 5, // placeholder
    LV_HASP_TABVIEW   = 6, // placeholder
    LV_HASP_TAB       = 7, // placeholder
    LV_HASP_PAGE      = 8, // Obsolete in v8

    /* Controls */
    LV_HASP_OBJECT    = 11,
    LV_HASP_BUTTON    = 12,
    LV_HASP_BTNMATRIX = 13,
    LV_HASP_IMGBTN    = 14, // placeholder
    LV_HASP_CHECKBOX  = 15,
    LV_HASP_SWITCH    = 16,
    LV_HASP_SLIDER    = 17,
    LV_HASP_TEXTAREA  = 18, // placeholder
    LV_HASP_SPINBOX   = 19, // placeholder
    LV_HASP_CPICKER   = 20,

    /* Visualizers */
    LV_HASP_LABEL   = 21,
    LV_HASP_GAUGE   = 22,
    LV_HASP_BAR     = 23,
    LV_HASP_LMETER  = 24,
    LV_HASP_LED     = 25,
    LV_HASP_ARC     = 26,
    LV_HASP_SPINNER = 27,
    LV_HASP_CHART   = 28,

    /* Selectors */
    LV_HASP_DROPDOWN = 29,
    LV_HASP_ROLLER   = 30,
    LV_HASP_LIST     = 31, // placeholder
    LV_HASP_TABLE    = 32,
    LV_HASP_CALENDER = 33,

    /* Graphics */
    LV_HASP_LINE   = 36,
    LV_HASP_IMAGE  = 37, // placeholder
    LV_HASP_CANVAS = 38, // placeholder
    LV_HASP_MASK   = 39, // placeholder
};

void hasp_new_object(const JsonObject& config, uint8_t& saved_page_id);

lv_obj_t* hasp_find_obj_from_parent_id(lv_obj_t* parent, uint8_t objid);
lv_obj_t* hasp_find_obj_from_page_id(uint8_t pageid, uint8_t objid);
bool hasp_find_id_from_obj(lv_obj_t* obj, uint8_t* pageid, uint8_t* objid);
const char* obj_get_type_name(lv_obj_t* obj);
bool obj_check_type(lv_obj_t* obj, lv_hasp_obj_type_t haspobjtype);
lv_hasp_obj_type_t obj_get_type(lv_obj_t* obj);
void hasp_object_tree(lv_obj_t* parent, uint8_t pageid, uint16_t level);

void object_dispatch_state(uint8_t pageid, uint8_t btnid, const char* payload);

void hasp_process_attribute(uint8_t pageid, uint8_t objid, const char* attr, const char* payload, bool update);

void object_set_normalized_group_values(uint8_t groupid, lv_obj_t* src_obj, int16_t val, int16_t min, int16_t max);

#define HASP_OBJ_BAR 1971
#define HASP_OBJ_BTN 3164
#define HASP_OBJ_CPICKER 3313
#define HASP_OBJ_CHECKBOX 1923
#define HASP_OBJ_SPINNER 7097
#define HASP_OBJ_MSGBOX 7498
#define HASP_OBJ_TABLE 12078
#define HASP_OBJ_ROLLER 13258
#define HASP_OBJ_LABEL 13684
#define HASP_OBJ_KEYBOARD 14343
#define HASP_OBJ_PAGE 19759
#define HASP_OBJ_WIN 20284
#define HASP_OBJ_TEXTAREA 24186
#define HASP_OBJ_IMGBTN 24441
#define HASP_OBJ_SPINBOX 25641
#define HASP_OBJ_CALENDAR 30334
#define HASP_OBJ_IMG 30499
#define HASP_OBJ_GAUGE 33145
#define HASP_OBJ_CHART 34654
#define HASP_OBJ_LINE 34804
#define HASP_OBJ_LIST 35134
#define HASP_OBJ_SLIDER 35265
#define HASP_OBJ_CANVAS 35480
#define HASP_OBJ_TILEVIEW 36019
#define HASP_OBJ_CONT 36434
#define HASP_OBJ_SWITCH 38484
#define HASP_OBJ_LED 41899
#define HASP_OBJ_DROPDOWN 49169
#define HASP_OBJ_BTNMATRIX 49629
#define HASP_OBJ_OBJ 53623
#define HASP_OBJ_OBJMASK 55395
#define HASP_OBJ_LMETER 62749
#define HASP_OBJ_TABVIEW 63226
#define HASP_OBJ_TAB 7861
#define HASP_OBJ_ARC 64594

#endif