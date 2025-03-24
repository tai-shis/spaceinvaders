#ifndef GAME_H
#define GAME_H

#include "render.h"
#include "types.h"
#include "events.h"
#include "model.h"
#include "raster.h"
#include "input.h"
#include "psg.h"
#include "music.h"

void asyncHandle(Model *model);

void syncHandle(Model *model, UINT32 timeElapsed);

void swapBuffers (void **active, void **inactive);

UINT32 getTime();

#endif