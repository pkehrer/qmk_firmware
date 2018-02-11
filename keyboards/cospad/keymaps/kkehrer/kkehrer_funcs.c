#include "cospad.h"
#include "rgblight.h"
#include "kkehrer_funcs.h"

extern rgblight_config_t rgblight_config;

#define KEYDOWN(record) record->event.pressed
#define KEYUP(record) !record->event.pressed

void rgb_init(void) {
  rgblight_init();
  rgblight_mode(1);
  rgblight_sethsv(HUE_PINK, rgblight_config.sat, rgblight_config.val);
}

bool process_keys_bl(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case BL_TOGG:
         if (KEYDOWN(record)) { cospad_bl_led_togg(); }
         return false;
      case BL_ON:
         if (KEYDOWN(record)) {
            cospad_bl_led_on();
         }
         return false;
      case BL_OFF:
      default:
         if(KEYDOWN(record)) {
            cospad_bl_led_off();
         }
         return false;
  }
}

void matrix_init_kkehrer(void) {
  rgb_init();
  cospad_bl_led_on();
}

bool process_record_kkehrer(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
        if (KEYDOWN(record)) { cospad_bl_led_togg(); }
        return false;
      case BL_ON:
        if (KEYDOWN(record)) { cospad_bl_led_on(); }
        return false;
      case BL_OFF:
        if (KEYDOWN(record)) { cospad_bl_led_off(); }
        return false;
      default:
         return true;
   }
}
