
/*
   Copyright 2019 @foostan
   Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/caps_word.h"

char wpm_str[10];

#define NORMAL 0
#define NAV 1
#define SYMBOL 2
#define MOUSE 3
#define NUMBERS 4
#define FUNCTIONS 5
#define GAMING 6
#define GAMING2 7


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT_split_3x6_3(
            KC_TAB,     KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,              KC_J,   KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_EQL,
            KC_GRV,     LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,              KC_M,   RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
            KC_BSLS,    KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,              KC_K,   KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_MINS,
            MO(SYMBOL), MO(NAV),      MO(NUMBERS),                                                 KC_SPC, KC_LEAD,      KC_BSPC
            ),

    [NAV] = LAYOUT_split_3x6_3(
            KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
            KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                    KC_FIND, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
            KC_TRNS, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_BTN5, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS,                                                             KC_TRNS,  KC_TRNS, KC_TRNS
            ),

    [SYMBOL] = LAYOUT_split_3x6_3(
            KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_NO,   KC_LCBR, KC_RCBR, KC_HASH, KC_SCLN, KC_EQL,
            KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                    KC_BSLS,   KC_LPRN, KC_RPRN, KC_LT,   KC_GT,   KC_QUOT,
            KC_TRNS, KC_LALT, KC_NO,   KC_NO,   KC_BSLS, KC_NO,                                    KC_BSLS, KC_LBRC, KC_RBRC, KC_DOT,  KC_SLSH, KC_MINS,
            KC_TRNS, KC_TRNS, KC_TRNS,                                                             KC_TRNS,  KC_TRNS,  KC_TRNS
            ),

    [NUMBERS] = LAYOUT_split_3x6_3(
            KC_TRNS, KC_NO,         KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,                              KC_BSLS, KC_7, KC_8, KC_9, KC_SCLN, KC_EQL,
            KC_TRNS, KC_NO,         KC_DLR,  KC_PERC, KC_CIRC, KC_NO,                              KC_0,    KC_4, KC_5, KC_6, KC_GRV,  KC_QUOT,
            KC_TRNS, KC_LALT,       KC_EXLM, KC_AT,   KC_HASH, KC_NO,                              KC_PDOT, KC_1, KC_2, KC_3, KC_SLSH, KC_MINS,
            KC_TRNS, MO(FUNCTIONS), KC_TRNS,                                                       KC_TRNS,  KC_0, KC_TRNS
            ),
    [FUNCTIONS] = LAYOUT_split_3x6_3(
            KC_TRNS, KC_NO,   KC_F7,  KC_F8, KC_F9, KC_F12,                                        KC_NO,   KC_F7,  KC_F8,  KC_F9, KC_F12, KC_NO,
            KC_TRNS, KC_NO,   KC_F4,  KC_F5, KC_F6, KC_F11,                                        KC_NO,   KC_F4,  KC_F5,  KC_F6, KC_F11, KC_NO,
            KC_TRNS, KC_NO,   KC_F1,  KC_F2, KC_F3, KC_F10,                                        KC_NO,   KC_F1,  KC_F2,  KC_F3, KC_F10, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS,                                                             KC_TRNS, KC_SPC, KC_TRNS
            ),
    [GAMING] = LAYOUT_split_3x6_3(
            LGUI_T(KC_TAB), KC_Q,         KC_W, KC_F, KC_P, KC_G,                                  KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_EQL,
            LCTL_T(KC_GRV), KC_A,         KC_R, KC_S, KC_T, KC_D,                                  KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
            OSM(MOD_LSFT),  LALT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                                  KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
            KC_TRNS,        KC_TRNS,      KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_TRNS
            ),
};
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LALT_T(KC_R):
        case LCTL_T(KC_S):
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
        case RCTL_T(KC_E):
        case RALT_T(KC_I):
        case RGUI_T(KC_O):
            return true;
        default:
            return false;
    }
}


const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_Z):
        case RGUI_T(KC_EQL):
        case RSFT_T(KC_QUOT):
        case RALT_T(KC_SLSH):
        case RCTL_T(KC_MINS):
        case LT(FUNCTIONS, KC_SPC):
            return TAPPING_TERM + 900;
            break;

        default:
            return TAPPING_TERM;
    }
}


LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_ONE_KEY(KC_O) {
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_RGHT);
            unregister_code(KC_RGHT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
        }
        SEQ_ONE_KEY(KC_N) {
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_LEFT);
            unregister_code(KC_LEFT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
        }
        SEQ_ONE_KEY(KC_F) {
            register_code(KC_LCTL);
            register_code(KC_ESC);
            unregister_code(KC_LCTL);
            unregister_code(KC_ESC);

        }
        SEQ_ONE_KEY(KC_U) {
            register_code(KC_LCTL);
            register_code(KC_ESC);
            unregister_code(KC_LCTL);
            unregister_code(KC_ESC);
        }
        SEQ_ONE_KEY(KC_W) {
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            register_code(KC_LSFT);
            register_code(KC_SCLN);
            unregister_code(KC_LSFT);
            unregister_code(KC_SCLN);
            register_code(KC_W);
            unregister_code(KC_W);
            register_code(KC_ENT);
            unregister_code(KC_ENT);

        }
    }
}

enum combo_events {
  GAME_ON,
  ESCAPE,
  ENTER,
  UNDO,
  CUT,
  COPY,
  PASTE,
  ENTERTWO
};

const uint16_t PROGMEM game_on[] = {KC_Q, KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM entertwo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM escape[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM undo[] = {KC_GRV, KC_G, COMBO_END};
const uint16_t PROGMEM cut[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [GAME_ON] = COMBO_ACTION(game_on),
    [ESCAPE] = COMBO(escape, KC_ESC),
    [ENTER] = COMBO(enter, KC_ENT),
    [ENTERTWO] = COMBO(entertwo, KC_ENT),
    [UNDO] = COMBO(undo, LCTL(KC_Z)),
    [CUT] = COMBO(cut, LCTL(KC_X)),
    [COPY] = COMBO(copy, LCTL(KC_C)),
    [PASTE] = COMBO(paste, LCTL(KC_V)),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case GAME_ON:
      if (pressed) {
        layer_invert(GAMING2);
      }
      break;
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

char keylog_str[24] = {};


#define LT_NORMAL 0
#define LT_NAV 2
#define LT_SYMBOL 4
#define LT_MOUSE 8
#define LT_NUMBERS 16
#define LT_FUNCTIONS 32

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_logo();
    } else {
        oled_render_logo();
    }
}
#endif // OLED_DRIVER_ENABLE

