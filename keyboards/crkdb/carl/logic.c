#include "bongo.c"

void caps_word_set_user(bool active) {
    if (is_keyboard_master()) {
    oled_set_cursor(0, 1);
    oled_write_P(active ? PSTR("CAPS: WORD") : PSTR("          "), false);
    }
}


void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state | default_layer_state)) {
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

bool should_process_keypress(void) { return true; }

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to put your image on the master side, put your function call
    // here: render_logo();
    oled_render_layer_state();
    // needed for bongocat?
    /* oled_render_keylog(); */
  } else {
    // oled_write_ln_P(PSTR("Uhu?"), false);
    //  And if you want to put your image on the slave side, put it here
    //  instead:
    // my_render_logo();
    render_anim(); // renders pixelart

    oled_set_cursor(
        0, 0); // sets cursor to (row, column) using charactar spacing (5 rows
               // on 128x32 screen, anything more will overflow back to the top)
    // sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to
    // change wwhat shows up, edit %03d to change how many digits show up
    // oled_write(wpm_str, false);                       // writes wpm on top
    // left corner of string

    // This way it's more size efficient than calling sprintf
    /* oled_write_P(PSTR("WPM: "), false); */
    /* oled_write(get_u8_str(get_current_wpm(), ' '), false); */
    // This way it's more size efficient than calling sprintf

    led_t led_state =
        host_keyboard_led_state(); // caps lock stuff, prints CAPS on new line
                                   // if caps led is on

    oled_set_cursor(0, 1);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false);
    // render_logo();
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (record->event.pressed) {
  //   set_keylog(keycode, record);
  // }
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
