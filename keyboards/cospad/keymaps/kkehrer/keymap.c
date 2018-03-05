#include "kkehrer_funcs.h"
#include "cospad.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define FN MO(_FL)



#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * .-------------------.
   * | (  | )  | ^  | *  |
   * |----|----|----|----|
   * | 7  | 8  | 9  | /  |
   * |----|----|----|----|
   * | 4  | 5  | 6  | +  |
   * |----|----|----|----|
   * | 1  | 2  | 3  | -  |
   * |----|----|----|----|
   * | .  | 0  | UP | =  |
   * |----|----|----|----|
   * |FN  |LFT |DWN |RGT |
   * '-------------------'
   */
[_BL] = KEYMAP(
  KC_LPRN,  KC_RPRN,  KC_CIRC,  KC_PAST, \
  KC_P7,    KC_P8,    KC_P9,    KC_PSLS, \
  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  \
  KC_P1,    KC_P2,    KC_P3,    KC_PMNS, \
  KC_PDOT,  KC_P0,    KC_UP,    KC_EQL, \
  FN,       KC_LEFT,  KC_DOWN,  KC_RIGHT),


  /* Keymap _FL: Function Layer
   * .-------------------.
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |BLTG|RTOG|    |
   * |----|----|----|----|
   * |    |BL+ |VAL+|    |
   * |----|----|----|----|
   * |    |BL- |VAL-|    |
   * '-------------------'
   */
[_FL] = KEYMAP(
  _______, _______, _______, RESET, \
  _______, _______, _______, _______, \
  _______, _______, _______, _______, \
  _______, BL_TOGG, RGB_TOG, _______, \
  _______, BL_INC, RGB_VAI, _______, \
  _______, BL_DEC, RGB_VAD, _______),
};


void matrix_init_user(void) {
  matrix_init_kkehrer();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_kkehrer(keycode, record);
}
