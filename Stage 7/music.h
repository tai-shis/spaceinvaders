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

typedef enum{
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

const UINT16 noteTunings[12][3] = {
    /* Goes note->octave */
    /* Aren't enharmonic equivalents fun? */
    /* My entire childhood of doing music is going to good use */
    {{0x03BE}, {0x01DC},  {0x00EF}}, /* C3 - C5 */ 
    {{0x0387}, {0x01C3},  {0x00E1}}, /* C#3 - C#5*/ /* C# == Db */
    {{0x0354}, {0x01A9},  {0x00D5}}, /* D3 - D5 */ /* D# == Eb */
    {{0x0324}, {0x0192},  {0x00C8}}, /* D#3 - D#5*/ /* G# == Ab */
    {{0x02F8}, {0x017B},  {0x00BD}}, /* E3 - E5 */ /* E# == F */
    {{0x02CC}, {0x0164},  {0x00B2}}, /* F3 - F5*/ 
    {{0x02A5}, {0x0150},  {0x00A8}}, /* F#3 - F#5*/ /* F# == Gb */
    {{0x027E}, {0x013E},  {0x009F}}, /* G3 - G5*/
    {{0x025A}, {0x012D},  {0x0096}}, /* G#3 - G#5*/ /* G# == Ab */
    {{0x0239}, {0x011B},  {0x008E}}, /* A3 - A5*/
    {{0x0219}, {0x010A},  {0x0085}}, /* A#3 - A#5*/ /* A# == Bb */
    {{0x01FA}, {0x00FD},  {0x007E}}, /* B3 - B5*/
}; 

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
char update_music(UINT32 time_elapsed, UINT32 time_before, int note);

#endif