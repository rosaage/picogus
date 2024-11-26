#include <stdio.h>
#include "pico/flash.h"

#include "tusb.h"
#include "mouse/8250uart.h"
#include "mouse/sermouse.h"

// #include <string.h>

#include "pico_pic.h"

void play_usb() {
    puts("starting core 1 USB");
    flash_safe_execute_core_init();

    // board_init();

    // Init PIC on this core so it handles timers
    PIC_Init();
    puts("pic inited on core 1");

    // init host stack on configured roothub port
    tuh_init(BOARD_TUH_RHPORT);

    for (;;) {
        // tinyusb host task
        tuh_task();

        // mouse task
        sermouse_core1_task();

        // uart emulation task
        uartemu_core1_task();
    }
}
