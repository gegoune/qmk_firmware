#include QMK_KEYBOARD_H
#include <stdio.h>

// Home row mods
// Left-hand
#define HOME_A LALT_T(KC_A)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_G LT(_NUMPAD, KC_G)
#define HOME_Z RALT_T(KC_Z)
// Right-hand
#define HOME_J RCTL_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RSFT_T(KC_L)
#define HOME_SCLN RALT_T(KC_SCLN)
#define HOME_SLSH LALT_T(KC_SLSH)

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
#define NV_ALFH S(G(KC_SPC)) // Alfred: clipboard history
#define NV_HB G(KC_LEFT)     // History: back
#define NV_HF G(KC_RIGHT)    // History: forward

// Extra layer aliases
// LAG: Hold Left Alt and Left GUI and press <kc>
// MEH: Hold Left Control, Shift and Alt and press <kc>
#define PA_L LAG(KC_LEFT)  // Pane (activate) left
#define PA_D LAG(KC_DOWN)  // Pane (activate) down
#define PA_U LAG(KC_UP)    // Pane (activate) up
#define PA_R LAG(KC_RIGHT) // Pane (activate) right
#define PR_L MEH(KC_LEFT)  // Pane (resize) left
#define PR_D MEH(KC_DOWN)  // Pane (resize) down
#define PR_U MEH(KC_UP)    // Pane (resize) up
#define PR_R MEH(KC_RIGHT) // Pane (resize) right
#define MO_SD HYPR(KC_SPC) // MacOS Show Desktop
#define MO_MC HYPR(KC_ENT) // MacOS Mission Control

// Neovim
#define NWIN LCTL(KC_W) // Send C-w

#define GBP LSFT(KC_NUBS) // British Pound symbol

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
    _NUMPAD,
    _EXTRA
};

// Custom keys
enum custom_keycodes {
    CK_ENT = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CK_ENT:
        // Exit the numpad layer after sending Enter.
        if (record->event.pressed) {
            layer_off(_NUMPAD);
            tap_code(KC_ENT);
        }
        return false;
    }
    return true;
}

// *INDENT-OFF*
#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );
#endif // CHORDAL_HOLD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬────────┬────────┬──────────┬────────────┬────────┐   ┌─────┬────────────┬────────┬────────┬───────────┬─────────────┐
//    │ MO(_EXTRA) │   q    │   w    │    e     │     r      │   t    │   │  y  │     u      │   i    │   o    │     p     │ TG(_NUMPAD) │
//    ├────────────┼────────┼────────┼──────────┼────────────┼────────┤   ├─────┼────────────┼────────┼────────┼───────────┼─────────────┤
//    │    tab     │ HOME_A │ HOME_S │  HOME_D  │   HOME_F   │ HOME_G │   │  h  │   HOME_J   │ HOME_K │ HOME_L │ HOME_SCLN │      '      │
//    ├────────────┼────────┼────────┼──────────┼────────────┼────────┤   ├─────┼────────────┼────────┼────────┼───────────┼─────────────┤
//    │    NVIM    │ HOME_Z │   x    │    c     │     v      │   b    │   │  n  │     m      │   ,    │   .    │ HOME_SLSH │   CW_TOGG   │
//    └────────────┴────────┴────────┼──────────┼────────────┼────────┤   ├─────┼────────────┼────────┼────────┴───────────┴─────────────┘
//                                   │ MO(_NAV) │ MO(_LOWER) │  spc   │   │ ent │ MO(_RAISE) │  bspc  │
//                                   └──────────┴────────────┴────────┘   └─────┴────────────┴────────┘
[_BASE] = LAYOUT_split_3x6_3(
  MO(_EXTRA) , KC_Q   , KC_W   , KC_E     , KC_R       , KC_T   ,     KC_Y   , KC_U       , KC_I    , KC_O   , KC_P      , TG(_NUMPAD),
  KC_TAB     , HOME_A , HOME_S , HOME_D   , HOME_F     , HOME_G ,     KC_H   , HOME_J     , HOME_K  , HOME_L , HOME_SCLN , KC_QUOT    ,
  NVIM       , HOME_Z , KC_X   , KC_C     , KC_V       , KC_B   ,     KC_N   , KC_M       , KC_COMM , KC_DOT , HOME_SLSH , CW_TOGG    ,
                                 MO(_NAV) , MO(_LOWER) , KC_SPC ,     KC_ENT , MO(_RAISE) , KC_BSPC
),

