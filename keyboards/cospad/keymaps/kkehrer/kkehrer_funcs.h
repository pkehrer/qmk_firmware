#include "quantum.h"

#define HUE_PINK 340

void rgb_default(void);
void rgb_init(void);

bool process_record_kkehrer(uint16_t keycode, keyrecord_t *record);
void matrix_init_kkehrer(void);


enum custom_keycodes {
  FUN_TOG = SAFE_RANGE
};
