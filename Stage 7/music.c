#include "music.h"

UINT16 song_a[48][2] = {
    /* Fallen Down from undertale */
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    
    {B, 1},
    {A, 1},
    {C_SHARP, 2},
    {C_SHARP, 2},
    {A, 1},
    {B, 1},
    
    {E, 2},
    {D_SHARP, 2},
    {E, 2},
    {F_SHARP, 2},
    {D_SHARP, 2},
    {B, 1},
    
    {F_SHARP, 2},
    {B, 1},
    {F_SHARP, 2},
    {B, 1},
    {F_SHARP, 2},
    {B, 1},
    
    {F_SHARP, 2},
    {A_SHARP, 1},
    {F_SHARP, 2},
    {A_SHARP, 1},
    {G, 2},
    {G, 2},
    
    {F_SHARP, 2},
    {D, 2},
    {F_SHARP, 2},
    {D, 2},
    {E, 2},
    {F_SHARP, 2},
    
    {E, 2},
    {E, 2},
    {D, 2},
    {D, 2},
    {C_SHARP, 2},
    {C_SHARP, 2}
};

void start_music() {

    /* First notes */
    set_tone(0, noteTunings[F_SHARP][2]);
    
    set_volume(0, 0xA);

    enable_channel(0, 1, 0);
    

    /* Disabled for now */
    /*
    set_tone(1, noteTunings[B][1]);
    set_volume(1, 5);
    enable_channel(1, 1, 0);
    */
}

char update_music(UINT32 time_elapsed, UINT32 time_before, int note) {
    

    /* 3/4 Time Signature, updates every 1/8th note */
    if ((time_elapsed - time_before) > 20) {
       set_tone(0, noteTunings[song_a[note][0]][song_a[note][1]]); 
       return 1;
    }

    return 0;
}