/**
    * @authors Harinder Punia & Tai Shishiba
    * @file music.h
    * @brief Header file for music.c
    * @date 2025-03-23
    * @details Contains functions for playing music, and updating music.
*/

#ifndef MUSIC_H
#define MUSIC_H
 
#include "psg.h"
 
typedef enum {
  C = 0,
  C_SHARP,
  D,
  D_SHARP,
  E,
  F,
  F_SHARP,
  G,
  G_SHARP,
  A,
  A_SHARP,
  B
} Note;
 
extern const UINT16 noteTunings[12][3];
 
/**
  * @brief Starts the music playback.
*/
void start_music();

/**
  * @brief Updates the music based on the elapsed time and the current note.
  * @param time_elapsed The time elapsed in-game
  * @param time_before The time since the last update.
  * @param note The note index from song array to play.
  * @return Whether or not the note was updated.
*/
char update_music(UINT32 time_now, UINT32 time_before, int note);
 
#endif