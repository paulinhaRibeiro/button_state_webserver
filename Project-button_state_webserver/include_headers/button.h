#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"

void button_init(uint pin);
bool button_is_pressed(uint pin);

#endif
