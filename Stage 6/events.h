/**
    * @authors Harinder Punia & Tai Shishiba
    * @file events.h
    * @brief Header file for events.c
    * @date 2025-02-12
    * @details Functions to handle player movement, shooting, aliens movement, bullets movement and collisions, and game end conditions.
*/

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/**
 * @brief Handles player movement based on the key pressed
 * 
 * @param model The game model to be updated
 * @param key The key pressed
 */
void async_move_player(Model *model, char key);

/**
 * @brief Handles player shooting
 * 
 * @param model The game model to be updated
 * @param cooldown The cooldown of the player's weapon
 */
void async_shoot(Model *model, int cooldown);

/**
 * @brief Makes aliens shoot
 * 
 * @param model The game model to be updated
 */
void aliens_shoot(Model *model);

/**
 * @brief Updates the aliens positions and checks boundaries
 * 
 * @param model The game model to be updated
 */
int update_aliens(Model *model);

/**
 * @brief Updates the bullets positions and checks for collisions
 * 
 * @param model The game model to be updated
 */
void update_bullets(Model *model);

/**
 * @brief Resets aliens classes to their original positions
 * 
 * @param model The game model to be updated
 */
void respawn_aliens(Model *model);

/**
 * @brief Checks if the game has ended
 * 
 * @param model The game model to be updated
 */
int check_endgame(Model *model);

/**
 * @brief Returns a random number
 */
int rand();

#endif