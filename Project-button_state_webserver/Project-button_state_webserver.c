#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "temperature_sensor.h"
#include "button.h"
#include "server_http.h"
#include "wifi.h"

const uint BUTTON_A_PIN = 5; // Pino do Botão A

volatile bool button_pressed = false;
volatile float temperature = 0.0;

int main()
{
    // Inicializa a comunicação padrão
    stdio_init_all();
    // Configura o botão
    button_init(BUTTON_A_PIN);
    // INICIALIZAÇÃO DO SENSOR DE TEMPERATURA
    // Liga o ADC e ativa o sensor de temperatura interno.
    temperature_sensor_init();

    // Tempo para leitura do estado do botão
    absolute_time_t last_button_update = get_absolute_time();

    sleep_ms(10000);

    // tenta conectar aoa wifi
    if (!connect_to_wifi())
        return 1;

    // Inicia o servidor HTTP
    server_http_init();

    while (true)
    {
        // Mantém o sistema em funcionamento, escutando conexões.
        //    É obrigatório para o Wi-Fi funcionar corretamente na Pico W.
        cyw43_arch_poll();

        // Atualiza o estado do botão e ler a temperatura a cada 1 segundo
        if (absolute_time_diff_us(last_button_update, get_absolute_time()) >= 1000000)
        {
            temperature = read_temperature();
            button_pressed = button_is_pressed(BUTTON_A_PIN);
            // Atualiza o tempo de leitura
            last_button_update = get_absolute_time();
        }

        sleep_ms(100);
    }

    // ENCERRAMENTO (caso saísse do loop)
    // Desliga o Wi-Fi ao finalizar o programa (embora nunca chegue aqui com while (true)).
    cyw43_arch_deinit();
    return 0;
}
