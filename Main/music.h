#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"

const int song_a[48] {
    /* Fallen Down from undertale */
    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],
    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],
    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],

    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],
    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],
    noteTunings[F_SHARP][2],
    noteTunings[C_SHARP][2],

    noteTunings[B][1],
    noteTunings[A][1],
    noteTunings[C_SHARP][2],
    noteTunings[C_SHARP][2],
    noteTunings[A][1],
    noteTunings[B][1],

    noteTunings[E][2],
    noteTunings[D_SHARP][2],
    noteTunings[E][2],
    noteTunings[F_SHARP][2],
    noteTunings[D_SHARP][2],
    noteTunings[B][1],

    noteTunings[F_SHARP][2],
    noteTunings[B][1],
    noteTunings[F_SHARP][2],
    noteTunings[B][1],
    noteTunings[F_SHARP][2],
    noteTunings[B][1],

    noteTunings[F_SHARP][2],
    noteTunings[A_SHARP][1],
    noteTunings[F_SHARP][2],
    noteTunings[A_SHARP][1],
    noteTunings[G][2],
    noteTunings[G][2],

    noteTunings[F_SHARP][2],
    noteTunings[D][2],
    noteTunings[F_SHARP][2],
    noteTunings[D][2],
    noteTunings[E][2],
    noteTunings[F_SHARP][2],

    noteTunings[E][2],
    noteTunings[E][2],
    noteTunings[D][2],
    noteTunings[D][2],
    noteTunings[C_SHARP][2],
    noteTunings[C_SHARP][2],
};

void start_music();

char update_music(UINT32 time_elapsed, UINT32 time_before, int note);

#endif