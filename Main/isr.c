#include "isr.h"
#include <osbind.h>


Vector install_vector(int num, Vector vector) {
    Vector orig;
    Vector *vectp = (Vector*)((long)num << 2);
    long oldSsp = Super(0);
    orig = *vectp;
    *vectp = vector;
    Super(oldSsp);
    return orig;
}

void do_VBL_ISR() {
    static int note_timing;
    static int ticks;
    
    if (play == 0) {
        ticks++;
        note_timing++;
        syncBullets();
        if (ticks == alien_interval) {
            ticks = 0;
            animation_frame++;
            syncHandle();
        }

        if (note_timing == 100) {
            note_timing = 0;
            note++;
            if(note == 48)
                note = 0;
            update_music(); /* Essentially changes to the next note */
        }
    }   

    render_request = 1;
}
