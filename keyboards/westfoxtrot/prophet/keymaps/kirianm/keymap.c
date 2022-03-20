#include QMK_KEYBOARD_H
#include "kirianm.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_BSPC,XX,
        LT(_NUM, KC_TAB), KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC,   KC_RBRC,    KC_BSLS,
        LCTL_T(KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   LT(_FN, KC_SCLN),  KC_QUOT,    KC_ENT,
        KC_LSFT,XX, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_RSFT,    KC_DEL,
        KC_LCTL,    KC_LGUI,    KC_LALT,                        KC_SPC,                     KC_RALT,  MO(_EX),   KC_RCTL
    ),
    [_FN] = LAYOUT_all(
        _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL, XX,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
        _______,    KC_LGUI,  KC_LALT,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,            _______,
        _______,    XX,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,                                _______,                                          _______,  _______,  _______
    ),
    [_EX] = LAYOUT_all(
        _______,    _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, XX, 
        _______,    KC_F13,  KC_F14,   KC_F15,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET, 
        _______,    KC_F16,  KC_F17,   KC_F18,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______, 
        _______,XX, KC_F19,   KC_F20,   KC_F21,  _______,   _______,  CKC_TILD, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______, 
        _______,    _______, _______,                                 KC_MPLY,                                          _______,  _______,  _______
    ),
    [_NUM] = LAYOUT_all(
        _______,    _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, XX, 
        _______,    _______,  _______,   _______,   _______,   _______,  _______,   KC_7,  KC_8,  KC_9,  _______,  _______,  _______,  RESET, 
        _______,    _______,  _______,   _______,   _______,   _______,  _______,   KC_4,  KC_5,  KC_6,  _______,  _______,            _______, 
        _______,XX, _______,   _______,   _______,  _______,   _______,  _______,   KC_1,  KC_2,  KC_3,  KC_0,  _______,  _______, 
        _______,    _______, _______,                                 _______,                                          _______,  _______,  _______
    ),
    // [_DVORAK] = LAYOUT_all(
    //     KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC,    KC_RBRC, KC_BSPC,XX, 
    //     KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSLS, 
    //     LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,          KC_ENT, 
    //     KC_LSFT,XX, KC_SCLN,KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_DEL, 
    //     KC_LCTL,    KC_LGUI,    KC_LALT,                        KC_SPC,                     KC_RALT,  MO(_EX),   KC_RCTL
    // ),
};
