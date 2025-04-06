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

extern char keyboard_buffer[256];
extern int buffer_index, buffer_fill;

void do_IKBD_ISR();

void add_to_buffer(char ch);