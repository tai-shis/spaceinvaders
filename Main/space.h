/**
    * @authors Harinder Punia & Tai Shishiba
    * @file spaceInvaders.h
    * @brief Header file for spaceInvaders.c
    * @date 2025-02-25
    * @details Functions for handling player input, synchrounous game logic, double buffering, and getting clock time.
*/

#ifndef SPACE_H
#define SPACE_H

#include <stdio.h>
#include <osbind.h>

#include "render.h"
#include "types.h"
#include "events.h"
#include "model.h"
#include "raster.h"
#include "input.h"
#include "psg.h"
#include "music.h"

/**
 * @brief Handles asynchronous events
 * 
 * @param model The game model to be updated
 */
void asyncHandle(Model *model);

/**
 * @brief Handles synchronous events
 * 
 * @param model The game model to be updated
 * @param timeElapsed The time elapsed since the last frame
 */
void syncHandle(Model *model, UINT32 timeElapsed);

/**
 * @brief Updates the bullets in the game
 * 
 * @param model The game model to be updated
 */
void syncBullets(Model *model);

/**
 * @brief Swaps the active and inactive buffers
 * 
 * @param active The active buffer
 * @param inactive The inactive buffer
 */
void swapBuffers (void **active, void **inactive);

/**
 * @brief Reads the clock to get the current time
 */
UINT32 getTime();

#endif