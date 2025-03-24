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
    if (channel == 0) {
        write_psg(0, (UINT8)(tuning & 0xFF));
        write_psg(1, (UINT8)(tuning >> 8));  /* here. */
    } else if (channel == 1) {
        write_psg(2, (UINT8)(tuning & 0xFF));
        write_psg(3, (UINT8)(tuning >> 8));  /* here. */
    } else if (channel == 2) {
        write_psg(4, (UINT8)(tuning & 0xFF));
        write_psg(5, (UINT8)(tuning >> 8));  /* here. */
    } else {
        return;
    }
}

void set_volume(int channel, int volume) {
    /* Maximum value for 5 bits of data */
    if (volume > 0x1F) {
        return;
    }

    if (channel == 0) {
        write_psg(8, (UINT8)(volume));
    } else if (channel == 1) {
        write_psg(9, (UINT8)(volume));
    } else if (channel == 2) {
        write_psg(10, (UINT8)(volume));
    } else {
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
    value = *PSG_reg_select;

    Super(old_ssp);


    /* For both if blocks, we handle two other cases, when the value is being turned on or off */
    /* To do this, the specific bits are modified from the CURRENT register value, then writted to the PSG */
    /* This looks slightly complicated, but this is done so that we dont overwrite other registers' settings */
    
    if (channel == 0) {

        if (tone_on == 0) {
            value = value | 0x1;
            write_psg(7, value);
        } else {
            value = value & 0x3E;
            write_psg(7, value);  
        }

        if (noise_on == 0) { 
            value = value | 0x8;
            write_psg(7, value);
        } else {
            value = value & 0x37;
            write_psg(7, value);  
        }

    } else if (channel == 1) {

        if (tone_on == 0) {
            value = value | 0x2;
            write_psg(7, value);
        } else {
            value = value & 0x3D;
            write_psg(7, value);  
        }

        if (noise_on == 00) {
            value = value | 0x10;
            write_psg(7, value);
        } else {
            value = value & 0x2F;
            write_psg(7, value);  
        }

    } else if (channel == 2) {

        if (tone_on == 0){
            value = value | 0x4;
            write_psg(7, value);
        } else {
            value = value & 0x3B;
            write_psg(7, value);  
        }

        if (noise_on == 0) {
            value = value | 0x20;
            write_psg(7, value);
        } else {
            value = value & 0x1F;
            write_psg(7, value);  
        } 

    } else {
        return;
    }
}

void stop_sound() {
    write_psg(8, 0);
    write_psg(9, 0);
    write_psg(10, 0);
}

void set_noise(UINT8 tuning) {
    if (tuning > 0x1F) {
        return;
    }

    write_psg(6, tuning);
}

void set_envelope(UINT8 shape, UINT16 sustain) {
    if (shape > 0xF) {
        return;
    }

    if (sustain > 0xFFFF) {
        return;
    }

    write_psg(13, shape);
    write_psg(11, (sustain & 0xF));
    write_psg(12, (sustain >> 8));
}

UINT8 read_psg(int reg) {
    UINT8 psg_val;
    long old_ssp = Super(0);

    *PSG_reg_select = reg;
    psg_val = *PSG_reg_select;

    Super(old_ssp);

    return psg_val;
}   