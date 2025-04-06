/* Setup functions which call low level input routines (maybe using <osbind.h>) */
/* Detect clock ticks in here? */
#include "input.h"

#define DEFAULT_NO_IRQ 0x16
#define DEFAULT 0x96

volatile UINT8 *const IKBD_control = 0xFFFC00;
volatile const UINT8 *const IKBD_status = 0xFFFC00;
volatile const UINT8 *const IKBD_RDR = 0xFFFC02;

char keyboard_buffer[256];
int buffer_index, buffer_fill;

void do_IKBD_ISR() {
    UINT8 scancode;
    char *scancode_2_ascii = (char *)((Keytbl(-1, -1, -1))->unshift);

    *IKBD_control = DEFAULT_NO_IRQ;

    if(*IKBD_status & 0x1) {
        scancode = *IKBD_RDR;
        if (scancode < 0x80) 
            add_to_buffer(scancode_2_ascii[scancode]);
    }

    *IKBD_control = DEFAULT;
}

void add_to_buffer(char ch) {
    if (buffer_fill <= 256) {
        buffer_index++;
        buffer_fill++;

        if (buffer_index > 256) {
            buffer_index = 0;
        }

        keyboard_buffer[buffer_index] = ch;
    } else {
        return;
    }
}

