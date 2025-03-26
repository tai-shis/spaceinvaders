/**
    * @authors Harinder Punia & Tai Shishiba
    * @file render.h
    * @brief Header file for render.c
    * @date 2025-02-12
    * @details Functions that render the game objects on the screen.
*/

#ifndef RENDER_H
#define RENDER_H

#include "model.h"
#include "raster.h"

/**
 * @brief Renders a model on the screen
 * 
 * @param model The model to be rendered
 * @param base The base address of the screen
 * @param f The frame to be rendered
 */
void render(const Model *model, void *base, int f);

/**
 * @brief Renders the player on the screen
 * 
 * @param player The player to be rendered
 * @param base The base address of the screen
 */
void render_player(const Player *player, UINT32 *base);

/**
 * @brief Renders an alien on the screen
 * 
 * @param alien The alien to be rendered
 * @param base The base address of the screen
 * @param bitmap The bitmap of the alien
 */
void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);

/**
 * @brief Renders all aliens on the screen (calls render_alien)
 * 
 * @param aliens The aliens to be rendered
 * @param base The base address of the screen
 * @param f The frame to be rendered
 */
void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);

/**
 * @brief Renders a bullet on the screen
 * 
 * @param bullet The bullet to be rendered
 * @param base The base address of the screen
 */
void render_bullet(const Bullet *bullet, UINT8 *base);

/**
 * @brief Renders the current player score on the screen
 * 
 * @param score The score to be rendered
 * @param base The base address of the screen
 */
void render_score(const Score *score, UINT16 *base);

/**
 * @brief Renders the current player lives on the screen
 * 
 * @param lives The number of lives to be rendered
 * @param base The base address of the screen
 */
void render_lives(UINT8 lives, UINT16 *base);
#endif