//    ┌─────┬─────┬─────┬──────┬─────┬─────┐   ┌──────┬─────────────┬──────┬──────┬──────┬──────┐
//    │     │  4  │  3  │  2   │  1  │  5  │   │  0   │      6      │  7   │  8   │  9   │  no  │
//    ├─────┼─────┼─────┼──────┼─────┼─────┤   ├──────┼─────────────┼──────┼──────┼──────┼──────┤
//    │     │     │     │      │     │ no  │   │ left │    down     │  up  │ rght │ home │ iso\ │
//    ├─────┼─────┼─────┼──────┼─────┼─────┤   ├──────┼─────────────┼──────┼──────┼──────┼──────┤
//    │     │ no  │ no  │  no  │ no  │ no  │   │  no  │    pgdn     │ pgup │      │ end  │  no  │
//    └─────┴─────┴─────┼──────┼─────┼─────┤   ├──────┼─────────────┼──────┼──────┴──────┴──────┘
//                      │ lgui │     │ spc │   │ ent  │ MO(_ADJUST) │ del  │
//                      └──────┴─────┴─────┘   └──────┴─────────────┴──────┘
[_LOWER] = LAYOUT_split_3x6_3(
  _______ , KC_4    , KC_3    , KC_2    , KC_1    , KC_5    ,     KC_0    , KC_6        , KC_7    , KC_8     , KC_9    , XXXXXXX,
  _______ , _______ , _______ , _______ , _______ , XXXXXXX ,     KC_LEFT , KC_DOWN     , KC_UP   , KC_RIGHT , KC_HOME , KC_NUBS,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_PGDN     , KC_PGUP , _______  , KC_END  , XXXXXXX,
                                KC_LGUI , _______ , KC_SPC  ,     KC_ENT  , MO(_ADJUST) , KC_DEL
),

//    ┌─────┬─────┬─────┬────┬─────────────┬─────┐   ┌─────┬─────┬─────┬────┬────┬────┐
//    │     │  !  │  @  │ #  │      $      │  %  │   │  ^  │  &  │  *  │ no │ no │ no │
//    ├─────┼─────┼─────┼────┼─────────────┼─────┤   ├─────┼─────┼─────┼────┼────┼────┤
//    │     │     │     │ (  │      )      │ GBP │   │  -  │  =  │  [  │ ]  │ \  │ `  │
//    ├─────┼─────┼─────┼────┼─────────────┼─────┤   ├─────┼─────┼─────┼────┼────┼────┤
//    │     │ no  │ no  │ no │     no      │ no  │   │  _  │  +  │  {  │ }  │ |  │ ~  │
//    └─────┴─────┴─────┼────┼─────────────┼─────┤   ├─────┼─────┼─────┼────┴────┴────┘
//                      │ no │ MO(_ADJUST) │ spc │   │ ent │     │     │
//                      └────┴─────────────┴─────┘   └─────┴─────┴─────┘
[_RAISE] = LAYOUT_split_3x6_3(
  _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR      , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , XXXXXXX , XXXXXXX , XXXXXXX,
  _______ , _______ , _______ , KC_LPRN , KC_RPRN     , GBP     ,     KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX ,     KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                XXXXXXX , MO(_ADJUST) , KC_SPC  ,     KC_ENT  , _______ , _______
),

//    ┌─────────┬────┬────┬──────┬─────┬─────┐   ┌──────┬──────┬──────┬──────┬────┬───────────┐
//    │ QK_BOOT │ no │ no │  no  │ no  │ no  │   │ mute │ mprv │ mply │ mnxt │ no │ QK_REBOOT │
//    ├─────────┼────┼────┼──────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼────┼───────────┤
//    │   no    │ no │ no │  no  │ no  │ no  │   │ bRIU │ volu │  no  │  no  │ no │    no     │
//    ├─────────┼────┼────┼──────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼────┼───────────┤
//    │   no    │ no │ no │  no  │ no  │ no  │   │ bRID │ vold │  no  │  no  │ no │    no     │
//    └─────────┴────┴────┼──────┼─────┼─────┤   ├──────┼──────┼──────┼──────┴────┴───────────┘
//                        │ lgui │     │ spc │   │ ent  │      │      │
//                        └──────┴─────┴─────┘   └──────┴──────┴──────┘
[_ADJUST] = LAYOUT_split_3x6_3(
  QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_MUTE , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , QK_REBOOT,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_BRIU , KC_VOLU , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_BRID , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,
                                KC_LGUI , _______ , KC_SPC  ,     KC_ENT  , _______ , _______
),

