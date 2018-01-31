#include "planck.h"
#include "keymap.h"
#include "keymap_german.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Down |Right | PgDn |  Del |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,     KC_P,    KC_BSPC              },
  {KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,     KC_SCLN, KC_QUOT              },
  {KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,   KC_SLSH, MT(MOD_RALT, KC_ENT) },
  {MO(_FUNC), KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DEL               } 
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   €  |  @   |      |      |      |      |  ü   |      |  ö   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ä  |  ß   |      |      |      |      |      |      |      |  |   |  ~   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |      |      |      |      |      |      |      |      |      |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {KC_GRV , DE_EURO, KC_AT,   _______, _______, _______, _______, DE_UE,   _______, DE_OE,   _______,   _______ },
  {_______, DE_AE,   DE_SS,   _______, _______, _______, _______, _______, _______, _______, KC_PIPE,   KC_TILD },
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLASH, _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______ }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |      |      |      |      |      |      |   _  |   =  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      | Pos1 | End  | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN,    KC_RPRN, KC_DEL  }, 
    {KC_DEL,  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_EQL,     KC_LCBR,    KC_RCBR, _______ },
    {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_PIPE, _______ },
    {_______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, LCTL(KC_A), LCTL(KC_E), KC_HOME, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  0   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   [  |  ]   |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 | F11  | F12  |      |   <  |   >  |  \   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |  Up  | Left | PgUp |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
    {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,      _______ },
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC,   KC_QUOT },
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, _______, KC_LT,   KC_GT,   KC_BSLASH, _______ },
    {_______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, KC_UP,   KC_LEFT, KC_PGUP,   _______ }
},
    

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | ???? | Reset|Qwerty|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |      | Mute | Vol+ | Play |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Prev | Vol- | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {M(0),    RESET,   QWERTY,  _______, _______, _______, _______, _______,             _______,           _______,              _______,  KC_DEL  },
  {KC_CAPS, _______, _______, _______, _______, _______, _______, KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE,  _______,  _______ },
  {_______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK,  _______,  _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
  }
  return true;
}

