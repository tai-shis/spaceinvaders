#include "raster.h"
#include <osbind.h>


void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height) { /* Could replace the height to constant value in func? */
	int i;
	UINT8 *start = base;
	start = (start + (y * 80) + (x >> 3));

	for (i = 0; i < height; i++) {
		*start |= (bitmap[i] >> (x & 7));
		if ((x & 7) > 0) {
			*(start + 1) |= (bitmap[i] << (8 - (x & 7)));
		}
		start += 80;
	}
}

void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height) {
	int i;
	UINT16 *start = base;
	start = (start + (y * 40) + (x >> 4));

	for (i = 0; i < height; i++) {
		*start |= (bitmap[i] >> (x & 15));
		if ((x & 15) > 0) {
			*(start + 1) |= (bitmap[i] << (16 - (x & 15)));
		}
		start += 40;
	}
}

void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height) {
	int i;
	UINT32 *start = base;
	start = (start + (y * 20) + (x >> 5));

	for (i = 0; i < height; i++) {
		*start |= (bitmap[i] >> (x & 31));
		if ((x & 31) > 0) {
			*(start + 1) |= (bitmap[i] << (32 - (x & 31)));
		}
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
			*screen_byte |= pattern;
			screen_byte = screen_byte + 80;
		}
	}
	return;
}

void plot_hline(UINT32 *base, int x1, int x2, int y) {
	/* Essentially very similar to plot_vline func */
	int temp;
	UINT8 start;
	UINT8 end;
	UINT32 *screen_long;
	UINT32 *line_end;

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
		start = 0xFF >> ((x1 & 31));
		end = 0xFF << (31 - (x2 & 31));
		screen_long = base + y * 20 + (x1 >> 5);
		line_end = base + y * 20 + ((x2 + 31) >> 5); /* End address (adjusted for remaining bits) */

		/* Plot start line */
		*screen_long = start;

		/* Plot 0xFFs */
		while (screen_long < line_end) {
			*screen_long |= 0xFFFFFFFF;
			screen_long++;
		}
		
		/* Plot end line */
		*screen_long = end;
	}
	return;
}

/* for 8 bit font sizes */
void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y) {
	UINT8 *start = base;
	int i;
	start = (start + (y * 80) + (x >> 3)); /* get the start pos*/
	ch = ch * 8; /* index in font map */

	for (i = 0; i < 8; i++) {
		*start |= font[ch];
		start += 80;
		ch++;
	}
}

void plot_custom(UINT32 *base, int x, int y, const UINT32 *bitmap, int height, int longWidth) {
	int i,j,k = 0;
	UINT32 *start = base;
	start += ((y * 20) + (x >> 5));

	for (i = 0; i < height; i++) {

		for (j = 0; j < longWidth; j++) {
			*(start + (i * 20) + j) |= (bitmap[k] >> (x & 31));
			if ((x & 31) > 0) {
				*(start + (i * 20) + j + 1) |= (bitmap[k] << (32 - (x & 31)));
			}
			k++;
		}
	}
}

UINT16 *get_video_base() {
	UINT8 *vid_hi = 0xFF8201;
	UINT8 *vid_mi = 0xFF8203;
	UINT32 vid_base;
	UINT32 oldSsp;
	int isr = Super(1);

    if(!isr)
        oldSsp = Super(0);

	vid_base = ((UINT32)*vid_hi);
	vid_base = vid_base << 8;
	vid_base |= ((UINT32)*vid_mi);
	vid_base = vid_base << 8;

	if(!isr)
		Super(oldSsp);

	return (UINT16 *)vid_base;
}
