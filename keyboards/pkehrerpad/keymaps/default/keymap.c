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
#include "pro_micro.h"

#define BASE_LAYER 0
#define FN_LAYER 1

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    TX_LED_TOGG = SAFE_RANGE,
    RX_LED_TOGG
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = KEYMAP(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, \
    KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, \
    KC_LCTRL,       KC_SPACE,       LT(FN_LAYER, KC_B)),

  [FN_LAYER] = KEYMAP(
    _______, _______, RX_LED_TOGG, TX_LED_TOGG, RESET, \
    _______, _______, _______, _______, _______, \
    _______, KC_Z,    KC_X,    KC_C,    KC_V, \
    _______,          _______,          _______),
};

void matrix_init_user(void) {
  TX_RX_LED_INIT;
  TXLED0;
  RXLED0;
}

void matrix_scan_user(void) {

}

bool txOn = false;
bool rxOn = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    switch(keycode) {
      case TX_LED_TOGG:
        if (txOn) {
          TXLED0;
        } else {
          TXLED1;
        }
        txOn = !txOn;
        return false;
      case RX_LED_TOGG:
        if(rxOn) {
          RXLED0;
        } else {
          RXLED1;
        }
        rxOn = !rxOn;
        return false;
    }
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
