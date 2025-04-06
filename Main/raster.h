/**
    * @authors Harinder Punia & Tai Shishiba 
    * @file raster.h
    * @brief Header file for raster.c
    * @date 2025-02-04
    * @details Plotting functions for bitmaps, lines, and clearing player and alien areas.
*/

#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/**
 * @brief Plots a 8x(specified height) bitmap on the screen
 * 
 * @param base The base address of the screen
 * @param x The x coordinate of the bitmap
 * @param y The y coordinate of the bitmap
 */
void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

/**
 * @brief Plots a 16x(specified height) bitmap on the screen
 * 
 * @param base The base address of the screen
 * @param x The x coordinate of the bitmap
 * @param y The y coordinate of the bitmap
 */
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

/**
 * @brief Plots a 32x(specified height) bitmap on the screen
 * 
 * @param base The base address of the screen
 * @param x The x coordinate of the bitmap
 * @param y The y coordinate of the bitmap
 */
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

/**
 * @brief Plots a vertical line on the screen
 * 
 * @param base The base address of the screen
 * @param x The x coordinate of the line
 * @param y1 The starting y coordinate of the line
 * @param y2 The ending y coordinate of the line
 */
void plot_vline(UINT8 *base, int x, int y1, int y2);

/**
 * @brief Plots a horizontal line on the screen
 * 
 * @param base The base address of the screen
 * @param x1 The starting x coordinate of the line
 * @param x2 The ending x coordinate of the line
 * @param y The y coordinate of the line
 */
void plot_hline(UINT32 *base, int x1, int x2, int y);

/**
 * @brief Plots a character on the screen
 * 
 * @param base The base address of the screen
 * @param font The font to be used
 * @param ch The character to be plotted
 * @param x The x coordinate of the character
 * @param y The y coordinate of the character
 */
void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y);

/**
 * @brief Plots a custom bitmap on the screen
 * 
 * @param base The base address of the screen
 * @param x The x coordinate of screen
 * @param y The y coordinate of screen
 * @param bitmap The bitmap to be plotted
 * @param height The height of the bitmap
 * @param longWidth The width of the bitmap in long words
 */
void plot_custom(UINT32 *base, int x, int y, const UINT32 *bitmap, int height, int longWidth);

/**
 * @brief Obtains the base address of the screen
 * 
 * @return The base address of the screen
 */
UINT16 *get_video_base();

void set_video_base(UINT16 *address);

#endif
