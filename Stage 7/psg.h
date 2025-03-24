#ifndef PSG_H
#define PSG_H

#include "TYPES.H"

void write_psg(int reg, UINT8 val);

void set_tone(int channel, int tuning);

void set_volume(int channel, int volume);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_noise(UINT8 tuning);

void set_envelope(UINT8 shape, UINT16 sustain);

UINT8 read_psg(int reg);

#endif