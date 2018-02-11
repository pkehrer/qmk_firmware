#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _AL 2
#define _RL 3


#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    PK_SNIPTOOL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * .-----------------------------------------------------------.
   * |GESC | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS-FN|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN-A|Ctrl |
   * '-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  MO(_FL),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT, KC_RGUI, TG(_AL),KC_RCTL),

// "Function"
[_FL] = KEYMAP_ANSI(
  MO(_RL), KC_F1,KC_F2,KC_F3 ,KC_F4 ,KC_F5 ,KC_F6 ,KC_F7 ,KC_F8,KC_F9,KC_F10,KC_F11 ,KC_F12,KC_DEL,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_PAUSE,KC_HOME, KC_END,_______, \
  _______,_______,PK_SNIPTOOL,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,KC_CALCULATOR,_______,_______,_______,_______,_______,_______,_______,KC_UP, \
  _______,_______,_______,                _______,                        _______,KC_LEFT,KC_DOWN,KC_RIGHT),

// "Admin"
[_AL] = KEYMAP_ANSI(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,  \
  XXXXXXX,   KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,BL_DEC,BL_INC,BL_TOGG, \
  XXXXXXX,      KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  XXXXXXX,         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,MAGIC_TOGGLE_NKRO,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX, \
  _______,   _______,_______,                XXXXXXX,                            _______,_______,_______,_______),

// "Reset"
[_RL] = KEYMAP_ANSI(
  _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     RESET,  \
  XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  _______,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  XXXXXXX,         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX, \
  _______,   _______,_______,                XXXXXXX,                            _______,_______,_______,_______),

};

void breath(uint8_t period) {
    if (!is_breathing()) {
      breathing_enable();
    }
    breathing_period_set(period);
}

void matrix_init_user(void) {
  breathing_disable();
}

#define SEND_WIN_STRING(str) \
  send_string_with_delay_P(PSTR(\
    SS_TAP(X_LGUI)""str""SS_TAP(X_ENTER)\
  ), 10);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_B:
      if (record->event.pressed) {
        breathing_pulse();
      }
      return true;
    case KC_CALCULATOR:
      if(record->event.pressed) {
        SEND_WIN_STRING("calculator");
      }
      return false;
    case PK_SNIPTOOL:
      if (record->event.pressed) {
        SEND_WIN_STRING("snipping tool");
      }
      return false;
    default:
      return true;
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
    case _BL:
      breathing_disable();
      break;
    case _FL:
      breath(6);
      break;
    case _RL:
      breath(12);
      break;
    case _AL:
    default:
      breath(1);
      break;
  }
  return state;
}
