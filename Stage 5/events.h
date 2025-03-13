#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

void async_move_player(Model *model, char key);

void async_shoot(Model *model, int cooldown);

int update_aliens(Model *model);

void update_bullets(Model *model);

int check_endgame(Model *model);

#endif