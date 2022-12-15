#include "kirianm.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    switch (keycode) {

        /* Prints ñ/Ñ */
        case CKC_NTILD:
            if (record->event.pressed) {
                tap_code16(KC_TILDE);
                tap_code(KC_N);
            } else {
            }

            return false;
        break;

        /* Prints ~  // S(KC_GRAVE) // */
        case CKC_TILD:
            if (record->event.pressed) {
                tap_code16(KC_TILDE);
                tap_code(KC_SPACE);
            } else {
            }

            return false;
        break;

        /* Prints ñ/Ñ if ALT is holded while pressing letter N */
        case KC_N:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    bool isShifted = false;

                    if (mod_state & MOD_MASK_SHIFT) {
                        isShifted = true;
                    }

                    del_mods(MOD_MASK_ALT);

                    if (isShifted) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                    tap_code16(KC_TILDE);

                    if (isShifted) {
                        add_mods(MOD_BIT(KC_LSHIFT));
                    }
                    tap_code(KC_N);

                    set_mods(mod_state);

                    return false;
                }
                
                //  else if ((mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                //     clear_mods();

                //     tap_code16(KC_TILDE);
                //     tap_code(KC_SPACE);

                //     set_mods(mod_state);

                //     return false;
                // }
            }
        break;

        /* Prints ç/Ç if ALT is holded while pressing letter C */
        case KC_C:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    bool isShifted = false;

                    if (mod_state & MOD_MASK_SHIFT) {
                        isShifted = true;
                    }

                    del_mods(MOD_MASK_ALT);

                    if (isShifted) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                    tap_code(KC_QUOT);

                    if (isShifted) {
                        add_mods(MOD_BIT(KC_RSHIFT));
                    }
                    tap_code(KC_C);

                    set_mods(mod_state);

                    return false;
                }
            }
        break;

        /* Starts to write ` (KC_LBRC) if ALT is holded while pressing letter '" */
        case KC_QUOT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    clear_mods();

                    tap_code(KC_GRV);

                    set_mods(mod_state);

                    return false;
                }
            }
        break;
    }

    return true;
}
