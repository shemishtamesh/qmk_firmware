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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BSE,  // base layer: default, for general use. includes qwerty layout, media controls, modifiers, dynamic macro controls.
    _NUM,  // number layer: includes numbers and symbols. also has modifiers.
    _NVG,  // navigation layer: includes arrows, mouse controls (including scrolling and speed settings), pgup + pgdown, home + end, and modifiers.
    _GMG,  // gaming layer: left hand has "normal keyboard" (qwerty + num row + pinkey modifiers etc.), right hand has arrows, mouse keys, and modifiers arranged in a way more comfortable for gaming than navigation.
    _SET,  // settings layer: includes options for lighting, and also the KC_SLEP key code.
    _RST,  // reset layer: for flashing firmware.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT(
        KC_MUTE,   KC_VOLD,  KC_VOLU, KC_MPLY, KC_BRID, KC_BRIU,                                         KC_HYPR, DM_PLY2, DM_PLY1, DM_REC2, DM_REC1,  DM_RSTP,
        KC_GRV,    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
        KC_ESC,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        SH_MON,     KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT,                                                           KC_UNDS, KC_TAB,  KC_RALT, KC_RCTL, SH_MON,
                                                                  KC_DEL,  MO(_SET), MO(_SET), TO(_GMG),
                                                                           KC_RALT,  KC_MEH,
                                                        MO(_NUM), KC_BSPC, MO(_NVG), KC_WREF,  KC_ENT,   KC_SPC
    ),
    [_NUM] = LAYOUT(
        KC_F10,  KC_F11,  KC_F12,  LCTL(KC_MINS), LCTL(KC_EQL), KC_WSTP,                                    KC_LT,   KC_WFAV, KC_SLSH, KC_ASTR, KC_COMM, KC_GT,
        KC_F7,   KC_F8,   KC_F9,   KC_AMPR,       KC_ASTR,      KC_GRV,                                     KC_LPRN, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_RPRN,
        KC_F4,   KC_F5,   KC_F6,   KC_DLR,        KC_PERC,      KC_CIRC,                                    KC_LCBR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_RCBR,
        KC_F1,   KC_F2,   KC_F3,   KC_EXLM,       KC_AT,        KC_HASH,                                    KC_LBRC, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_RBRC,
        KC_TILD, KC_LGUI, KC_LALT, KC_LCTL,       KC_LSFT,                                                           KC_0,    KC_DOT,  KC_COMM, KC_ENT,  KC_TAB,
                                                                         KC_NO, KC_NO,    KC_LALT, KC_RSFT,
                                                                                KC_NO,    KC_RALT,
                                                                KC_TRNS, KC_NO, KC_NO,    KC_RCTL, KC_BSPC, KC_SPC
    ),
    [_NVG] = LAYOUT(
        KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO,       KC_NO,                                    KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   MEH(KC_NO), HYPR(KC_NO), KC_ACL2,                                  KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL,    KC_LSFT,     KC_ACL1,                                  KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_PGUP,
        KC_NO, KC_NO,   KC_ACL0, KC_ACL1,    KC_ACL2,     KC_ACL0,                                  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
        KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO,                                                          KC_BTN2, KC_BTN5, KC_BTN4, KC_APP,  KC_NO,
                                                                 KC_NO, KC_NO,    KC_NO,   KC_NO,
                                                                        KC_NO,    KC_BTN7,
                                                          KC_NO, KC_NO, KC_TRNS,  KC_BTN6, KC_BTN1, KC_BTN3
    ),
    [_GMG] = LAYOUT(
        KC_GRV,  KC_1,  KC_2,  KC_3,    KC_4,   KC_5,                                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_BSE),
        KC_ESC,  KC_Q,  KC_W,  KC_E,    KC_R,   KC_T,                                             KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_RSFT, KC_NO,
        KC_TAB,  KC_A,  KC_S,  KC_D,    KC_F,   KC_G,                                             KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_RCTL, KC_NO,
        KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_V,   KC_B,                                             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RALT, KC_NO,
        KC_LCTL, KC_NO, KC_NO, KC_LALT, KC_SPC,                                                            KC_BTN1, KC_BTN3, KC_NO,   KC_NO,   KC_NO,
                                                          TO(_BSE), KC_NO,       KC_NO, TO(_BSE),
                                                                    KC_NO,       KC_NO,
                                                 KC_WREF, KC_NO,    KC_NO,       KC_NO, KC_ENT,   KC_SPC
    ),
    [_SET] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP, KC_TRNS,
        KC_TRNS,  KC_TRNS, RGB_SAI, RGB_VAI, RGB_MOD, RGB_HUI,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS,
        KC_TRNS,  RGB_TOG, RGB_SAD, RGB_VAD, RGB_RMOD,RGB_HUD,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        MO(_RST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RST),
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
                                                                        KC_TRNS,    KC_TRNS,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_RST] = LAYOUT(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
        KC_NO,    KC_NO,   EE_CLR,  DB_TOGG, QK_BOOT, KC_NO,                          KC_NO, QK_BOOT, DB_TOGG, EE_CLR, KC_NO,   KC_NO,
        KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TRNS,
        KC_NO,    KC_TRNS, KC_NO,   KC_NO,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,  KC_TRNS, KC_NO,
                                                             KC_NO, KC_TRNS, KC_TRNS, KC_NO,
                                                                    KC_NO,   KC_NO,
                                                      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO
    ),
};

// combos
enum combos {
    BRIGHTNESS_MEDIA_PREV,
    VOLUME_MEDIA_NEXT,
};
const uint16_t PROGMEM media_prev_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM media_next_combo[] = {KC_BRID, KC_BRIU, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [VOLUME_MEDIA_NEXT] = COMBO(media_prev_combo, KC_MPRV),
    [BRIGHTNESS_MEDIA_PREV] = COMBO(media_next_combo, KC_MNXT),
};


// dynamic macros
bool isRecordingLeft = false;
bool isRecordingRight = false;

void dynamic_macro_record_start_user(int8_t direction) {
  switch (direction) {
    case -1:
        isRecordingLeft = true;
        break;
    case 1:
        isRecordingRight = true;
        break;
  }
  layer_state_set_user(layer_state);
}

void dynamic_macro_record_end_user(int8_t direction) {
  switch (direction) {
    case -1:
        isRecordingLeft = false;
        break;
    case 1:
        isRecordingRight = false;
        break;
  }
  layer_state_set_user(layer_state);
}


// layer state
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BSE:
            rgblight_sethsv(0, 0, 255);
            break;
        case _NUM:
            rgblight_sethsv(42, 255, 255);
            break;
        case _NVG:
            rgblight_sethsv(170, 255, 255);
            break;
        case _GMG:
            rgblight_sethsv(85, 255, 255);
            break;
        case _SET:
            rgblight_sethsv(212, 255, 255);
            break;
        case _RST:
            rgblight_sethsv(0, 255, 255);
            break;
        default:  // for any other layers, or the default layer
            rgblight_sethsv(0, 50, 50);
            break;
    }
    if (isRecordingLeft) {
        rgblight_sethsv_range(226, 255, 255, 0, 3);
    }
    if (isRecordingRight) {
        rgblight_sethsv_range(226, 255, 255, 11, 16);
    }

  return state;
}


// initialization
void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}

