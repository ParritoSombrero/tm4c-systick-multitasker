#include <stdint.h>
#include <string.h>
#include "gpio.h"
#include "uart.h"
#include "systick.h"

int state = 0;

int main(void) {
    gpio_init();
    systick_setup();
    uart_init();

    timer_start(&trafficlight, 500);
    timer_start(&heartbeat, 1500);
    timer_start(&uarttimer, 4500);

    while(1) {
        if (timer_expired(&trafficlight)) {
            switch (state) {
                case 0:
                    // just to get everything cleared out
                    redLEDoff();
                    greenLEDoff();

                    redLEDtoggle();
                    state++;
                    timer_start(&trafficlight, 500);
                    break;
                case 1:
                    greenLEDtoggle();
                    state++;
                    timer_start(&trafficlight, 500);
                    break;
                case 2:
                    redLEDtoggle();
                    state = 0;
                    timer_start(&trafficlight, 500);
                    break;

            }
        }

        if (timer_expired(&heartbeat)) {
            blueLEDtoggle();
            timer_start(&heartbeat, 1500);
        }

        if (timer_expired(&uarttimer)) {
            uart_out("beat");
            timer_start(&uarttimer, 4500);
        }
    }
}
