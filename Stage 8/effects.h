/**
    * @authors Harinder Punia & Tai Shishiba
    * @file effects.h
    * @brief Header file for effects.c
    * @date 2025-03-23
    * @details Contains functions for shooting, bullet collision, and game over sound effects.
*/

#ifndef EFFECTS_H
#define EFFECTS_H

#include "psg.h"

/**
* @brief Plays the shooting sound effect.
*/
void play_shoot();

/**
* @brief Plays the bullet hit sound effect.
*/
void play_hit();

/**
* @brief Plays the game over sound effect.
*/
void play_game_over();

#endif