/**
    * @authors Harinder Punia & Tai Shishiba
    * @file font.h
    * @brief Header file for font.c
    * @date 2025-02-04
    * @details This file contains the font bitmaps for the system font.
*/

#ifndef FONT_H
#define FONT_H

#include "types.h"

extern const UINT8 font[];     /* 8x8 system font */

#define FONT_HEIGHT 8
#define CHAR_BEL    7
#define CHAR_TAB    9
#define CHAR_LF    10
#define CHAR_VT    11
#define CHAR_FF    12
#define CHAR_CR    13
#define CHAR_DEL  127

#define IS_PRINTABLE(i) ((i) >= ' ' && (i) <= '~')
#define GLYPH_START(i) (font + (((i) - ' ') << 3))

#endif
