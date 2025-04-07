#include "effects.h"
#include "psg.h"

void play_shoot() {
    enable_channel(2, 1, 0); /* Noise for channel C */
    set_tone(2, 0x54);
    set_volume(2, 0x10);
    set_envelope(0x0, 0x0500); 
}

void play_hit() {
    enable_channel(2, 0, 1);
    set_noise(0x1F);
    set_volume(2, 0x10);
    set_envelope(0x0, 0x1500);
}

void play_game_over() {
    enable_channel(2, 1, 0);
    set_tone(2, 0xFF9);
    set_volume(2, 0x10);
    set_envelope(0x9, 0x1800);
}