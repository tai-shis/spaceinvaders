#include "music.h"

void start_music() {

    /* First notes */
    set_tone(0, noteTunings[F_SHARP][2]);
    
    set_volume(0, 5);

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
    if ((time_elapsed - time_before) > 12) {
       set_tone(0, song_a[note]); 
       return 1;
    }

    return 0;
}