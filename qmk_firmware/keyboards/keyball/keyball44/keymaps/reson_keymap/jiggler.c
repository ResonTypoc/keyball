#ifdef JIGGLER_ENABLE

#include QMK_KEYBOARD_H

static bool jiggler_enabled = false;
static uint32_t jiggler_timer = 0;
static bool led_update_pending = false;

#ifndef JIGGLER_INTERVAL  
#define JIGGLER_INTERVAL 180000  // デフォルト3分 = 180,000ms  
#endif

#ifndef JIGGLER_KEYCODE  
#define JIGGLER_KEYCODE KC_F23   // デフォルトF23キー  
#endif

#ifdef LAYER_LED_ENABLE  
void change_layer_led_color(uint8_t layer_no);  
#endif

void jiggler_toggle(bool pressed) {  
    if (!pressed) {  
        return;  
    }  
      
    jiggler_enabled = !jiggler_enabled;
    if (jiggler_enabled) {
        jiggler_timer = timer_read32();
    }

#ifdef LAYER_LED_ENABLE
    led_update_pending = true;
#endif
}

void jiggler_task(void) {
    if (jiggler_enabled) {
        if (timer_elapsed32(jiggler_timer) > JIGGLER_INTERVAL) {
            tap_code(JIGGLER_KEYCODE);
            jiggler_timer = timer_read32();
        }
    }

#ifdef LAYER_LED_ENABLE
    if (led_update_pending) {
        change_layer_led_color(get_highest_layer(layer_state));
        led_update_pending = false;
    }
#endif
}

bool jiggler_is_enabled(void) {  
    return jiggler_enabled;  
}

#endif