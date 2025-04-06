#include "isr.h"
#include <osbind.h>

extern Model model;
extern unsigned int note;
extern int alienInterval;

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
    static int ticks
    ticks++;
    note_timing++;
    
    syncBullets(&model);
    if (ticks == alienInterval) {
        ticks = 0;
        animation_frame++;
        syncHandle(&model);
    }

    if (note_timing == 100) {
        note_timing = 0;
        note++;
        update_music(); /* Essentially changes to the next note */
    }

    render_request = 1;
}