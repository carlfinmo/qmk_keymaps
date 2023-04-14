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
