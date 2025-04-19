#include "button.h"


void button_init(uint pin)
{
    // Configura o botão
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin); // Usa resistor de pull-up interno
}

// Muda o estado do botão
bool button_is_pressed(uint pin)
{
    return !gpio_get(pin);
}