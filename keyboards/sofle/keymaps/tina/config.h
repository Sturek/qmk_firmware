#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define OLED_TIMEOUT 180000

//Underglow
#define RGB_DI_PIN D3
#define RGBLED_NUM 14
#define RGBLED_SPLIT {7,7}
#define RGBLIGHT_LED_MAP { 7, 6, 5, 4 ,3 , 2, 1, 0, 8, 9, 10, 11, 12, 13, 14}
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_LAYERS