#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/**
 * @brief Handles player movement
 * 
 * @param model Pointer to the game model
 * @param key Character indicating the direction ('l' for left, 'r' for right)
 */
void async_move_player(Model *model, char key);

/**
 * @brief Handles shooting bullets
 * 
 * @param model Pointer to the game model
 * @param cooldown Cooldown period for shooting
 */
void async_shoot(Model *model, int cooldown);

/**
 * @brief Updates the position of aliens
 * 
 * @param model Pointer to the game model
 * @return int Status of the update operation
 */
int update_aliens(Model *model);

/**
 * @brief updates the position of bullets
 * 
 * @param model Pointer to the game model
 */
void update_bullets(Model *model);

#endif