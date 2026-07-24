#pragma once

#define MASTER_LEFT
#define LAYER_STATE_8BIT

#ifdef OLED_ENABLE
#   define SPLIT_LAYER_STATE_ENABLE
#   define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif

// Fix home row mods not emiting keys on Macos login prompt.
#define TAP_CODE_DELAY 10

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM.
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// https://docs.qmk.fm/#/feature_auto_shift?id=retro-shift
#define RETRO_SHIFT 500

#define NO_AUTO_SHIFT_SPECIAL

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
