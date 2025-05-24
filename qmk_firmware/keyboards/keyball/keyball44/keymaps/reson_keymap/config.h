/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

// オートマウスレイヤ関係
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 2 // オートマウスのデフォルトレイヤ
#define AUTO_MOUSE_TIME 500 // オートマウスの有効時間 (ms)

#define DYNAMIC_KEYMAP_LAYER_COUNT 7 // レイヤ数

#define TAPPING_TERM 164 // キー長押し判定時間

#define KEYBALL_CPI_DEFAULT 700 // デフォルトCPI
#define KEYBALL_SCROLL_DIV_DEFAULT 6 // デフォルトスクロール速度

// レイヤーごとにLED色を変更する
#define LAYER_LED_ENABLE

// CPIプレシジョンモード
#define PRECISION_ENABLE // 有効化
#define PRECISION_CPI 2  // 下げた時のCPI (1/100の値を指定。)

// Jiggler機能
#define JIGGLER_ENABLE // 有効化
#define JIGGLER_INTERVAL 10000  // 3分間隔  
#define JIGGLER_KEYCODE KC_A   // 送信するキー