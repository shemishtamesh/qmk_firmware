/* Copyright 2021 StefanGrindelwald
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "lib/dynamic_sleep_queue.h"


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BSE,  // base layer: default, for general use. includes qwerty layout, media controls, modifiers, dynamic macro controls.
    _BSEM, // base layer mirror: mirrors base layer.
    _NUM,  // number layer: includes numbers and symbols. also has modifiers.
    _NUMM, // number layer mirror: mirrors number layer.
    _GMG,  // gaming layer: left hand has "normal keyboard" (qwerty + num row + pinkey modifiers etc.), right hand has arrows, mouse keys, and modifiers arranged in a way more comfortable for gaming than navigation.
    _GMGM, // gaming layer mirror: mirros gaming layer, the right hand "normal keyboard" is not inverted, nor are the arrows and mouse control for the left hand.
    _NVG,  // navigation layer: includes arrows, mouse controls (including scrolling and speed settings), pgup + pgdown, home + end, and modifiers.
    _NVGM, // navigation layer mirror: mirrors navigation layer, but keeping directions (essentially moving the navigation keys to the left hand).
    _LTG,  // lighting settings layer: includes options for lighting, and also the KC_SLEP key code.
    _RST,  // reset layer: for flashing firmware.
};

enum custom_keycodes {
    KM_DSLP = SAFE_RANGE,  // sleep for an amount of time equivelent to the amount of time the key has been pressed for, only active when recording a dynamic macro
};

enum combos {
    BRIGHTNESS_MEDIA_PREV,
    VOLUME_MEDIA_NEXT,
};
const uint16_t PROGMEM media_prev_combo[] = {KC_BRID, KC_BRIU, COMBO_END};
const uint16_t PROGMEM media_next_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [BRIGHTNESS_MEDIA_PREV] = COMBO(media_prev_combo, KC_MPRV),
    [VOLUME_MEDIA_NEXT] = COMBO(media_next_combo, KC_MNXT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT(
        KC_MUTE,   KC_VOLD,  KC_VOLU, KC_MPLY, KC_BRID, KC_BRIU,                                          KM_DSLP, DM_PLY2, DM_PLY1, DM_REC2, DM_REC1,  DM_RSTP,
        KC_GRV,    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
        KC_ESC,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        TO(_BSEM), KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT,                                                            KC_UNDS, KC_TAB,  KC_RALT, KC_RCTL, TO(_BSEM),
                                                                  MO(_NVG), MO(_LTG), MO(_LTG), TO(_GMG),
                                                                            KC_RALT,  KC_MEH,
                                                        MO(_NUM), KC_BSPC,  KC_DEL,   KC_HYPR,  KC_ENT,   KC_SPC
    ),
    [_BSEM] = LAYOUT(
        DM_RSTP,  DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, KM_DSLP,                                         KC_BRIU,  KC_BRID, KC_MPLY, KC_VOLU, KC_VOLD, KC_MUTE,
        KC_BSLS,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                                            KC_T,     KC_R,    KC_E,    KC_W,    KC_Q,    KC_GRV,
        KC_QUOT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                                            KC_G,     KC_F,    KC_D,    KC_S,    KC_A,    KC_ESC,
        KC_LSFT,  KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,                                            KC_B,     KC_V,    KC_C,    KC_X,    KC_Z,    KC_RSFT,
        TO(_BSE), KC_NO,   KC_LALT, KC_TAB,  KC_UNDS,                                                            KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, TO(_BSE),
                                                               TO(_GMGM), KC_LCTL, KC_NO,   MO(_NVGM),
                                                                          KC_MEH,  KC_LALT,
                                                      KC_SPC,  KC_ENT,    KC_HYPR, KC_DEL,  KC_BSPC,   MO(_NUMM)
    ),
    [_NUM] = LAYOUT(
        KC_F10,  KC_F11,  KC_F12,  KC_QUES, KC_GRV,  TG(_NUM),                                   KC_LT,   KC_WFAV, KC_SLSH, KC_ASTR, KC_COMM, KC_GT,
        KC_F7,   KC_F8,   KC_F9,   KC_AMPR, KC_ASTR, KC_GRV,                                     KC_LPRN, KC_7,    KC_8,    KC_9,    KC_PPLS, KC_RPRN,
        KC_F4,   KC_F5,   KC_F6,   KC_DLR,  KC_PERC, KC_CIRC,                                    KC_LCBR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_RCBR,
        KC_F1,   KC_F2,   KC_F3,   KC_EXLM, KC_AT,   KC_HASH,                                    KC_LBRC, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_RBRC,
        KC_TILD, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,                                                      KC_0,    KC_DOT,  KC_COMM, KC_ENT,  KC_TAB,
                                                               KC_NO, KC_NO,    KC_LALT, KC_RSFT,
                                                                      KC_NO,    KC_RALT,
                                                     MO(_NUM), KC_NO, KC_NO,    KC_RCTL, KC_BSPC, KC_SPC
    ),
    [_NUMM] = LAYOUT(
        KC_LT,   KC_COMM, KC_ASTR, KC_SLSH, KC_WFAV, KC_GT,                                      TG(_NUMM), KC_TILD, KC_QUES, KC_F12,  KC_F11,  KC_F10,
        KC_LPRN, KC_PPLS, KC_9,    KC_8,    KC_7,    KC_RPRN,                                    KC_GRV,    KC_ASTR, KC_AMPR, KC_F9,   KC_F8,   KC_F7,
        KC_LCBR, KC_MINS, KC_6,    KC_5,    KC_4,    KC_RCBR,                                    KC_CIRC,   KC_PERC, KC_DLR,  KC_F6,   KC_F5,   KC_F4,
        KC_LBRC, KC_EQL,  KC_3,    KC_2,    KC_1,    KC_RBRC,                                    KC_HASH,   KC_AT,   KC_EXLM, KC_F3,   KC_F2,   KC_F1,
        KC_TAB,  KC_ENT,  KC_COMM, KC_DOT,  KC_0,                                                           KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TILD,
                                                              KC_LSFT, KC_LALT,    KC_NO, KC_NO,
                                                                       KC_RALT,    KC_NO,
                                                     KC_SPC,  KC_BSPC, KC_LCTL,    KC_NO, KC_NO, MO(_NUMM)
    ),
    [_GMG] = LAYOUT(
        KC_GRV,  KC_1,  KC_2,  KC_3,    KC_4,   KC_5,                                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_BSE),
        KC_ESC,  KC_Q,  KC_W,  KC_E,    KC_R,   KC_T,                                           KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_RSFT, KC_NO,
        KC_TAB,  KC_A,  KC_S,  KC_D,    KC_F,   KC_G,                                           KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_RCTL, KC_NO,
        KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_V,   KC_B,                                           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RALT, KC_NO,
        KC_LCTL, KC_NO, KC_NO, KC_LALT, KC_SPC,                                                          KC_BTN1, KC_BTN3, KC_NO,   KC_NO,   KC_NO,
                                                          KC_NO, TO(_BSE),    TO(_BSE), KC_NO,
                                                                 KC_NO,       KC_NO,
                                                 KC_HYPR, KC_NO, KC_NO,       KC_NO,    KC_ENT, KC_SPC
    ),
    [_GMGM] = LAYOUT(
        TO(_BSE), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                   KC_5,  KC_4,   KC_3,  KC_2,  KC_1,    KC_GRV,
        KC_NO,    KC_RSFT, KC_NO,   KC_UP,   KC_NO,   KC_NO,                                   KC_T,  KC_R,   KC_E,  KC_W,  KC_Q,    KC_ESC,
        KC_NO,    KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                                   KC_G,  KC_F,   KC_D,  KC_S,  KC_A,    KC_TAB,
        KC_NO,    KC_LALT, KC_WH_U, KC_WH_D, KC_WH_L, KC_WH_R,                                 KC_B,  KC_V,   KC_C,  KC_X,  KC_Z,    KC_RSFT,
        KC_NO,    KC_NO,   KC_NO,   KC_BTN3, KC_BTN1,                                                 KC_SPC, KC_NO, KC_NO, KC_TRNS, KC_RCTL,
                                                               KC_NO,  TO(_BSEM),    TO(_BSE), KC_NO,
                                                                       KC_NO,        KC_NO,
                                                      KC_SPC,  KC_ENT, KC_NO,        KC_NO,    KC_NO, KC_HYPR
    ),
    [_NVG] = LAYOUT(
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO,                                           KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   MEH(KC_NO), HYPR(KC_NO),                                     KC_ACL2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL,    KC_LSFT,                                         KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO,                                           KC_ACL0, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,                                                                KC_BTN2, KC_BTN5, KC_BTN4, KC_APP,  KC_NO,
                                                                 MO(_NVG), KC_NO,    KC_NO, KC_NO,
                                                                           KC_NO,    KC_NO,
                                                    KC_NO,       KC_NO,    KC_NO,    KC_NO, KC_BTN1, KC_BTN3
    ),
    [_NVGM] = LAYOUT(
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,                                        KC_NO,       KC_NO,      KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2,                                      HYPR(KC_NO), MEH(KC_NO), KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,                                      KC_RSFT,     KC_RCTL,    KC_RALT, KC_RGUI, KC_NO, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ACL0,                                      KC_NO,       KC_NO,      KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_APP,  KC_BTN4, KC_BTN5, KC_BTN2,                                                            KC_NO,      KC_NO,   KC_NO,   KC_NO, KC_NO,
                                                            KC_NO,   KC_NO,    KC_NO, MO(_NVGM),
                                                                     KC_NO,    KC_NO,
                                                   KC_BTN3, KC_BTN1, KC_NO,    KC_NO, KC_NO,     KC_NO
    ),
    [_LTG] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        RGB_SAI, RGB_VAI, RGB_MOD,  KC_TRNS, KC_SLEP, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        RGB_SAD, RGB_VAD, RGB_RMOD, KC_TRNS, RGB_TOG, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
        MO(_RST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, MO(_RST),
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                          KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                                                               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
                                                                        KC_TRNS,    RGB_HUI,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,    RGB_HUD, KC_TRNS, KC_TRNS
    ),
    [_RST] = LAYOUT(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,                         KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,                         KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   DB_TOGG, EE_CLR, QK_BOOT, KC_NO,                         KC_NO, QK_BOOT, EE_CLR, DB_TOGG, KC_NO,   KC_NO,
        MO(_RST), KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,                         KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   MO(_RST),
        KC_NO,    KC_TRNS, KC_NO,   KC_NO,  KC_NO,                                         KC_NO,   KC_NO,  KC_NO,   KC_TRNS, KC_NO,
                                                            KC_NO, KC_NO,    KC_NO, KC_NO,
                                                                   KC_NO,    KC_NO,
                                                     KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    ),
};

static bool recording_macro = false;
static bool playing_macro = false;
static uint16_t dynamic_sleep_timer = 0;
static DynamicSleepQueue dynamic_sleep_queue;

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);

    dynamic_sleep_queue.front = 0;
    dynamic_sleep_queue.end = 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KM_DSLP:
            if (record->event.pressed && recording_macro) {
                // when keycode KM_DSLP is pressed and a dynamic macro is being recorded
                dynamic_sleep_timer = timer_read();
            } else if (recording_macro) {
                // when keycode KM_DSLP is released and a dynamic macro is being recorded
                switch (dynamic_sleep_enqueue(&dynamic_sleep_queue, timer_elapsed(dynamic_sleep_timer))) {
                    case 1:
                        rgblight_sethsv_range(0, 255, 255, 2, 4);
                        rgblight_sethsv_range(0, 255, 255, 16, 19);
                        break;
                }
            } else if (record->event.pressed && playing_macro) {
                // when keycode KM_DSLP is pressed and a dynamic macro is being played
                uint16_t time_to_wait;
                dynamic_sleep_dequeue(&dynamic_sleep_queue, &time_to_wait);  // the function could fail, but used this way the user can never cause that (hopefully)
                wait_ms(time_to_wait);
            }
            break;
    }
    return true;
};

void dynamic_macro_record_start_user(void) {
    recording_macro = true;
    layer_state_set_user(layer_state);
    dynamic_sleep_empty(&dynamic_sleep_queue);
}

void dynamic_macro_record_end_user(int8_t direction) {
    recording_macro = false;
    layer_state_set_user(layer_state);
}

void dynamic_macro_play_start_user(int8_t direction) {
    playing_macro = true;
    layer_state_set_user(layer_state);
}

void dynamic_macro_play_user(int8_t direction) {
    dynamic_sleep_reset(&dynamic_sleep_queue);
    playing_macro = false;
    layer_state_set_user(layer_state);
}

// TODO: remove this definition:
void rgblight_sethsv_master(uint8_t hue, uint8_t sat, uint8_t val) {
    // this is the definition of rgblight_sethsv_master from the source, for some reason this function isn't declared with the current config.h so this definition is here as a temporary way of making this work
    rgblight_sethsv_range(hue, sat, val, 0, (uint8_t)RGBLED_NUM / 2);
}

layer_state_t layer_state_set_user(layer_state_t state) {
   switch (get_highest_layer(state)) {
        case _BSE:
            rgblight_sethsv(0, 0, 255);
            rgblight_sethsv_master(0, 0, 100);
            break;
        case _BSEM:
            rgblight_sethsv(0, 0, 100);
            rgblight_sethsv_master(0, 0, 255);
            break;
        case _NUM:
            rgblight_sethsv(42, 255, 255);
            rgblight_sethsv_master(42, 177, 255);
            break;
        case _NUMM:
            rgblight_sethsv(42, 177, 255);
            rgblight_sethsv_master(42, 255, 255);
            break;
        case _GMG:
            rgblight_sethsv(85, 255, 255);
            rgblight_sethsv_master(85, 177, 255);
            break;
        case _GMGM:
            rgblight_sethsv(85, 177, 255);
            rgblight_sethsv_master(85, 255, 255);
            break;
        case _NVG:
            rgblight_sethsv(170, 255, 255);
            rgblight_sethsv_master(170, 177, 255);
            break;
        case _NVGM:
            rgblight_sethsv(170, 177, 255);
            rgblight_sethsv_master(170, 255, 255);
            break;
        case _LTG:
            rgblight_sethsv(212, 255, 255);
            break;
        case _RST:
            rgblight_sethsv(0, 255, 255);
            break;
        default:  // for any other layers, or the default layer
            rgblight_sethsv(0, 50, 50);
            rgblight_sethsv_master(0, 50, 50);
            break;
    }
    if (recording_macro) {
        rgblight_sethsv_range(212, 255, 255, 0, 2);
        rgblight_sethsv_range(212, 255, 255, 12, 15);
    }

    if (playing_macro) {
        rgblight_sethsv_range(0, 255, 255, 0, 2);
        rgblight_sethsv_range(0, 255, 255, 12, 15);
    }

  return state;
}

