/*enum my_keycodes {
  WHEEL_UP = SAFE_RANGE,
  WHEEL_DOWN
}; 

#include "pointing_device.h"
#include "report.h"
report_mouse_t currentReport = {};
report_mouse_t currentReport2 = {};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WHEEL_UP:
       report.buttons = 0;
          if (record->event.pressed) {
            report.buttons |= MOUSE_BTN1; //this is defined in report.h
          }
          else {
            report.buttons &= ~MOUSE_BTN1;
          }
          pointing_device_set_report(report);
          pointing_device_send();
        break;
    case WHEEL_DOWN:
        report_mouse_t currentReport2 = pointing_device_get_report();
        if (record->event.pressed) {
            currentReport2.v = -5;
        } else {
            break;
        }
        pointing_device_set_report(currentReport2);
        pointing_device_send();
        break;
  }
}
*/
#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

#endif