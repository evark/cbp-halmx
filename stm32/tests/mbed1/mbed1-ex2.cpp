 #include "gpio_api.h"
#include "serial_api.h"
 /*
    MBED LOW LEVEL HAL TESTS

    uart test

*/

gpio_t led;
serial_t pc;

 int main() {
    serial_init(&pc,SERIAL_TX,SERIAL_RX);
    gpio_init_out(&led, LED1);

     while(1) {
         gpio_write(&led, !gpio_read(&led));
         serial_putc(&pc, 'A');
         HAL_Delay(150);
     }
 }
