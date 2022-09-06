#include QMK_KEYBOARD_H
#include "dnaq.h"
#include "leader.h"
#include "sendstring_swedish.h"
#include "../callum/swapper.h"

void *leader_git_func(uint16_t keycode) {
    switch (keycode) {
        case KC_A:
            SEND_STRING("git add ");
            return NULL;
        case KC_C:
            SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
            return NULL;
        case KC_P:
            SEND_STRING("git push ");
            return NULL;
        case KC_S:
            SEND_STRING("git status\n");
            return NULL;
        case KC_D:
            SEND_STRING("git diff\n");
            return NULL;
        default:
            return NULL;
    }
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case CU_LEAD:
            SEND_STRING(SS_TAP(X_SLCK) SS_DELAY(10) SS_TAP(X_SLCK) SS_DELAY(40) SS_TAP(X_ENT));
            return NULL;
        case KC_Q:
            SEND_STRING(SS_TAP(X_SLCK) SS_DELAY(10) SS_TAP(X_SLCK) SS_DELAY(40) "1" SS_DELAY(40) SS_TAP(X_ENT));
            return NULL;
        case KC_W:
            SEND_STRING(SS_TAP(X_SLCK) SS_DELAY(10) SS_TAP(X_SLCK) SS_DELAY(40) "2" SS_DELAY(40) SS_TAP(X_ENT));
            return NULL;
        case KC_E:
            SEND_STRING(SS_TAP(X_SLCK) SS_DELAY(10) SS_TAP(X_SLCK) SS_DELAY(40) "3" SS_DELAY(40) SS_TAP(X_ENT));
            return NULL;
        case KC_R:
            SEND_STRING(SS_TAP(X_SLCK) SS_DELAY(10) SS_TAP(X_SLCK) SS_DELAY(40) "4" SS_DELAY(40) SS_TAP(X_ENT));
            return NULL;
        case KC_G:
            return leader_git_func;
        default:
            return NULL;
    }
}

static bool caps_word_enabled = false;
void caps_word_enable(void) {
    caps_word_enabled = true;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_enabled = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void caps_word_toggle(void) {
    if (caps_word_enabled) {
        caps_word_disable();
    } else {
        caps_word_enable();
    }
}

static void process_caps_word(uint16_t keycode, keyrecord_t *record) {
    if (caps_word_enabled) {
        // first strip of the mod taps and layer taps if needed
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                if (record->tap.count == 0)
                    return;
                keycode = keycode & 0xFF;
        }
        // we end caps word on one of the following keypresses
        switch (keycode & 0xFF) {
            case KC_0:
                if (!(get_mods() && MOD_MASK_SHIFT)) {
                    break;
                }
            case KC_RBRC:
            case KC_ESC:
            case KC_SPC:
            case KC_ENT:
            case KC_TAB:
            case KC_DOT:
            case KC_COMM:
                if (record->event.pressed) {
                    caps_word_disable();
                }
        }
    }
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

static bool sw_win_active = false;
static bool sw_app_active = false;

bool process_global_quick_tap(uint16_t keycode, keyrecord_t *record) {
  static uint16_t global_quick_tap_timer = 0;
  if (keycode < QK_MOD_TAP || keycode > QK_MOD_TAP_MAX) {
    global_quick_tap_timer = timer_read();
    return true;
  }
  if (timer_elapsed(global_quick_tap_timer) > TAPPING_TERM) {
    return true;
  }
  if (record->event.pressed) {
    keycode = keycode & 0xFF;
    global_quick_tap_timer = timer_read();
    tap_code(keycode);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);
    update_swapper(&sw_app_active, KC_LGUI, KC_GRV, SW_APP, keycode, record);

    if (!process_global_quick_tap(keycode, record)) {
        return false;
    }

    if (!process_leader(keycode, record)) {
        return false;
    }

    process_caps_word(keycode, record);

    switch (keycode) {
        case CU_CAPS:
            if (record->event.pressed) {
                caps_word_enable();
            }
            return false;
        case CU_LEAD:
            if (record->event.pressed) {
                start_leading();
                
            }
            return false;
        default:
            return true;
    }
}

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);
    return update_tri_layer_state(state, _LW, _RS, _AD);
}
