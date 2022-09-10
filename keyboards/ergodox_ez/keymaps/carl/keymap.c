#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  QWERTY,
  COLEMAK,
};

enum {
  TD_QUOTE,
  TD_BRACKET,
  TD_POE, // P or Ö = altgr(p)
  TD_AAO, // A or Å
  TD_QAE, // Q or Ä
};

enum layers {
  _QW,
  _CM,
  _L1,
  _L2,
  _L3,
};

#define WITHOUT_MODS(...) \
  do { \
    const uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

typedef struct {
    uint16_t keycode;
    uint16_t keycode2;
} test_user_data_t;

#define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) \
        { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)user_user_data, }


void quote_taps(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
	// if shift 
	//clear_mods();
	bool lshift = get_mods() & (MOD_BIT(KC_LSHIFT));
	bool rshift = get_mods() & (MOD_BIT(KC_RSHIFT));
	if (lshift || rshift) { 
		tap_code(KC_QUOTE);
		//tap_code(KC_LEFT);
		tap_code(KC_QUOTE);
	} else {
		tap_code(KC_QUOTE);
		tap_code(KC_QUOTE);
		//tap_code(KC_LEFT);
	}
	WITHOUT_MODS({
	  SEND_STRING(SS_TAP(X_LEFT));
	});

        reset_tap_dance(state);
    }
}

void bracket_taps(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
	tap_code(KC_LBRACKET);
    }
    else if (state->count >= 2) {
	bool lshift = get_mods() & (MOD_BIT(KC_LSHIFT));
	bool rshift = get_mods() & (MOD_BIT(KC_RSHIFT));
	if (lshift || rshift) { 
		clear_mods();
		tap_code(KC_RBRACKET);
		tap_code(KC_LEFT);
		tap_code(KC_LBRACKET);
	} else {
		tap_code(KC_LBRACKET);
		tap_code(KC_RBRACKET);
		tap_code(KC_LEFT);
	}

        reset_tap_dance(state);
    }
}

void swedish_keys(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = ((test_user_data_t*)user_data)->keycode;
    uint16_t keycode2 = ((test_user_data_t*)user_data)->keycode2;
    switch (state->count) {
        case 1:
            tap_code16(keycode);
            break;
        case 2:
	    tap_code16(ALGR(keycode2));
            break;
    }
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QUOTE] = ACTION_TAP_DANCE_FN(quote_taps),
    [TD_BRACKET] = ACTION_TAP_DANCE_FN(bracket_taps),
    [TD_POE] = ACTION_TAP_DANCE_FN_ADVANCED_USER(NULL, swedish_keys, NULL, &((test_user_data_t){KC_P, KC_P})),
    [TD_AAO] = ACTION_TAP_DANCE_FN_ADVANCED_USER(NULL, swedish_keys, NULL, &((test_user_data_t){KC_A, KC_W})),
    [TD_QAE] = ACTION_TAP_DANCE_FN_ADVANCED_USER(NULL, swedish_keys, NULL, &((test_user_data_t){KC_Q, KC_Q})),
};


// KC_APPLICATION
// KC_HYPR KC_MEH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   // q w f p g j j l u y ;
   // a r s t d h n e i o
   // z x c v b k m , .
  [_CM] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_ESCAPE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_LBRACKET,                                    KC_RBRACKET,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,           KC_BSLASH,
    KC_BSPACE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,                                                                           KC_H,           KC_N,           KC_E,           KC_I,           KC_O,  RALT_T(KC_QUOTE),
    KC_LSPO,      LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           LGUI_T(KC_EQUAL),                                        LGUI_T(LSFT(KC_EQUAL)),         KC_K,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH), KC_RSPC,
    LT(_L1,KC_GRAVE), KC_RALT,        CAPS_WORD,KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        TD(TD_QUOTE),    TD(TD_BRACKET),    MO(_L2),
                                                                                                            KC_LCTL,KC_LALT,        KC_PSCR,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_TAB,       KC_SPACE,         KC_END,         KC_PGDOWN,      LALT_T(KC_MINUS),         KC_ENTER
  ),
  [_QW] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_ESCAPE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      TD(TD_QAE),           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           TD(TD_POE),           KC_BSLASH,
    KC_BSPACE,      TD(TD_AAO),           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON, RALT_T(KC_QUOTE),
    KC_LSPO,      LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,          LGUI_T(KC_EQUAL),                                        LGUI_T(LSFT(KC_EQUAL)),         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH), KC_RSPC,
    LT(_L1,KC_GRAVE), KC_RALT,        KC_LALT,KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        TD(TD_QUOTE),    TD(TD_BRACKET),    MO(_L2),
                                                                                                           KC_LCTL, KC_LALT,        KC_PSCR,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_TAB,       KC_SPACE,         KC_END,         KC_PGDOWN,      LALT_T(KC_MINUS),         KC_ENTER
  ),



  [_L1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    LCTL(KC_LALT), KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_LCTL,        KC_LALT,RGB_TOG,        RGB_SLD,
                                                                                                                    HSV_86_255_128, KC_TRANSPARENT,
                                                                                    RGB_VAD,        RGB_VAI,        HSV_27_255_255, KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),


  [_L2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, LCTL(LALT(KC_F1)), LCTL(LALT(KC_F2)), LCTL(LALT(KC_F3)), LCTL(LALT(KC_F4)), LCTL(LALT(KC_F5)), KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LALT(KC_F6)), LCTL(LALT(KC_F7)), LCTL(LALT(KC_F8)), LCTL(LALT(KC_F9)), LCTL(LALT(KC_F10)), RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, WEBUSB_PAIR,    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, COLEMAK, QWERTY, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
	ergodox_right_led_3_on();
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CM);
	ergodox_right_led_3_off();
      }
      return false;
    default: 
      return true;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  //ergodox_right_led_3_off();
  switch (layer) {
    case _L1:
      ergodox_right_led_1_on();
      break;
    case _L2:
      ergodox_right_led_2_on();
      break;
    case _L3:
      ergodox_right_led_3_on();
      break;
/*
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
*/
    default:
      break;
  }
  return state;
};
