#ifndef RENDER_H
#define RENDER_H

#include "model.h"
#include "raster.h"

void render(const Model *model, void *base, int f);

void render_player(const Player *player, UINT32 *base);

void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);

void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);

void render_bullet(const Bullet *bullet, UINT8 *base);

void render_score(const Score *score, UINT16 *base);
#endif