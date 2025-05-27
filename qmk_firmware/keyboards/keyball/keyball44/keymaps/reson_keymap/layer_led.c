#ifdef LAYER_LED_ENABLE

#include QMK_KEYBOARD_H

#ifdef JIGGLER_ENABLE
bool jiggler_is_enabled(void);  
#endif

static const uint8_t my_layer_colors[] = {43, 85, 128, 171, 213, 0}; // 黄, 緑, シアン, 青, マゼンタ, 赤

static uint8_t my_latest_val    = 0;
static uint8_t my_latest_hue    = 0;
static bool    layer_led        = false;
static bool    brightness_saved = false;

// レイヤーごとにLED色変更
void change_layer_led_color(uint8_t layer_no) {
    if (!layer_led) {
        return;
    }

#ifdef JIGGLER_ENABLE  
    // ジグラーが有効な場合は専用色を表示  
    if (jiggler_is_enabled()) {  
        rgblight_sethsv(0, 255, my_latest_val);  // 赤 
        return;  
    }  
#endif

    // 初回のみ明度を保存  
    if (!brightness_saved) {  
        my_latest_val = rgblight_get_val();  
        brightness_saved = true;  
    }

    if (layer_no == 0) {
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0);
    } else if (layer_no <= 6) {
        rgblight_sethsv(my_layer_colors[layer_no-1], rgblight_get_sat(), my_latest_val);
    }
}

// 機能の有効・無効を切り替え
void toggle_layer_led(bool pressed) {
    if (!pressed) {
        return;
    }

    layer_led = !layer_led;
    if (layer_led) {
        my_latest_hue = rgblight_get_hue();
    } else {
        rgblight_sethsv(my_latest_hue, rgblight_get_sat(), rgblight_get_val());
    }
}

#endif