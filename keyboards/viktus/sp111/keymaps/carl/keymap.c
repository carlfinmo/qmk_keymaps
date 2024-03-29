/* Copyright 2020 blindassassin111
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum Layers {
  _CM = 0,
  _QW,
  _L1,
  _L2,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
};


// KC_AUDIO_VOL_UP KC_VOLU
// KC_AUDIO_VOL_DOWN KC_VOLD
// KC_MPLY KC_MNXT
  /* SC_LSPO,    SC_RSPC, */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_CM] = LAYOUT_all(
    KC_MUTE, KC_MPLY, KC_VOLU, KC_VOLD,      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,  KC_DEL, KC_INS,
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,      KC_DEL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,        KC_HOME,  KC_END,
    KC_P4,   KC_P5,   KC_P6,   KC_PEQL,      KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, RALT_T(KC_QUOT), KC_NUHS, KC_ENT,               KC_PGUP, KC_PGDN,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,      SC_LSPO, LCTL_T(KC_NUBS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  LCTL_T(KC_SLSH), SC_RSPC, MO(_L1),            KC_UP,
    KC_P0,   KC_P0,   KC_PDOT, KC_PDOT,      KC_LCTL, KC_LGUI, KC_LALT, KC_TAB, KC_SPC,           KC_ENT,  KC_APP,  KC_RALT, KC_RGUI, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RIGHT),

	[_QW] = LAYOUT_all(
    KC_MUTE, KC_MPLY, KC_VOLU, KC_VOLD,      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,  KC_DEL, KC_INS,
    KC_P7,   KC_P8,   KC_P9,   KC_PEQL,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_HOME,  KC_END,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RALT_T(KC_QUOT), KC_NUHS, KC_ENT,           KC_PGUP, KC_PGDN,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,      SC_LSPO, LCTL_T(KC_NUBS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LCTL_T(KC_SLSH), SC_RSPC, MO(_L1),            KC_UP,
    KC_P0,   KC_P0,   KC_PDOT, KC_PDOT,      KC_LCTL, KC_LGUI, KC_LALT, KC_TAB, KC_SPC,           KC_SPC,  KC_APP,  KC_RALT, KC_RGUI, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RIGHT),

    [_L1] = LAYOUT_all(
    COLEMAK, QWERTY, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, QK_BOOT,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,                            _______, _______, _______),

    [_L2] = LAYOUT_all(
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,                            _______, _______, _______),
};

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
