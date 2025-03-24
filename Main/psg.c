#include <osbind.h>
#include "psg.h"

volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;

void write_psg(int reg, UINT8 val) {
    long old_ssp = Super(0);

    *PSG_reg_select = reg;
    *PSG_reg_write = val;

    Super(old_ssp);
}

void set_tone(int channel, int tuning) {
    /* Maximum value for 12 bits of data */
    if (tuning > 0xFFF) {
        return;
    }

    /* Because of the 1st max value check, we shouldn't need to & the 2nd call by 0xF */
    switch(channel) {
        case 0:
            write_psg(0, (UINT8)(tuning & 0xFF));
            write_psg(1, (UINT8)(tuning >> 8));  /* here. */
            break;
        case 1:
            write_psg(2, (UINT8)(tuning & 0xFF));
            write_psg(3, (UINT8)(tuning >> 8));  /* here. */
            break;
        case 2:
            write_psg(4, (UINT8)(tuning & 0xFF));
            write_psg(5, (UINT8)(tuning >> 8));  /* here. */
            break;
        default:
            return;
    }
}

void set_volume(int channel, int volume) {
    /* Maximum value for 5 bits of data */
    if (volume > 0x1F) {
        return;
    }

    switch(channel) {
        case 0:
            write_psg(8, (UINT8)(volume));
            break;
        case 1:
            write_psg(9, (UINT8)(volume));
            break;
        case 2:
            write_psg(10, (UINT8)(volume));
            break;
        default:
            return;
    }
}

void enable_channel(int channel, int tone_on, int noise_on) {
    long old_ssp;
    UINT8 value;

    if ((tone_on > 1) || (tone_on < 0)) {
        return;
    }

    if ((noise_on > 1) || (noise_on < 0)) {
        return;
    }

    /* Enter supervisor mode to grab current reg value */
    old_ssp = Super(0);

    *PSG_reg_select = 7; /* We check the 7th register, and only edit the 7th register */
    value = *PSG_reg_write;

    Super(old_ssp);


    /* For both switch cases, we handle two other cases, when the value is being turned on or off */
    /* To do this, the specific bits are modified from the CURRENT register value, then writted to the PSG */
    /* This looks slightly complicated, but this is done so that we dont overwrite other registers' settings */
    switch(channel) {
        case 0:
            if (tone_on) {
                value |= 0x1;
                write_psg(7, value);
            } else {
                value &= 0xFE;
                write_psg(7, value);  
            }
            break;
        case 1:
            if (tone_on) {
                value |= 0x2;
                write_psg(7, value);
            } else {
                value &= 0xFD;
                write_psg(7, value);  
            }
            break;
        case 2:
            if (tone_on){
                value |= 0x4;
                write_psg(7, value);
            } else {
                value &= 0xFB;
                write_psg(7, value);  
            }
            break;
        default:
            return;
    }

    switch(channel) {
        case 0:
            if (noise_on) { 
                value |= 0x8;
                write_psg(7, value);
            } else {
                value &= 0xF7;
                write_psg(7, value);  
            }
            break;
        case 1:
            if (noise_on) {
                value |= 0x10;
                write_psg(7, value);
            } else {
                value &= 0xEF;
                write_psg(7, value);  
            }
            break;
        case 2:
            if (noise_on) {
                value |= 0x20;
                write_psg(7, value);
            } else {
                value &= 0xDF;
                write_psg(7, value);  
            } 
            break;
        default:
            return;
    }
}

void stop_sound() {
    write_psg(8, 0);
    write_psg(9, 0);
    write_psg(10, 0);
}