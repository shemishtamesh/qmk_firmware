/*
Copyright 2021 StefanGrindelwald

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

#pragma once


#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5, B6, B7 }
#define MATRIX_COL_PINS { F7, F6, F5, F4, F1, F0 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define SELECT_SOFT_SERIAL_SPEED 5

#define RGB_DI_PIN C7
#define RGBLIGHT_LED_COUNT 22
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLED_SPLIT { 11, 11 }
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// split handadness
#define SPLIT_USB_DETECT
#define EE_HANDS

// mouse
#define MK_COMBINED
#define MOUSEKEY_MAX_SPEED 4

// combos
#define COMBO_COUNT 2

