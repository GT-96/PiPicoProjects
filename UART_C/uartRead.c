#include <stdio.h>
#include "pico/stdlib.h"
#include <pthread.h>
#include "pico/multicore.h"

#define UART_TX_PIN 0
#define UART_RX_PIN 1



void core1_main(){


    uart_init(uart0, 115200);
    gpio_set_function(UART_TX_PIN,GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);


    while(true){

        printf("Testing Uart");
        uart_puts(uart0, "Testing");

        sleep_ms(5000);

    }


}


int main() {
    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    multicore_launch_core1(core1_main);

    while (true) {
        printf("this is in main thread\n");
        // sleep_ms(500);

        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        sleep_ms(200);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        sleep_ms(200);



    }
    return 0;
}


