#ifndef CONFIG_KKEHRER
#define CONFIG_KKEHRER

#include "config_common.h"
#include "../../config.h"

/* USB Device descriptor parameter */
#ifdef MANUFACTURER
#undef MANUFACTURER
#endif
#define MANUFACTURER    KPRepublic

#ifdef PRODUCT
#undef PRODUCT
#endif
#define PRODUCT         Cospad

#ifdef DESCRIPTION
#undef DESCRIPTION
#endif
#define DESCRIPTION     QMK keyboard firmware for cospad

#ifdef RGBLIGHT_HUE_STEP
#undef RGBLIGHT_HUE_STEP
#endif
#define RGBLIGHT_HUE_STEP 5

#ifdef RGBLIGHT_SAT_STEP
#undef RGBLIGHT_SAT_STEP
#endif
#define RGBLIGHT_SAT_STEP 17

#ifdef RGBLIGHT_VAL_STEP
#undef RGBLIGHT_VAL_STEP
#endif
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 1000


#endif
