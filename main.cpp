#include <stdio.h>
#include "pico/stdlib.h"

#ifndef PICO_DEFAULT_LED_PIN
#error blink example requires a board with a regular LED
#else
constexpr uint LED_PIN = PICO_DEFAULT_LED_PIN;
#endif

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    printf("Hello, world!\n");
    
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        sleep_ms(900);
    }
}