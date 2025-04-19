#include "temperature_sensor.h"
#include "hardware/adc.h" // controle do ADC (conversor analógico-digital)


// INICIALIZAÇÃO DO SENSOR DE TEMPERATURA
void temperature_sensor_init(void) {
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

// LEITURA DA TEMPERATURA INTERNA
float read_temperature(void) {
    // Seleciona o canal ADC 4 (sensor de temperatura interno da RP2040) e lê o valor.
    adc_select_input(4);
    uint16_t raw = adc_read();
    // Converte o valor lido para graus Celsius. Fórmula padrão da RP2040.
    const float fator = 3.3f / (1 << 12);
    return 27.0f - ((raw * fator) - 0.706f) / 0.001721f;
}
