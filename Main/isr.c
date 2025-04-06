#include "isr.h"
#include <osbind.h>

#define VBL_ISR 28
#define IKBD_ISR 7

extern void vbl_isr();
extern void ikbd_isr();

Vector orig_VBL, orig_IKBD;

void install_vectors() {
    orig_VBL = install_vector(VBL_ISR, do_VBL_ISR);
    orig_IKBD = install_vector(IKBD_ISR, do_IKBD_ISR);
}

void uninstall_vectors() {
    install_vector(VBL_ISR, orig_VBL);
    install_vector(IKBD_ISR, orig_IKBD);
}

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
    static int note_timing = 0;
    static int ticks = 0;
    
    if (in_game == 1) {
        ticks++;
        note_timing++;
        syncBullets();
        if (ticks >= alien_interval) {
            ticks = 0;
            animation_frame++;
            syncHandle();
        }

        if (note_timing >= 30) {
            note_timing = 0;
            note++;
            if(note == 48)
                note = 0;
            update_music(); /* Essentially changes to the next note */
        }
    }   

    render_request = 1;
}

