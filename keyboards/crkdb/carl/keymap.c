/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
};

enum Layers {
  _QW = 0,
  _CM,
  _L1,
  _L2,
  _L3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I, KC_O, RALT_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SC_LSPO,LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                     KC_K,    KC_M, KC_COMM,  KC_DOT, LCTL_T(KC_SLSH),  SC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LGUI,   LT(_L1, KC_TAB),  KC_SPC,     KC_ENT,   MO(_L2), LALT_T(KC_MINUS)
                                      //`--------------------------'  `--------------------------'

  ),

// KC_LSPO and KC RSPC LALT_T(KC_MINUS)
// tab,space, lalt, minus enter

  [_QW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RALT_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SC_LSPO,    LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M, KC_COMM,  KC_DOT, LCTL_T(KC_SLSH),  SC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LGUI,   LT(_L1, KC_TAB),  KC_SPC,     KC_ENT,   MO(_L2), LALT_T(KC_MINUS)
                                      //`--------------------------'  `--------------------------'

  ),

  [_L1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK,                      QWERTY, XXXXXXX, XXXXXXX, KC_DOT, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |-hnei/------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(_L3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_L2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_LCTL, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, KC_F11, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_L3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_L3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

};

void caps_word_set_user(bool active) {
    oled_set_cursor(0, 1);
    oled_write_P(active ? PSTR("CAPS: WORD") : PSTR("          "), false);
}

/*
static void my_render_logo(void) {
static const char PROGMEM my_logo[] = {
	// 'untitled', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x02, 0x80, 
0x80, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x70, 0x18, 0x0c, 0x06, 0x02, 0x83, 
0x81, 0x81, 0x81, 0x01, 0x81, 0x81, 0x81, 0x83, 0x82, 0x86, 0x06, 0x1c, 0x38, 0xf0, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x0e, 0x03, 0x01, 
0x01, 0x01, 0x00, 0x80, 0xe0, 0x61, 0x31, 0x11, 0x1b, 0x8e, 0xfc, 0x08, 0x08, 0x18, 0x10, 0x30, 
0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf2, 
0xf2, 0x32, 0x1c, 0x18, 0x18, 0x68, 0xc8, 0x08, 0x10, 0x10, 0x00, 0x20, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xbc, 0x9e, 0x0f, 0x07, 
0x03, 0x01, 0x00, 0x00, 0xc0, 0xc1, 0x62, 0x26, 0x04, 0x48, 0x90, 0x3f, 0x3f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x70, 0xc0, 0x80, 0x03, 0x03, 0x07, 
0x03, 0x03, 0x07, 0x07, 0x03, 0x03, 0x07, 0x02, 0x0a, 0x12, 0x80, 0xcc, 0xe0, 0x7f, 0x1f, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf3, 0x1f, 0x0e, 0x0e, 
0x0e, 0x0b, 0x1b, 0x1f, 0x3b, 0x6b, 0xcf, 0x86, 0x86, 0x9f, 0xf9, 0xe0, 0x80, 0x80, 0xc0, 0xc0, 
0x70, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0xf3, 0x70, 
0xd8, 0x8d, 0x86, 0xc6, 0x66, 0x3f, 0x0f, 0x09, 0x99, 0x91, 0xd1, 0x79, 0x39, 0x1f, 0x19, 0x0a, 
0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x05, 0x08, 0x08, 0xfd, 0x0c, 0x07, 0x80, 
0x80, 0x60, 0xb8, 0x91, 0x97, 0x84, 0xcd, 0xff, 0x6c, 0x76, 0x33, 0x10, 0x10, 0x90, 0xe0, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 
0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e, 0x0c, 0x18, 
0x10, 0x30, 0x30, 0x20, 0x20, 0x30, 0x30, 0x18, 0x18, 0x0d, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x02, 
0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x01, 0x01, 
0x01, 0x00, 0x00, 0x00, 0x7d, 0x0d, 0x96, 0xdf, 0xc2, 0x64, 0x38, 0x00, 0x00, 0x00, 0x01, 0x00
};
  oled_write_raw_P(my_logo, sizeof(my_logo));
}
*/

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _QW:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _CM:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _L1:
            oled_write_ln_P(PSTR("L1"), false);
            break;
        case _L2:
            oled_write_ln_P(PSTR("L2"), false);
            break;
        case _L3:
            oled_write_ln_P(PSTR("L3"), false);
            break;
    }
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
      // If you want to put your image on the master side, put your function call here:
      // render_logo();
      oled_render_layer_state();
    } else {
      //oled_write_ln_P(PSTR("Uhu?"), false);
      // And if you want to put your image on the slave side, put it here instead:
      //my_render_logo();
      render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //if (record->event.pressed) {
  //  set_keylog(keycode, record);
  //}
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CM);
      }
      return false;
    default: 
      return true;
  }
  return true;
}
