/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

enum my_keyball_keycodes {
    LAY_TOG = KEYBALL_SAFE_RANGE, // レイヤーLEDトグル
    PRC_TOG,                      // Precision モードトグル
    PRC_SW,                       // Precision モードスイッチ
    JIGGLER_TOG,                  // ジグラーのトグル
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U           , KC_I     , KC_O           , KC_P                 , KC_BSPC      ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J           , KC_K     , KC_L           , LT(2,KC_SCLN)        , LT(3,KC_ENT) ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M           , KC_COMM  , KC_DOT         , MT(MOD_LSFT,KC_SLSH) , KC_BSLS      ,
               KC_LALT  , KC_LGUI             , LT(4,KC_F20) , LT(3,KC_SPC) , LT(5,KC_MINS)     , MT(MOD_LGUI,KC_GRV)  , LT(4,KC_F21)   , _______  , _______       , LT(1,KC_ESC)
  ),

  [1] = LAYOUT_universal(
    KC_ESC   , TG(1)           , KC_7     , KC_8     , KC_9     , S(KC_MINS)       ,                         KC_TRNS  , KC_F7      , KC_F8      , KC_F9   , KC_F12   , KC_TRNS  ,
    KC_TRNS  , KC_ASTERISK     , KC_4     , KC_5     , KC_6     , KC_KP_PLUS       ,                         KC_TRNS  , KC_F4      , KC_F5      , KC_F6   , KC_F11   , KC_TRNS  ,
    KC_TRNS  , KC_KP_SLASH     , KC_1     , KC_2     , KC_3     , KC_KP_MINUS      ,                         KC_TRNS  , KC_F1      , KC_F2      , KC_F3   , KC_F10   , KC_TRNS  ,
                KC_0           , KC_0                , KC_DOT   , KC_0   , KC_KP_ENTER          , KC_TRNS  , KC_TRNS  , _______    , _______              , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_TRNS  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_TRNS  , KC_F5      , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS,
    KC_TRNS  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_TRNS  , KC_MS_BTN1 , KC_MS_BTN2 , PRC_SW  , KC_TRNS , KC_TRNS,
    KC_TRNS  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_TRNS  , KC_MS_BTN4 , KC_MS_BTN5 , KC_TRNS , KC_TRNS , KC_TRNS,
              KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                   KC_TRNS   , KC_TRNS , _______    , _______              , KC_TRNS
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_HOME  , KC_PAGE_DOWN , KC_PAGE_UP , KC_END  , KC_TRNS , KC_TRNS,
    LAY_TOG  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_LEFT  , KC_DOWN      , KC_UP      , KC_RIGHT, KC_TRNS , KC_TRNS,
    PRC_TOG  ,KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                              KC_TRNS  , QK_KB_13     , QK_KB_14   , QK_KB_15, KC_TRNS , KC_TRNS,
              KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                   KC_TRNS  , KC_TRNS  , _______ , _______         , KC_TRNS
  ),

  [4] = LAYOUT_universal(
    JIGGLER_TOG  ,S(KC_1)          , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)     ,                              S(KC_6)     , S(KC_7) , S(KC_8)         , S(KC_9)           , S(KC_0) , KC_TRNS ,
    KC_TRNS  ,KC_1             , KC_2     , KC_3     , KC_4     , KC_5        ,                              KC_6        , KC_7    , KC_8            , KC_9              , KC_0    , KC_QUOTE,
    KC_TRNS  ,KC_TRNS          , S(KC_9)  , S(KC_0)  , KC_TRNS  , KC_TRNS     ,                              KC_TRNS     , KC_MINS , KC_LEFT_BRACKET , KC_RIGHT_BRACKET  , KC_EQUAL, KC_EQUAL ,
              KC_TRNS          , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS     ,                   KC_TRNS  , S(KC_EQUAL) , _______ , _______                             , KC_TRNS
  ),

  [5] = LAYOUT_universal(
    KC_TRNS ,KC_TRNS         ,KC_TRNS     ,LGUI(KC_UP)        ,KC_TRNS             ,KC_TRNS,                KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS,
    KC_TRNS ,LCTL(LGUI(KC_D)),LGUI(KC_TAB),LCTL(LGUI(KC_LEFT)),LCTL(LGUI(KC_RIGHT)),KC_TRNS,                KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS,
    KC_TRNS ,KC_TRNS         ,KC_TRNS     ,LGUI(KC_LEFT)      ,LGUI(KC_RIGHT)      ,KC_TRNS,                KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS,
             KC_TRNS         ,KC_TRNS     ,KC_TRNS            ,KC_TRNS             ,KC_TRNS,     KC_TRNS  , KC_TRNS  , _______ , _______          , KC_TRNS
  ),
};
// clang-format on

#ifdef LAYER_LED_ENABLE
#include "layer_led.c"
#endif

#ifdef PRECISION_ENABLE
#include "precision.c"
#endif

#ifdef JIGGLER_ENABLE  
#include "jiggler.c"  
#endif  

void matrix_scan_user(void) {  
    #ifdef JIGGLER_ENABLE  
    jiggler_task();  
    #endif  
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3); 

    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 3:
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            keyball_set_scroll_mode(get_highest_layer(state) == 3); 
            break;
        default:
            set_auto_mouse_enable(true);
            break;
    }
    #endif

    change_layer_led_color(get_highest_layer(state));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef LAYER_LED_ENABLE
        case LAY_TOG: toggle_layer_led(record->event.pressed); return true;
        #endif
        #ifdef PRECISION_ENABLE
        case PRC_SW:  precision_switch(record->event.pressed); return false;
        case PRC_TOG: precision_toggle(record->event.pressed); return false;
        #endif
        #ifdef JIGGLER_ENABLE  
        case JIGGLER_TOG: jiggler_toggle(record->event.pressed); return false;  
        #endif  
        default: break;
    }
    return true;
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
