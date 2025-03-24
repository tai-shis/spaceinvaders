#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"

void start_music();

char update_music(UINT32 time_elapsed, UINT32 time_before, int note);

#endif