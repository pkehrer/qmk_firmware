/* Copyright 2017 Paul Kehrer
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
#define FN_LAYER 1

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = KEYMAP(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, \
    KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, \
    KC_SPACE,       KC_Z,       LT(FN_LAYER, KC_B)),

  [FN_LAYER] = KEYMAP(
    _______, _______, _______, _______, RESET, \
    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, \
    _______,          _______,          _______),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    // something fun here?
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
