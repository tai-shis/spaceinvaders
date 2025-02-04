#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/* [TO DO] the functions below are examples. Replace them! */

void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

void plot_vline(UINT8 *base, int x, int y1, int y2);

void plot_hline(UINT8 *base, int x1, int x2, int y);

#endif
