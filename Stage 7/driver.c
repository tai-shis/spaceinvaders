/**
    * @file     driver.c
    * @brief    Test driver file for Stage 7
    * @date     2025-03-25
    * @details  Tests all functionality for psg and effects. Does not test for music as it relies on timing which is done in Stage 5's game code.
*/

#include "music.h"
#include "effects.h"

#include <osbind.h>
#include <stdio.h>

#define yield while(!Cconis()){} Cnecin();

int main() {
    printf("Press any key to play shoot sound effect.\n");
    yield;
    play_shoot();
    printf("%d\n", read_psg(7));
    
    printf("Press any key to play hit sound effect.\n");
    yield;
    play_hit();
    printf("%d\n", read_psg(7));

    printf("Press any key to play game over sound effect.\n");
    yield;
    play_game_over();

    printf("Press any key to play a C.\n");
    yield;
    enable_channel(0, 1, 0);
    set_tone(0, noteTunings[C][0]);
    set_volume(0, 0x4);
    printf("%d\n", read_psg(0));

    printf("Press any key to play an E on top.\n");
    yield;
    enable_channel(1, 1, 0);
    set_tone(1, noteTunings[E][0]);
    set_volume(1, 0x4);
    printf("%d\n", read_psg(1));

    printf("Press any key to play a G on top.\n");
    yield;
    enable_channel(2, 1, 0);
    set_tone(2, noteTunings[G][0]);
    set_volume(2, 0x4);

    printf("Press any key to raise only the C volume.\n");
    yield;
    set_volume(0, 0x6);

    printf("Press any key to raise only the E volume.\n");
    yield;
    set_volume(0, 0x04);
    set_volume(1, 0x06);

    printf("Press any key to raise only the G volume.\n");
    yield;
    set_volume(0, 0x04);
    set_volume(1, 0x04);
    set_volume(2, 0x06);

    printf("Press any key to turn off G.\n");
    yield;
    enable_channel(2, 0, 0);

    printf("Press any key to turn off E.\n");
    yield;
    enable_channel(1, 0, 0);

    printf("Press any key to turn off C.\n");
    yield;
    enable_channel(0, 0, 0);

    printf("Press any key to play ambient wave noises.\n");
    yield;
    set_noise(0x8);
    enable_channel(0, 0, 1);
    set_volume(0, 0x10);
    set_envelope(0xE, 0x4F00);

    printf("Press any key to stop sound.\n");
    yield;
    stop_sound();

    printf("Press any key to finish tests.\n");
    yield;

    return 0;
}