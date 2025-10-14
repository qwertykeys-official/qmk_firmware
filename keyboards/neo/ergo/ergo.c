/* 
Copyright 2023 NEO

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
#include "ergo.h"
// #include "print.h"


uint8_t swtchIdx = 0;
uint8_t ledstart[]={
    5,
    5,
    8,
    15
};

uint8_t lednumber[]={
    11,
    3,
    8,
    0
};
keyboard_config_t keyboard_config;


const rgblight_segment_t PROGMEM my_capslock_layer0[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_WHITE});
const rgblight_segment_t PROGMEM my_capslock_layer1[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_WHITE});
const rgblight_segment_t PROGMEM my_capslock_layer2[] = RGBLIGHT_LAYER_SEGMENTS({8, 8, HSV_WHITE});
const rgblight_segment_t PROGMEM my_capslock_layer3[] = RGBLIGHT_LAYER_SEGMENTS({15, 0, HSV_WHITE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer0,
    my_capslock_layer1,
    my_capslock_layer2,
    my_capslock_layer3
);

void keyboard_post_init_kb(void) {
    keyboard_config.raw = eeconfig_read_kb(); //从eeprom里读取数据
    swtchIdx = keyboard_config.led_toggle_index;
    if( swtchIdx > 3 || swtchIdx < 0){
        swtchIdx = 0;
        keyboard_config.led_toggle_index = 0;
        eeconfig_update_kb(keyboard_config.raw);
    }
    
    rgblight_layers = my_rgb_layers;
    rgblight_disable();//关闭灯效
    rgblight_set_effect_range(ledstart[swtchIdx], lednumber[swtchIdx]);  //开机设置灯效范围
    rgblight_enable();//打开灯效
    keyboard_post_init_user();
}

bool led_update_kb(led_t led_state) { //开机设置大写照明灯范围
    bool res = led_update_user(led_state);
        if (res) {
        rgblight_set_layer_state(swtchIdx, led_state.caps_lock);
    }
    return res;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {
        
        case RGB_TOG:
            if (record->event.pressed) {
                if(host_keyboard_led_state().caps_lock){ //判断是否大写状态
                    rgblight_set_layer_state(swtchIdx, false);//先把大写关了，不然靠下边的代码关不掉大写灯
                }

                swtchIdx++;
                if(swtchIdx > 3){ //0到3循环
                    swtchIdx = 0;
                }
                
                rgblight_disable();//关闭灯效
                rgblight_set_effect_range(ledstart[swtchIdx], lednumber[swtchIdx]);//设置灯效范围
                // xprintf("ledstart[swtchIdx]:%d, lednumber[swtchIdx]:%d, swtchIdx:%d\n", ledstart[swtchIdx], lednumber[swtchIdx], swtchIdx);
                keyboard_config.led_toggle_index = swtchIdx;
                eeconfig_update_kb(keyboard_config.raw);//存到eeprom里
                rgblight_set_layer_state(swtchIdx, host_keyboard_led_state().caps_lock);//设置大写范围
                // if(swtchIdx < 3){
                rgblight_enable();//打开灯效
                // }
            }
            return false;

        default:
            break;
   }


  return process_record_user(keycode, record);
}
