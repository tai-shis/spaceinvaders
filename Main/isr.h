#ifndef ISR_H
#define ISR_H

#include "music.h"
#include "space.c"

typedef void (*Vector)();

Vector install_vector(int num, Vector vector);

void do_VBL_ISR();

#endif