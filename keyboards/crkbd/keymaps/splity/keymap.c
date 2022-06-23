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

// HOME ROW MODS
// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RSFT_T(KC_L)
#define HOME_SCLN RALT_T(KC_SCLN)

// Navigation layer aliases
#define NV_DP C(KC_LEFT)     // Desktop previous
#define NV_DN C(KC_RIGHT)    // Desktop next
#define NV_TP SCMD(KC_LBRC)  // Tab previous
#define NV_TN SCMD(KC_RBRC)  // Tab next
#define NV_MTL RCS(KC_LEFT)  // Move tab to the left
#define NV_MTR RCS(KC_RIGHT) // Move tab to the right
#define NV_TGP C(G(KC_LBRC)) // Tab Group previous
#define NV_TGN C(G(KC_RBRC)) // Tab Group next
#define NV_ALF G(KC_SPC)     // Alfred: search
#define NV_ALFH C(G(KC_SPC)) // Alfred: clipboard history
#define NV_HB G(KC_LEFT)     // History: back
#define NV_HF G(KC_RIGHT)    // History: forward

// *INDENT-OFF*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                      KC_H,  HOME_J,  HOME_K,   HOME_L, HOME_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(4),   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,KC_HOME, KC_NUBS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,  HOME_A,  HOME_S,                      KC_BRIU, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_BRID, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       NV_TGP,   NV_HB,   NV_HF,  NV_TGN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |---------+-------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        NV_DP, XXXXXXX, XXXXXXX,   NV_DN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |---------+-------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        NV_TP,  NV_MTL,  NV_MTR,   NV_TN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+---------+-------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX, XXXXXXX,     NV_ALF, NV_ALFH, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
// *INDENT-ON*

// Key overrides.
#ifdef KEY_OVERRIDE_ENABLE
// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));

// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &tilde_esc_override,
    &grave_esc_override,
    NULL
};
#endif // KEY_OVERRIDE_ENABLE

// Combos
#ifdef COMBO_ENABLE
enum combos {
    FJ_ESC,
    DK_COL,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM fj_combo[] = {LCTL_T(KC_F), RCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM dk_combo[] = {LGUI_T(KC_D), RGUI_T(KC_K), COMBO_END};

combo_t key_combos[] = {
    [FJ_ESC] = COMBO(fj_combo, KC_ESC),
    [DK_COL] = COMBO(dk_combo, LSFT(KC_SCLN)),
};
#endif // COMBO_ENABLE

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_NAV 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
    case L_BASE:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case L_LOWER:
        oled_write_ln_P(PSTR("Lower"), false);
        break;
    case L_RAISE:
        oled_write_ln_P(PSTR("Raise"), false);
        break;
    case L_NAV:
        oled_write_ln_P(PSTR("Navigate"), false);
        break;
    case L_ADJUST:
    case L_ADJUST|L_LOWER:
    case L_ADJUST|L_RAISE:
    case L_ADJUST|L_LOWER|L_RAISE:
        oled_write_ln_P(PSTR("Adjust"), false);
        break;
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0
    };
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
