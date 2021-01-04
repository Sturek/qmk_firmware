/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, FN_MO13,  KC_SPC,     KC_ENT, FN_MO23, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT\
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT\
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 1
#define L_RAISE 2
#define L_ADJUST 3

void oled_render_layer_state(void) {
    oled_write_P("Layer: ", false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P("Default", false);
            break;
        case L_LOWER:
            oled_write_ln_P("Lower", false);
            break;
        case L_RAISE:
            oled_write_ln_P("Raise", false);
            break;
        case L_ADJUST:
            oled_write_ln_P("Adjust", false);
            break;
    }
}


char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}
void oled_render_keylogs(void) {
    oled_write(keylogs_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,128, 64, 64, 64, 64,128,  0,  0,  0,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192, 32, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224, 16, 16, 16, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,224, 16, 16, 16, 32,192,  0,  0,  0,127, 65, 79, 78, 66, 78,207, 65,255,
        0,  0,  0,  1,226, 60, 12,  6,218,147,217,  1, 48,200, 72, 48,  1,  3,252,  0,  0,  0,  0,240,  8,  4,250,142,  2,  1,  1,  1,  1, 50, 77,173,165,134,132,120, 40, 52, 28, 10,139,140,247,131,254,  0,  0,  0,  0,128, 64, 32,248, 14, 65, 72,202, 74,202,148, 45,214,178,130,196, 56,  8,  6, 33, 17, 46,  1,  0,  0,  0, 64,160, 29,  2,  0,  0,  0,192, 56,148,110, 42,186,254,252,162,  2, 67,147, 98, 34,100, 17,  2, 12,  8,  8,  6,  1,  1,  1,128,193, 34, 20, 12,  4,  3,  0,  0,255,  9,  9,121, 25,121, 73, 72,207, 
        0,  0,  0,192, 35, 22, 12,  4,128,112, 96,192,128,128,128,192,224, 56, 15,  0,  0,  0,  0,  0,  1,  1,247,  8,  4,  4,  6,132,248, 12,  6,  5, 72,136,144,149,182,184,184,241,240, 97, 19, 15,  1,  0,  0,  0,  3, 28, 44, 68, 69, 70, 70, 70, 70, 71, 70, 71, 74, 73, 46, 28, 12,  9, 22, 50, 78, 68, 56, 16, 32, 96,128,128,160,159,112,  0,  0,  0,  7, 28, 33, 78,124,223,177,160,231,206,222,249, 54, 20, 22,136, 64, 48, 16, 16, 96,128,128,128,  1,131, 68, 40, 48, 32,192,  0,  0,123,206,134, 50, 50, 50,134,206,123, 
        0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  7,  8,  8,  8,  8, 12,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  2,  2,  1,  0,  0,  1,  1,  2,  2,  2,  2,  2,  2,  2,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8,  8,  6,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8,  8,  4,  3,  0,  0,  0,124,195,153,159,195,249,153,195,126,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
        // oled_render_keylogs();
        // oled_renger_bootmagic_icon(keymap_config.swap_lalt_lgui);
    } else {
        render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // set_timelog();
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
