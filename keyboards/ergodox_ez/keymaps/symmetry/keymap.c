#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    ALP,  // alpha, spacebar & backspace
    SYM, // symbols, numbers, enter, tab, escape, layer switches
    FUN, // function keys & layer switches
    NAV, // navigation keys
    MSE, // mouse control
    MDA, // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[ALP] = LAYOUT_ergodox_pretty(

 KC_BSPC, KC_B, KC_P, KC_M, KC_I,   KC_Y,       TT(SYM),  TT(SYM),       KC_Y,   KC_I, KC_M, KC_P, KC_B, KC_BSPC,
    KC_J, KC_V, KC_F, KC_W, KC_E,   KC_C, OSM(MOD_LCTL),  OSM(MOD_LCTL), KC_C,   KC_E, KC_W, KC_F, KC_V, KC_J,
    KC_Q, KC_D, KC_T, KC_N, KC_A,   KC_H,                                KC_H,   KC_A, KC_N, KC_T, KC_D, KC_Q,
    KC_X, KC_Z, KC_S, KC_L, KC_O, KC_SPC, OSM(MOD_LSFT),  OSM(MOD_LSFT), KC_SPC, KC_O, KC_L, KC_S, KC_Z, KC_X,
 TT(FUN), KC_G, KC_K, KC_R, KC_U,                                                KC_U, KC_R, KC_K, KC_G, TT(FUN),
                           OSM(MOD_RALT), OSM(MOD_RGUI),  OSM(MOD_RGUI), OSM(MOD_RALT),
                                          OSM(MOD_RCTL),  OSM(MOD_RCTL),
            OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RSFT),  OSM(MOD_RSFT), OSM(MOD_LGUI), OSM(MOD_LALT)
),

[SYM] = LAYOUT_ergodox_pretty(

 TO(ALP),  KC_GRV,    KC_9,    KC_8,    KC_7, KC_ESC, KC_TRNS,  KC_TRNS, KC_ESC, KC_7,    KC_8,    KC_9,    KC_GRV,  TO(ALP),
 TT(MDA), KC_QUOT,    KC_6,    KC_5,    KC_4, KC_ENT, KC_TRNS,  KC_TRNS, KC_ENT, KC_4,    KC_5,    KC_6,    KC_QUOT, TT(MDA),
 TT(MSE), KC_RBRC,    KC_3,    KC_2,    KC_1, KC_TAB,                    KC_TAB, KC_1,    KC_2,    KC_3,    KC_RBRC, TT(MSE),
 TT(NAV), KC_LBRC, KC_SLSH, KC_SCLN, KC_COMM,   KC_0, KC_TRNS,  KC_TRNS, KC_0,   KC_COMM, KC_SCLN, KC_SLSH, KC_LBRC, TT(NAV),
 KC_TRNS,  KC_EQL, KC_BSLS, KC_MINS,  KC_DOT,                                    KC_DOT,  KC_MINS, KC_BSLS, KC_EQL,  KC_TRNS,
                                             KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

[FUN] = LAYOUT_ergodox_pretty(

 KC_TRNS,  KC_F5,  KC_F4,  KC_F3,  KC_F2,  KC_F1, KC_TRNS,  KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
 KC_TRNS, KC_F10,  KC_F9,  KC_F8,  KC_F7,  KC_F6, KC_TRNS,  KC_TRNS, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
 KC_TRNS, KC_F15, KC_F14, KC_F13, KC_F12, KC_F11,                    KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS,
 KC_TRNS, KC_F20, KC_F19, KC_F18, KC_F17, KC_F16, KC_TRNS,  KC_TRNS, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS,
 KC_TRNS, KC_F24, KC_F23, KC_F22, KC_F21,                                    KC_F21, KC_F22, KC_F23, KC_F24, KC_TRNS,
                                         KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                  KC_TRNS,  KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

[NAV] = LAYOUT_ergodox_pretty(

 KC_TRNS, KC_TRNS, KC_TRNS, KC_FIND, KC_UNDO,  KC_DEL, KC_PSCR,  KC_PSCR, KC_DEL,  KC_UNDO, KC_FIND, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT,   KC_UP,  KC_CUT, KC_TRNS,  KC_TRNS, KC_CUT,  KC_UP,   KC_LEFT, KC_PGUP, KC_HOME, KC_TRNS,
 KC_TRNS,  KC_END, KC_PGDN, KC_RGHT, KC_DOWN, KC_COPY,                    KC_COPY, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,  KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSTE, KC_TRNS,  KC_TRNS, KC_PSTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                       KC_TRNS,  KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

[MSE] = LAYOUT_ergodox_pretty(

 KC_TRNS, KC_ACL2, KC_ACL1, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS,
 KC_TRNS, KC_WH_L, KC_WH_U, KC_MS_L, KC_MS_U, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_MS_L, KC_WH_U, KC_WH_L, KC_TRNS,
 KC_TRNS, KC_WH_R, KC_WH_D, KC_MS_R, KC_MS_D, KC_TRNS,                    KC_TRNS, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R, KC_TRNS,
 KC_TRNS, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_TRNS,
 KC_TRNS, KC_BTN8, KC_BTN7, KC_BTN6, KC_BTN5,                                      KC_BTN5, KC_BTN6, KC_BTN7, KC_BTN8, KC_TRNS,
                                              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                       KC_TRNS,  KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

[MDA] = LAYOUT_ergodox_pretty(

 KC_TRNS,  KC_PWR,  KC_APP, KC_WBAK, KC_MPRV, KC_VOLU, KC_MUTE,  KC_MUTE, KC_VOLU, KC_MPRV, KC_WBAK, KC_APP,  KC_PWR,  KC_TRNS,
 KC_TRNS, KC_SLEP, KC_WFAV, KC_WFWD, KC_MNXT, KC_VOLD, KC_TRNS,  KC_TRNS, KC_VOLD, KC_MNXT, KC_WFWD, KC_WFAV, KC_SLEP, KC_TRNS,
 KC_TRNS, KC_WAKE, KC_WSTP, KC_WHOM, KC_MPLY, KC_BRIU,                    KC_BRIU, KC_MPLY, KC_WHOM, KC_WSTP, KC_WAKE, KC_TRNS,
 KC_TRNS, KC_CALC, KC_MAIL, KC_WSCH, KC_MRWD, KC_BRID, KC_TRNS,  KC_TRNS, KC_BRID, KC_MRWD, KC_WSCH, KC_MAIL, KC_CALC, KC_TRNS,
 KC_TRNS, KC_MYCM, KC_MSEL, KC_WREF, KC_MFFD,                                      KC_MFFD, KC_WREF, KC_MSEL, KC_MYCM, KC_TRNS,
                                              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                       KC_TRNS,  KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),


};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