//    ┌────┬────┬────┬──────┬────┬────┐   ┌─────────┬────────┬────────┬────────┬────┬────┐
//    │ no │ no │ no │  no  │ no │ no │   │ NV_TGP  │ NV_HB  │ NV_HF  │ NV_TGN │ no │ no │
//    ├────┼────┼────┼──────┼────┼────┤   ├─────────┼────────┼────────┼────────┼────┼────┤
//    │ no │ no │ no │  no  │ no │ no │   │  NV_DP  │   no   │   no   │ NV_DN  │ no │ no │
//    ├────┼────┼────┼──────┼────┼────┤   ├─────────┼────────┼────────┼────────┼────┼────┤
//    │ no │ no │ no │  no  │ no │ no │   │  NV_TP  │ NV_MTL │ NV_MTR │ NV_TN  │ no │ no │
//    └────┴────┴────┼──────┼────┼────┤   ├─────────┼────────┼────────┼────────┴────┴────┘
//                   │ lgui │ no │ no │   │ NV_ALFH │ NV_ALF │  del   │
//                   └──────┴────┴────┘   └─────────┴────────┴────────┘
[_NAV] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     NV_TGP  , NV_HB   , NV_HF   , NV_TGN , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     NV_DP   , XXXXXXX , XXXXXXX , NV_DN  , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     NV_TP   , NV_MTL  , NV_MTR  , NV_TN  , XXXXXXX , XXXXXXX,
                                KC_LGUI , XXXXXXX , XXXXXXX ,     NV_ALFH , NV_ALF  , KC_DEL
),

//    ┌─────┬────┬──────┬──────┬────┬─────┐   ┌────────┬──────┬──────┬──────┬─────┬─────┐
//    │  (  │ )  │ kp_/ │ kp_* │ no │ no  │   │   no   │ kp_7 │ kp_8 │ kp_9 │ no  │     │
//    ├─────┼────┼──────┼──────┼────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//    │     │ no │ kp_- │ kp_+ │ =  │ no  │   │   no   │ kp_4 │ kp_5 │ kp_6 │  .  │ no  │
//    ├─────┼────┼──────┼──────┼────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//    │ no  │ no │  ,   │  .   │ no │ no  │   │   no   │ kp_1 │ kp_2 │ kp_3 │     │ no  │
//    └─────┴────┴──────┼──────┼────┼─────┤   ├────────┼──────┼──────┼──────┴─────┴─────┘
//                      │  no  │ no │     │   │ CK_ENT │ kp_0 │      │
//                      └──────┴────┴─────┘   └────────┴──────┴──────┘
[_NUMPAD] = LAYOUT_split_3x6_3(
  KC_LPRN , KC_RPRN , KC_PSLS , KC_PAST , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_KP_7 , KC_KP_8 , KC_KP_9 , XXXXXXX , _______,
  _______ , XXXXXXX , KC_PMNS , KC_PPLS , KC_EQL  , XXXXXXX ,     XXXXXXX , KC_KP_4 , KC_KP_5 , KC_KP_6 , KC_DOT  , XXXXXXX,
  XXXXXXX , XXXXXXX , KC_COMM , KC_DOT  , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_KP_1 , KC_KP_2 , KC_KP_3 , _______ , XXXXXXX,
                                XXXXXXX , XXXXXXX , _______ ,     CK_ENT  , KC_KP_0 , _______
),

