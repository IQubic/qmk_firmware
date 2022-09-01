#pragma once

enum layers {
    _QW,
    _SM,
    _NM,
    _NV,
    _AD,
};

enum keycodes {
    CU_CAPS = SAFE_RANGE,
    CU_LEAD,

    // swapper keys for cmd-tab and cmd-`
    SW_WIN,
    SW_APP,

    KEYMAP_SAFE_RANGE,
};

#define EU_ARNG RALT(KC_W)
#define EU_ADIA RALT(KC_A)

#define GU_A LGUI_T(KC_A)
#define AL_S LALT_T(KC_S)
#define CT_D LCTL_T(KC_D)
#define SF_F LSFT_T(KC_F)
#define SF_J RSFT_T(KC_J)
#define CT_K RCTL_T(KC_K)
#define AL_L RALT_T(KC_L)

// this keycode needs to be handled in process_record_user
#define GU_ODIA RGUI_T(KC_O)

#define CT_ESC LCTL_T(KC_ESC)

#define NAV_ENT LT(_NV, KC_ENT)
#define SYM_ESC LT(_SM, KC_ESC)
#define SYM_0   LT(_SM, KC_0)
#define NUM_BSP LT(_NM, KC_BSPC)
#define UNDO LCMD(KC_Z)
#define CUT LCMD(KC_X)
#define COPY LCMD(KC_C)
#define PASTE LCMD(KC_V)
#define REDO SCMD(KC_Z)

#define _____________________QWERTY__L0_____________________   KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5
#define _____________________QWERTY__L1_____________________   KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T 
#define _____________________QWERTY__L2_____________________   KC_ESC,   GU_A,   AL_S,   CT_D,   SF_F,   KC_G
#define _____________________QWERTY__L3_____________________  KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B

#define _____________________QWERTY__R0_____________________     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS
#define _____________________QWERTY__R1_____________________     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,EU_ARNG
#define _____________________QWERTY__R2_____________________     KC_H,   SF_J,   CT_K,   AL_L,GU_ODIA,EU_ADIA
#define _____________________QWERTY__R3_____________________     KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT

#define _______________________SYM_L0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________SYM_L1_______________________  _______,  KC_NO,KC_UNDS,KC_LBRC,KC_RBRC,KC_CIRC
#define _______________________SYM_L2_______________________  _______,KC_BSLS,KC_SLSH,KC_LCBR,KC_RCBR,KC_ASTR
#define _______________________SYM_L3_______________________  _______,KC_HASH, KC_DLR,KC_PIPE,KC_TILD, KC_GRV

#define _______________________SYM_R0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________SYM_R1_______________________  KC_EXLM,KC_LABK,KC_RABK, KC_EQL,KC_AMPR,_______
#define _______________________SYM_R2_______________________  KC_QUES,KC_LPRN,KC_RPRN,KC_MINS,KC_COLN,  KC_AT
#define _______________________SYM_R3_______________________  KC_PLUS,KC_PERC,KC_DQUO,KC_QUOT,KC_SCLN,_______

#define _______________________NUM_L0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NUM_L1_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NUM_L2_______________________  _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______
#define _______________________NUM_L3_______________________  _______,_______,_______,_______,_______,_______

#define _______________________NUM_R0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NUM_R1_______________________  _______,   KC_7,   KC_8,   KC_9,_______,_______
#define _______________________NUM_R2_______________________  _______,   KC_4,   KC_5,   KC_6,KC_COLN,_______
#define _______________________NUM_R3_______________________  _______,   KC_1,   KC_2,   KC_3,_______,_______

#define _______________________NAV_L0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NAV_L1_______________________  _______,KC_PGUP,KC_HOME,  KC_UP, KC_END, KC_INS
#define _______________________NAV_L2_______________________  _______,KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_CAPS
#define _______________________NAV_L3_______________________  _______,   UNDO,    CUT,   COPY,  PASTE,   REDO

#define _______________________NAV_R0_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NAV_R1_______________________  _______,_______,_______,_______,_______,_______
#define _______________________NAV_R2_______________________  _______,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______
#define _______________________NAV_R3_______________________  _______,_______,_______,_______,_______,_______

#define _____________________ADJUST__L0_____________________   KC_F11,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5
#define _____________________ADJUST__L1_____________________   KC_F11,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5
#define _____________________ADJUST__L2_____________________   KC_CAPS,RGB_TOG,RGB_SAI,RGB_HUI,RGB_VAI,RGB_MOD
#define _____________________ADJUST__L3_____________________    RESET,_______,RGB_SAD,RGB_HUD,RGB_VAD,RGB_RMOD

#define _____________________ADJUST__R0_____________________    KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F12
#define _____________________ADJUST__R1_____________________    KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F12
#define _____________________ADJUST__R2_____________________  _______,_______,_______,_______,_______,_______
#define _____________________ADJUST__R3_____________________  _______,_______,_______,_______,_______,_______
