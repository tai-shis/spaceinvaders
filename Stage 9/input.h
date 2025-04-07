/**
    * @authors Harinder Punia & Tai Shishiba
    * @file input.h
    * @brief Header file for input.c
    * @date 2025-02-25
    * @details Function to handle keyboard input.
*/
#ifndef INPUT_H
#define INPUT_H

#include "types.h"
#include <osbind.h>

/**
 * @brief Function to get a keystroke from the keyboard.
 */
char keystroke();

/**
 * @brief Function to handle the keyboard/mouse ISR.
 */
void do_IKBD_ISR();

/**
 * @brief Function to add a character to the character buffer.
 * 
 * @param ch The character to be added to the buffer.
 */
void add_to_buffer(char ch);

#endif