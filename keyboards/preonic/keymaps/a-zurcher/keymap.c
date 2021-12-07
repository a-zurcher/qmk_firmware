/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTZ,
  _MIDI,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTZ = SAFE_RANGE,
  MIDI,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Yakuak|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   #  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | SUPER| LAlt | RAlt | Lower|    Space    | Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ] = LAYOUT_preonic_grid(
  KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  LGUI(KC_F12), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_NUHS, KC_RSFT,
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SENT,
  KC_LCTL,      KC_LGUI, KC_LALT, KC_RALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* MIDI
 * ,-----------------------------------------------------------------------------------.
 * |QWERTZ|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |-1 oct| -vel | +vel |+1 oct|
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_preonic_grid(
  MI_Ds_3,  MI_E_3,  MI_F_3,  MI_Fs_3, MI_G_3,  MI_Gs_3, MI_A_3,  MI_As_3, MI_B_3,  MI_C_4,  MI_Cs_4, MI_D_4,
  MI_As_2,  MI_B_2,  MI_C_3,  MI_Cs_3, MI_D_3,  MI_Ds_3, MI_E_3,  MI_F_3,  MI_Fs_3, MI_G_3,  MI_Gs_3, MI_A_3,
  MI_F_2,   MI_Fs_2, MI_G_2,  MI_Gs_2, MI_A_2,  MI_As_2, MI_B_2,  MI_C_3,  MI_Cs_3, MI_D_3,  MI_Ds_3, MI_E_3,
  MI_C_2,   MI_Cs_2, MI_D_2,  MI_Ds_2, MI_E_2,  MI_F_2,  MI_Fs_2, MI_G_2,  MI_Gs_2, MI_A_2,  MI_As_2, MI_B_2,
  _______,  _______, _______, _______, LOWER,   _______, _______, RAISE,   MI_OCTD, MI_VELD, MI_VELU, MI_OCTU
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ^  |      |      |      |      |      |      |      |      |   ß  |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   Ü  |   +  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   Ö  |   Ä  |   #  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   <  |   >  |   ¸  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | print|      |      |      |      |     Play    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_GRV,   _______, _______,       _______,        _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______,
  _______,  KC_F1,   KC_F2,         KC_F3,          KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LBRC, KC_RBRC, _______,
  _______,  KC_F7,   KC_F8,         KC_F9,          KC_F10,  KC_F11,  KC_F12,  _______, KC_SCLN, KC_QUOT, KC_NUHS, _______,
  _______,  KC_NUBS, LSFT(KC_NUBS), RALT(KC_EQL),   _______, _______, _______, _______, _______, _______, _______, _______,
  KC_PSCR,  _______, _______,       _______,        _______, KC_MPLY, KC_MPLY, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   °  |      |      |      |      |      |      |      |      |   ?  |   `  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   Ü  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   Ö  |   Ä  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   |  |      |   ¸  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | print|      |      |      |      |     Play    |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  LSFT(KC_GRV), _______,       _______, _______,        _______, _______, _______, _______, _______, LSFT(KC_MINS), LSFT(KC_EQL),  _______,
  _______,      KC_F1,         KC_F2,   KC_F3,          KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LBRC,       LSFT(KC_RBRC), _______,
  _______,      KC_F7,         KC_F8,   KC_F9,          KC_F10,  KC_F11,  KC_F12,  _______, KC_SCLN, KC_QUOT,       LSFT(KC_NUHS), _______,
  _______,      RALT(KC_NUBS), _______, LSFT(KC_NUBS),  _______, _______, _______, _______, _______, _______,       _______,       _______,
  KC_PSCR,      _______,       _______, _______,        _______, KC_MPLY, KC_MPLY, _______, KC_MPRV, KC_VOLD,       KC_VOLU,       KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |QWERTZ| MIDI |      |mouse1|mouse2|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Lmouse|Dmouse|Umouse|Rmouse|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, QWERTZ,  MIDI,    _______, KC_BTN1, KC_BTN2, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTZ:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTZ);
          }
          return false;
          break;
        case MIDI:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MIDI);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
