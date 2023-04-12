/* Copyright 2018 Carlos Filoteo
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

enum layers {
  _QW,
  _CM,
  _L1,
  _L2,
  _L3,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};


#define LT3_TAB LT(_L3, KC_TAB)
#define LT3_MINUS LT(_L3, KC_MINUS)
#define LT1_TAB LT(_L1, KC_TAB)
//#define LT2_SPC LT(_L2, KC_SPC)
#define LT2_RET LT(_L2, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Alt | Gui | App |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

[_QW] = LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LT3_MINUS,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RALT_T(KC_QUOT),
  SC_LSPO, LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), SC_RSPC,
  KC_LCTL, KC_LALT, KC_LEFT, KC_RIGHT,  LT1_TAB, KC_SPC,  LT2_RET, KC_UP, KC_DOWN, KC_LGUI,   KC_APP
),
[_CM] = LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    LT3_MINUS,
  KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, RALT_T(KC_QUOT),
  SC_LSPO, LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), SC_RSPC,
  KC_LCTL, KC_LALT, KC_LEFT, KC_RIGHT,  LT1_TAB, KC_SPC,  LT2_RET, KC_UP, KC_DOWN, KC_LGUI,   KC_APP
),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_L1] = LAYOUT( /* Right */
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE,
  KC_DEL , RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  _______,  _______,  _______,  _______,
  _______, _______, KC_HOME, KC_END, _______,     _______,      _______, KC_PGUP, KC_PGDN, _______, _______
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_L2] = LAYOUT( /* Left */
  KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DELETE,
  KC_DEL , _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, KC_HOME, KC_END, _______,     _______,      _______, KC_PGUP, KC_PGDN, _______, _______
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

[_L3] = LAYOUT( /* Tab */
  KC_ESC,  KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_R, KC_MS_BTN1,   _______,    KC_MS_BTN2, KC_MS_U, KC_MS_D, QWERTY, COLEMAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
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
};
