#pragma once

#define MASTER_LEFT
#define LAYER_STATE_8BIT

#ifdef OLED_ENABLE
// https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_OLED_ENABLE  // Syncs the on/off state of the OLED between the halves.
#endif

// Fix home row mods not emiting keys on Macos login prompt.
#define TAP_CODE_DELAY 10

// https://docs.qmk.fm/tap_hold#tapping-term
#define TAPPING_TERM 200
// https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM 120
// https://docs.qmk.fm/tap_hold#chordal-hold
#define CHORDAL_HOLD  // Constrains holds to opposite-hand combinations.
// https://docs.qmk.fm/tap_hold#flow-tap
#define FLOW_TAP_TERM 50
// https://docs.qmk.fm/tap_hold#speculative-hold
#define SPECULATIVE_HOLD
#define SPECULATIVE_HOLD_FLOW_TERM 200

#define RETRO_SHIFT 500
// https://docs.qmk.fm/features/auto_shift#auto-shift-repeat-simple-define
#define AUTO_SHIFT_REPEAT
// https://docs.qmk.fm/features/auto_shift#no-auto-shift-special-simple-define
#define NO_AUTO_SHIFT_SPECIAL

// https://docs.qmk.fm/features/caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
