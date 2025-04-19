#ifndef PAGE_H
#define PAGE_H

#include "pico/stdlib.h"

extern char http_response[1024];
void create_http_response(bool button_pressed, float temp);

#endif
