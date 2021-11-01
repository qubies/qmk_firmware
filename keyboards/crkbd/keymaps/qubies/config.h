/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define VENDOR_ID 0x4653
#define PRODUCT_ID 0x0001


// #define MANUFACTURER littlekeyboards
// #define PRODUCT corne 1.1
// #define DESCRIPTION corne 1.1

// #define USE_MATRIX_I2C

/* Select hand configuration */

//#define MASTER_LEFT
#define MASTER_RIGHT

// #define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define LEADER_TIMEOUT 500
// #define MK_KINETIC_SPEED

// #define AUTO_SHIFT_TIMEOUT 250

#define COMBO_COUNT 3
#define COMBO_TERM 100 //timeout for combos
//#define SPLIT_HAND_PIN B7
//#define SPLIT_USB_DETECT

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
