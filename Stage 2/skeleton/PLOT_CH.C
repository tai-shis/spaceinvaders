#include <linea.h>
#include <osbind.h>
#include <stdio.h>
#include "font.c"
#include "types.h"

void blank_screen();

void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y);

int main()
{
	UINT8 *base = Physbase();
	UINT8 ch;

	blank_screen();
	ch = Cnecin();

	plot_ch(base, font, 1, 0, 0);

	Cnecin();
	return 0;
}

void blank_screen()
{
	printf("\033E\033f\n");     /* VT52: clear screen, hide cursor */
}

void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y) {
	UINT8 *start = base;
	int i;
	start = (start + (y * 80) + (x >> 3)); /* get the start pos*/
	ch = ch * 8;

	for (i = 0; i < 8; i++) {
		*start |= font[ch];
		start += 80;
		ch++;
	}
}