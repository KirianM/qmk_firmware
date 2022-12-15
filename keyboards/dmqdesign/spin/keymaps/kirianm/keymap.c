#include QMK_KEYBOARD_H
#include "kirianm.h"

enum layers {
    _MACRO,
    _NUMPAD,
    _CONFIG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MACRO] = LAYOUT(
                KC_F13, KC_F14, KC_F15, KC_MPLY,
                KC_F16, KC_F17, KC_F18, TO(_NUMPAD),
                KC_F19, KC_F20, KC_F21, TO(_CONFIG),
                KC_NO, KC_LALT, RSFT_T(KC_NO)
                ),
    [_NUMPAD] = LAYOUT(
                KC_KP_7, KC_KP_8, KC_KP_9, TO(_MACRO),
                KC_KP_4, KC_KP_5, KC_KP_6, KC_NO,
                KC_KP_1, KC_KP_2, KC_KP_3, TO(_CONFIG),
                KC_NO, KC_NO, KC_KP_0
                ),
    [_CONFIG] = LAYOUT(
                RESET, KC_NO, KC_NO, TO(_MACRO),
                KC_NO, KC_NO, KC_NO, TO(_NUMPAD),
                KC_NO, KC_NO, KC_NO, KC_NO,
                RGB_TOG, KC_LEFT, KC_RIGHT
                ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU); // Volume
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
            case _MACRO:
            case _CONFIG:
                if (clockwise) {
                    // Page Down
                    tap_code(KC_PGDOWN);
                } else {
                    // Page Up
                    tap_code(KC_PGUP);
                }
                break;
        }
    } else if (index == 2) { /* Third encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
            case _MACRO:
            case _CONFIG:
                if (clockwise) {
                    // Arrow Down
                    for(int i = 0; i <= 6; i++) {
                        tap_code(KC_DOWN);
                    }
                } else {
                    // Arrow Up
                    for(int i = 0; i <= 6; i++) {
                        tap_code(KC_UP);
                    }
                }
                break;
        }
    }
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _MACRO:
            setrgb(RGB_RED, &led[0]);
            setrgb(RGB_GOLD, &led[1]);
            setrgb(RGB_GOLD, &led[2]);
            break;
        case _NUMPAD:
            setrgb(RGB_GOLD, &led[0]);
            setrgb(RGB_RED, &led[1]);
            setrgb(RGB_GOLD, &led[2]);
            break;
        case _CONFIG:
            setrgb(RGB_GOLD, &led[0]);
            setrgb(RGB_GOLD, &led[1]);
            setrgb(RGB_RED, &led[2]);
            break;
    }

    rgblight_set();
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    switch (get_highest_layer(state)) {
        case _MACRO:
            setrgb(RGB_RED, &led[0]);
            setrgb(RGB_GOLD, &led[1]);
            setrgb(RGB_GOLD, &led[2]);
            break;
        case _NUMPAD:
            setrgb(RGB_GOLD, &led[0]);
            setrgb(RGB_RED, &led[1]);
            setrgb(RGB_GOLD, &led[2]);
            break;
        case _CONFIG:
            setrgb(RGB_GOLD, &led[0]);
            setrgb(RGB_GOLD, &led[1]);
            setrgb(RGB_RED, &led[2]);
            break;
    }

    rgblight_set();

    return state;
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    #ifdef LEFT_HAND
        return OLED_ROTATION_180;
    #else
        return OLED_ROTATION_0;
    #endif
}

void oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MACRO:
            oled_write_P(PSTR("Macro\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _CONFIG:
            oled_write_P(PSTR("Config\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_ln_P(PSTR("Kirian Murgadella"), false);
}
#endif