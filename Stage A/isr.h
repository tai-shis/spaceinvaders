#ifndef ISR_H
#define ISR_H

#include "music.h"
#include "space.h"
#include "types.h"
#include "input.h"
#include "raster.h"

void uninstall_vectors();

void install_vectors();

Vector install_vector(int num, Vector vector);

void do_VBL_ISR();

#endif