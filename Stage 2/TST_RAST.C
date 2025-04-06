#include <osbind.h>
#include "raster.h"
#include "bitmaps.c"

int main()
{
	void *base = Physbase();

	plot_hline(base, 0, 620, 199);
	plot_vline(base, 319, 0, 400);
	
	plot_bitmap32(base, 320, 200, player_bitmap, 32);
	plot_bitmap32(base, 352, 205, alien_maps[0][0], 32);
	plot_bitmap32(base, 384, 205, alien_maps[1][0], 32);
	plot_bitmap32(base, 416, 205, alien_maps[2][0], 32);

	plot_bitmap8(base, 325, 180, bullet_bitmaps[0], 16);
	plot_bitmap8(base, 335, 180, bullet_bitmaps[1], 16);

	plot_bitmap16(base, 345, 180, heart, 16);
	plot_bitmap16(base, 365, 180, broken_heart, 16);

	return 0;
}
