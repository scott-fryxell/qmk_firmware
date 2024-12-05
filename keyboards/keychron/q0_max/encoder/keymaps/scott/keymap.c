#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    BASE,
    RIMLOS,
    WAFT,
    FUNC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tenkey_27(
        KC_MUTE,       TO(BASE), TO(RIMLOS), TO(WAFT),     TO(FUNC),
        KC_TAB,          KC_NUM,    KC_PSLS,  KC_PAST,      KC_PMNS,
        KC_LEFT_CTRL,     KC_P7,      KC_P8,    KC_P9,      KC_PPLS,
        KC_LEFT_ALT,      KC_P4,      KC_P5,    KC_P6,
        KC_LEFT_GUI,      KC_P1,      KC_P2,    KC_P3,      KC_PENT,
        KC_LEFT_SHIFT,    KC_P0,              KC_PDOT),

    [RIMLOS] = LAYOUT_tenkey_27(
         KC_SPC,        _______,    _______,  _______,      _______,
        _______,           KC_R,       KC_I,     KC_M,         KC_L,
        _______,        KC_HOME,      KC_UP,  KC_PGUP,         KC_O,
        _______,        KC_LEFT,      KC_P5, KC_RIGHT,
        _______,         KC_END,    KC_DOWN,  KC_PGDN,         KC_S,
        _______,         KC_ESC,               KC_DEL),

    [WAFT] = LAYOUT_tenkey_27(
     KC_MS_BTN1,        _______,    _______,  _______,      _______,
        _______,           KC_W,       KC_H,  XXXXXXX,     KC_MS_UP,
        _______,           KC_A,       KC_U,  XXXXXXX,   KC_MS_DOWN,
        _______,           KC_F,       KC_V,  XXXXXXX,
        _______,           KC_T,       KC_X,  XXXXXXX,  KC_MS_RIGHT,
        _______,     KC_MS_LEFT,              XXXXXXX),

    [FUNC] = LAYOUT_tenkey_27(
        XXXXXXX,        _______,    _______,   _______,     _______,
        _______,         KC_F10,     KC_F11,    KC_F12,     BT_HST1,
        _______,          KC_F7,      KC_F8,     KC_F9,     BT_HST2,
        _______,          KC_F4,      KC_F5,     KC_F6,
        _______,          KC_F1,      KC_F2,     KC_F3,     BT_HST3,
        _______,        XXXXXXX,               XXXXXXX),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [RIMLOS] = {ENCODER_CCW_CW(KC_PMNS, KC_PPLS)},
    [WAFT]   = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [FUNC]   = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_mode(1);
  switch(biton32(state)) {
    case 0:
        rgblight_disable_noeeprom();
        break;
    case 1:
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    case 2:
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
    case 3:
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_WHITE);
        break;
    default:
		rgblight_disable_noeeprom();
    break;
  }
  return state;
}
