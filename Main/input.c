/* Setup functions which call low level input routines (maybe using <osbind.h>) */
/* Detect clock ticks in here? */
#include "input.h"

#define DEFAULT_NO_IRQ 0x16
#define DEFAULT 0x96

extern int isr_pause(int new_mask);

volatile UINT8 *const IKBD_control = 0xFFFC00;
volatile const UINT8 *const IKBD_status = 0xFFFC00;
volatile const UINT8 *const IKBD_RDR = 0xFFFC02;

char keyboard_buffer[256];
int buffer_index = 0;
int buffer_open = 0;
int buffer_fill = 0;

char mouse_info[3];
int mouse_x = 0;
int mouse_y = 0;
int mouse_click = 0;
int mouse_prog = 0;

int get_mouse_x() {
    int temp;

    int old_mask = isr_pause(6);
    temp = mouse_x;
    isr_pause(old_mask);

    return temp;
}

int get_mouse_y() {
    int temp;

    int old_mask = isr_pause(6);
    temp = mouse_y;
    isr_pause(old_mask);

    return temp;
}

int get_mouse_click() {
    int temp;

    int old_mask = isr_pause(6);
    temp = mouse_click;
    isr_pause(old_mask);

    return temp;
}

char keystroke() {
    char ch;
    if (buffer_fill > 0) {
        ch = keyboard_buffer[buffer_index];
        buffer_index++;
        buffer_fill--;
        
        if (buffer_index < 0) {
            buffer_index = 255;
        }

        return ch;
    }  else {
        return '\0';
    }
}

void do_IKBD_ISR() {
    UINT8 scancode;
    char *scancode_2_ascii = (char *)((Keytbl(-1, -1, -1))->unshift);

    *IKBD_control = DEFAULT_NO_IRQ;

    if(*IKBD_status & 0x1) {
        scancode = *IKBD_RDR;
        if ((scancode < 0x80) && (mouse_prog == 0)) { /* Key Pressed */
            add_to_buffer(scancode_2_ascii[scancode]);
        }

        if ((scancode >= 0xF8) && (mouse_prog == 0)) { /* Mouse Packet */
            mouse_info[0] = scancode;
            mouse_prog = 1;
        } else if (mouse_prog == 1) { /* Mouse X */
            mouse_info[1] = scancode;
            mouse_prog = 2;
        } else if (mouse_prog == 2) { /* Mouse Y */
            mouse_info[2] = scancode;
            mouse_prog = 0;

            mouse_x += (int)mouse_info[1];
            mouse_y += (int)mouse_info[2];

            if (mouse_x >= 632) {
                mouse_x = 632;
            } else if (mouse_x < 0) {
                mouse_x = 0;
            }

            if (mouse_y >= 392) {
                mouse_y = 392;
            } else if (mouse_y < 0) {
                mouse_y = 0;
            }

            mouse_click = (mouse_info[0] & 0x1) ? 1 : 0;
        }
    }

    *IKBD_control = DEFAULT;
}

void add_to_buffer(char ch) {
    if (buffer_fill <= 256) {
        keyboard_buffer[buffer_open] = ch;
        buffer_open++;
        buffer_fill++;

        if (buffer_open > 255) {
            buffer_open = 0;
        }
    } else {
        return;
    }
}

