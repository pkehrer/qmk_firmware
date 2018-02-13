/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "pkehrerpad.h"

#define BASE_LAYER 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = KEYMAP(
    KC_7, KC_8, KC_9, \
    KC_4, KC_5, KC_6, \
    KC_1, KC_2, KC_3  \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void pk_send_word(uint16_t keycode) {
    switch(keycode) {
      case KC_1:
        send_string("Paul ");
        break;
      case KC_2:
        send_string("Kehrer ");
        break;
      case KC_3:
        send_string("makes ");
        break;
      case KC_4:
        send_string("the ");
        break;
      case KC_5:
        send_string("best ");
        break;
      case KC_6:
        send_string("keyboards ");
        break;
      case KC_7:
        send_string("in ");
        break;
      case KC_8:
        send_string("the ");
        break;
      case KC_9:
        send_string("world ");
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    //pk_send_word(keycode);
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