//    ┌────┬─────┬─────┬─────┬─────┬─────┐   ┌───────┬───────┬──────┬──────┬────┬────┐
//    │ no │ f1  │ f2  │ f3  │ f4  │ f5  │   │ PR_L  │ PR_D  │ PR_U │ PR_R │ no │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────┤   ├───────┼───────┼──────┼──────┼────┼────┤
//    │ no │ f6  │ f7  │ f8  │ f9  │ f10 │   │ PA_L  │ PA_D  │ PA_U │ PA_R │ no │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────┤   ├───────┼───────┼──────┼──────┼────┼────┤
//    │ no │ f11 │ f12 │ f13 │ f14 │ f15 │   │  no   │  no   │  no  │  no  │ no │ no │
//    └────┴─────┴─────┼─────┼─────┼─────┤   ├───────┼───────┼──────┼──────┴────┴────┘
//                     │ no  │ no  │ no  │   │ MO_MC │ MO_SD │  no  │
//                     └─────┴─────┴─────┘   └───────┴───────┴──────┘
[_EXTRA] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_F1  , KC_F2  , KC_F3   , KC_F4   , KC_F5   ,     PR_L    , PR_D    , PR_U    , PR_R    , XXXXXXX , XXXXXXX,
  XXXXXXX , KC_F6  , KC_F7  , KC_F8   , KC_F9   , KC_F10  ,     PA_L    , PA_D    , PA_U    , PA_R    , XXXXXXX , XXXXXXX,
  XXXXXXX , KC_F11 , KC_F12 , KC_F13  , KC_F14  , KC_F15  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                              XXXXXXX , XXXXXXX , XXXXXXX ,     MO_MC   , MO_SD   , XXXXXXX
)
};
// *INDENT-ON*

#ifdef SPECULATIVE_HOLD
bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) { // These keys may be speculatively held.
    case HOME_A:
    case HOME_S:
    case HOME_D:
    case HOME_F:
        return true;
    }
    return false; // Disable otherwise.
}
#endif // SPECULATIVE_HOLD

// Combos
#ifdef COMBO_ENABLE
enum combos {
    FJ_ESC,
    DK_COL,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM fj_combo[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {HOME_D, HOME_K, COMBO_END};

combo_t key_combos[] = {
    [FJ_ESC] = COMBO(fj_combo, KC_ESC),
    [DK_COL] = COMBO(dk_combo, KC_COLN),
};
#endif // COMBO_ENABLE

#ifdef OLED_ENABLE
// Provided (weakly) by keyboards/crkbd/crkbd.c; declare it so we can call it.
void oled_render_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_ln_P(PSTR("BASE"), false);
        break;
    case _LOWER:
        oled_write_ln_P(PSTR("LOWE"), false);
        break;
    case _RAISE:
        oled_write_ln_P(PSTR("HIGH"), false);
        break;
    case _ADJUST:
        oled_write_ln_P(PSTR("ADJT"), false);
        break;
    case _NAV:
        oled_write_ln_P(PSTR("NAVI"), false);
        break;
    case _NUMPAD:
        oled_write_ln_P(PSTR("NUME"), false);
        break;
    case _EXTRA:
        oled_write_ln_P(PSTR("EXTR"), false);
        break;
    }
}

static bool caps_word_active = false;
void caps_word_set_user(bool active) {
    caps_word_active = active;
}

void oled_render_caps_word(void) {
    if (caps_word_active) {
        oled_set_cursor(0, oled_max_lines() - 1);
        oled_write_P(PSTR("CAPS"), true);
    }
}

void oled_render_mods(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();

    char buf[] = "ASGC";

    if (!(mods & MOD_MASK_ALT))   buf[0] = '.';
    if (!(mods & MOD_MASK_SHIFT)) buf[1] = '.';
    if (!(mods & MOD_MASK_GUI))   buf[2] = '.';
    if (!(mods & MOD_MASK_CTRL))  buf[3] = '.';

    oled_write_ln(buf, false);
}

bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_mods();
        oled_render_caps_word();
    } else {
        oled_render_logo();
    }
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();

    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("FIRM"), true);
        } else {
            oled_write_P(PSTR("BOOT"), true);
        }
    }

    oled_render_dirty(true);

    oled_scroll_set_area(0, 7);   // whole display (for 128x64)
    oled_scroll_set_speed(3);
    oled_scroll_left();
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return true;
}
#endif // OLED_ENABLE

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_MOD_TAP(keycode);
}
