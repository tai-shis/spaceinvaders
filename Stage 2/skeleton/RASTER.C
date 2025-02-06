#include "raster.h"

void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height) { /* Could replace the height to constant value in func? */
	int i;
	UINT8 *start = base;
	start = (start + (x * 80) + (y >> 3));

	for (i = 0; i < height; i += 1) {
		*start |= bitmap[i];
		start += 80;
	}
}

void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height) {
	int i;
	UINT16 *start = base;
	start = (start + (x * 40) + (y >> 4));

	for (i = 0; i < height; i += 1) {
		*start |= bitmap[i];
		start += 40;
	}
}

void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height) {
	int i;
	UINT32 *start = base;
	start = (start + (x * 20) + (y >> 5));

	for (i = 0; i < height; i += 1) {
		*start |= bitmap[i];
		start += 20;
	}
}

void plot_vline (UINT8 *base, int x, int y1, int y2){
	int temp;
	UINT8 pattern;
	UINT8 *screen_byte;

	if (x >= 0 && x < 640) { /* Make sure x is in bounds */
		/* If line call with y is backwards, flip */
		if (y1 > y2) { 
			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		/* If y1 exceeds lower bounds, set to lower bound */
		if (y1 < 0) {
			y1 = 0;
		}

		/* If y2 exceeds upper bounds, set to upper bound */
		if (y2 > 399) {
			y2 = 399;
		}

		pattern = 1 << (7 - (x & 7));
		screen_byte = base + y1 * 80 + (x >> 3);

		/* For loop taken from tutorial 4 */
		for ( ; y1 <= y2; y1++) {
			*screen_byte = pattern;
			screen_byte = screen_byte + 80;
		}
	}
	return;
}

void plot_hline(UINT8 *base, int x1, int x2, int y) {
	/* Essentially very similar to plot_vline func */
	int temp;
	UINT8 start;
	UINT8 end;
	UINT8 *screen_byte;
	UINT8 *line_end;

	if (y >= 0 && y < 400) { /* Make sure y is in bounds */
		/* If line call with x is backwards, flip */
		if (x1 > x2) {
			temp = x1;
			x1 = x2;
			x2 = temp;
		}

		/* If x1 exceeds lower bounds, set to lower bound */
		if (x1 < 0) {
			x1 = 0;
		}

		/* If x2 exceeds upper bounds, set to upper bound */
		if (x2 > 639) {
			x2 = 639;
		}

		/* THIS DOES NOT COVER THE CASE WHERE x2-x1 IS < 8 */
		start = 0xFF >> (x1 & 7);
		end = 0xFF << (7 - (x2 & 7));
		screen_byte = base + y * 80 + (x1 >> 3);
		line_end = base + y * 80 + (x2 >> 3); /* End address (rounded down by 8) */

		/* Plot start line */
		*screen_byte = start;	
		screen_byte += 8;

		/* Plot 0xFFs */
		while (screen_byte < line_end) {
			*screen_byte = 0xFF;
			screen_byte += 8;
		}
		
		/* Plot end line */
		*screen_byte = end;
	}
	return;
}