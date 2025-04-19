#include "page.h"
#include <stdio.h>
#include <string.h>

// Buffer para resposta HTTP
char http_response[1024];


// Função para criar a resposta HTTP
void create_http_response(bool button_pressed, float temp)
{
    // GERAÇÃO DA PÁGINA HTML DE RESPOSTA
    /*
        Cria uma página HTML com botões para controlar os LEDs e mostra a temperatura atual.
        Os botões enviam novos comandos (GET) ao servidor ao serem clicados.
    */
   snprintf(http_response, sizeof(http_response),
   "HTTP/1.1 200 OK\r\n"
   "Content-Type: text/html\r\n"
   "\r\n"
   "<!DOCTYPE html>"
   "<html lang=\"pt-BR\">"
   "<head>"
   "  <meta charset=\"UTF-8\">"
   "  <title>Estado do Botão e Temperatura Interna</title>"
   "  <script src=\"https://cdn.tailwindcss.com\"></script>"
   "  <style>body {font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;}</style>"
   "</head>"
   "<body class=\"bg-gradient-to-br from-[#f7f8fa] to-[#e8ebf0] min-h-screen text-gray-800\">"
   "  <header class=\"w-full text-center py-8 bg-[#12343b] shadow-md\">"
   "    <h1 class=\"text-4xl font-bold tracking-wide text-white uppercase\">Estado do Botão e Temperatura Interna</h1></header>"
   "  <div class=\"flex flex-col items-center space-y-6 mt-10\">"
   "    <div class=\"text-xl font-semibold text-[#12343b]\">Botão está: %s</div>"
   "    <div class=\"text-xl font-semibold text-[#12343b]\">Temperatura Interna: %.2f &deg;C</div>"
   "  </div>"
   "  <script>"
   "      setTimeout(function(){"
   "          location.reload();"
   "      }, 1000);"
   "  </script>"
   "</body></html>",
   button_pressed ? "Pressionado" : "Solto",
   temp);
}