#include QMK_KEYBOARD_H
#include "kirianm.h"

#define L_QWERTY 0
#define L_NUMBERS 1
#define L_SYMBOLS 2
#define L_ARROWS 3
#define L_FN 4
#define L_SETTINGS 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H, KC_J, KC_K, KC_L, LT(L_ARROWS, KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        KC_LGUI, MO(L_NUMBERS), KC_SPC,                                 KC_ENT, MO(L_SYMBOLS), KC_RALT
    ),
	[L_NUMBERS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX,
        _______, MO(L_SETTINGS), _______,                                _______, KC_0, _______
    ),
	[L_ARROWS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, _______,                                      _______, XXXXXXX, _______
    ),
	[L_SYMBOLS] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        _______, _______, KC_SPC,                                       KC_ENT, _______, KC_RALT
    ),
	[L_FN] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_F1, KC_F2, KC_F3, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX, XXXXXXX,
        _______, _______, _______,                                      _______, KC_F10, _______
    ),
	[L_SETTINGS] = LAYOUT_split_3x6_3(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX
    )
};

