 #include "gpio_api.h"

 /*
    MBED LOW LEVEL HAL TESTS

    gpio test

*/

 gpio_t led;

 int main() {
    gpio_init_out(&led, LED1);

     while(1) {
         gpio_write(&led, !gpio_read(&led));
         HAL_Delay(150);
     }
 }
