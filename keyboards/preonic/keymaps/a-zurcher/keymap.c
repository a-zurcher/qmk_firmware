/* Copyright 2015-2021 Alexandre Zürcher
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
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   #  |Termin|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | SUPER| LAlt | RAlt | Lower|    Space    | Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ] = LAYOUT_preonic_grid(
  KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_NUHS, LGUI(KC_F12),
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL,      KC_LGUI, KC_LALT, KC_RALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* MIDI
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  n/a |  C#3 |  D#3 |  n/a |  F#3 |  G#3 |  A#3 |  n/a |  C#4 |  D#4 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  C3  |  D3  |  E3  |  F3  |  G3  |  A3  |  B3  |  C4  |  D4  |  E4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Oct- | Oct+ |  n/a |  n/a |  n/a |  n/a |  n/a |  n/a | Vel- | Vel+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_NO,   MI_Cs3,  MI_Ds3,  KC_NO,   MI_Fs3,  MI_Gs3,  MI_As3,  KC_NO,   MI_Cs4,  MI_Ds4,  _______,
  _______, MI_C3,   MI_D3,   MI_E3,   MI_F3,   MI_G3,   MI_A3,   MI_B3,   MI_C4,   MI_D4,   MI_E4,   _______,
  _______, MI_OCTD, MI_OCTU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MI_VELD, MI_VELU, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
 * |      |RESET |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |QWERTZ| MIDI |      |mouse1|mouse2|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Lmouse|Dmouse|Umouse|Rmouse|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        rgblight_enable();
    } else {
        rgblight_disable();
    }
    return true;
}

extern rgblight_config_t rgblight_config;
void keyboard_post_init_user(void) {
  rgblight_config.hue = 100; // only change this
  rgblight_config.sat = 255;
  rgblight_config.val = 255;
}

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
