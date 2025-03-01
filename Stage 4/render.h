#ifndef RENDER_H
#define RENDER_H

#include "model.h"

void render(const Model *model, UINT32 *base, int f);

void render_player(const Player *player, UINT32 *base);

void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);

void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);

void render_bullet(const Bullet *bullet, UINT32 *base);

void render_score(const Score *score, UINT32 *base);
#endif