#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/** 
 * @brief Plots and 8xheight bitmap
 * 
 * @param base Pointer to frame buffer address
 * @param x x coordinate to plot
 * @param y y coordinate to plot
 * @param bitmap Bitmap information
 * @param height height of bitmap
 */
void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

/** 
 * @brief Plots and 16xheight bitmap
 * 
 * @param base Pointer to frame buffer address
 * @param x x coordinate to plot
 * @param y y coordinate to plot
 * @param bitmap Bitmap information
 * @param height height of bitmap
 */
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

/** 
 * @brief Plots and 32xheight bitmap
 * 
 * @param base Pointer to frame buffer address
 * @param x x coordinate to plot
 * @param y y coordinate to plot
 * @param bitmap Bitmap information
 * @param height height of bitmap
 */
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

/** 
 * @brief Plots a vertical line
 * 
 * @param base Pointer to frame buffer address
 * @param x x coordinate to plot
 * @param y1 starting y coordinate
 * @param y2 ending y coordinate
 */
void plot_vline(UINT8 *base, int x, int y1, int y2);

/** 
 * @brief Plots a vertical line
 * 
 * @param base Pointer to frame buffer address
 * @param x1 starting x coordinate
 * @param x2 ending x coordinate
 * @param y y coordinate to plot
 */
void plot_hline(UINT8 *base, int x1, int x2, int y);

/** 
 * @brief Plots a character
 * 
 * @param base Pointer to frame buffer address
 * @param font pointer to font map
 * @param ch ASCII value of which character to plot
 * @param x x coordinate to plot
 * @param y y coordinate to plot
 */
void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y);

#endif
