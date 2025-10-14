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
#pragma once

#include "quantum.h"

extern uint8_t swtchIdx;
extern uint8_t ledstart[];

extern uint8_t lednumber[];

typedef union {
    uint32_t raw;
    struct {
        uint8_t led_toggle_index :8;
    };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;