#pragma once

#include <stdint.h>
#include "8250uart.h"
#include "tusb.h"

#ifdef __cplusplus
extern "C" {
#endif

// serial mouse emulation structures

// current mouse protocol
enum {
    SERMOUSE_PROTOCOL_MICROSOFT     = 0,
    SERMOUSE_PROTOCOL_LOGITECH      = 1,
    SERMOUSE_PROTOCOL_INTELLIMOUSE  = 2,
    SERMOUSE_PROTOCOL_MOUSESYSTEMS  = 3,

    SERMOUSE_PROTOCOL_LAST,
};

enum {
    SERMOUSE_REPORTRATE_MIN         = 20,
    SERMOUSE_REPORTRATE_MAX         = 200,

    SERMOUSE_REPORTRATE_DEFAULT     = 60,

    SERMOUSE_REPORT_LEN_MAX         = 8,
};

enum {
    SERMOUSE_STATE_NULL             = 0,        // invalid
    SERMOUSE_STATE_RESET,
    SERMOUSE_STATE_ID,
    SERMOUSE_STATE_RUN,
};

struct sermouse_packet_t {
    int16_t           x, y, z;                // current coordinates

    // formatted data buffer
    struct uartemu_databuf_t databuf;
    uint8_t           data[SERMOUSE_REPORT_LEN_MAX];
};

struct sermouse_state_t {
    // is initialized?
    uint8_t     initialized : 1;

    // current and next state
    uint8_t     state, next_state;

    // current protocol
    uint8_t     protocol;

    // sensitivity in 8.8fx
    int16_t    sensitivity;

    // report rate in hz
    uint8_t     report_rate_hz;

    // report and byte send interval in us
    uint32_t    report_interval_us;
    uint32_t    rx_interval_us;

    // button data
    uint8_t     buttons, buttons_prev;

    // previous modem control info
    uint8_t     modem_control;

    // buffer index
    uint8_t     current_buf;

    // id token buffer
    struct uartemu_databuf_t idbuf;

    // current state buffer (double buffered)
    struct sermouse_packet_t pkt[2];

    // last packet timestamp in us
    uint64_t    last_pkt_timestamp_us;
};

// --------------------------
// any core
uint32_t sermouse_init();
uint32_t sermouse_attach_uart();
uint32_t sermouse_done();

void sermouse_set_protocol(uint8_t protocol);
uint8_t sermouse_get_protocol();

void sermouse_set_sensitivity(int16_t sensitivity);
int16_t sermouse_get_sensitivity();

void sermouse_set_report_rate_hz(uint8_t rate);
uint8_t sermouse_get_report_rate_hz();

// --------------------------
// core1 side
void sermouse_core1_task();

// mouse HID report callback
void sermouse_process_report(hid_mouse_report_t const * report);

#ifdef __cplusplus
}
#endif