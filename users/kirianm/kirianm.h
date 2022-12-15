#pragma once

#include "quantum.h"

#define XX KC_NO

enum userspace_layers {
  _QWERTY = 0, // Base Layer,
  _FN = 1, // FX Layer + Arrow Keys,
  _EX = 2, // Extra Layer,
  _NUM = 3
};

// Enum of custom keycodes defined in process_record_user
enum keycodes {
    CKC_NTILD = SAFE_RANGE, // Output ñ/Ñ.
    CKC_TILD
};
