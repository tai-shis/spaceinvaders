#include <osbind.h>
#include "raster.h"
#include "player.c"

int main()
{
	void *base = Physbase();

	plot_hline(base, 0, 620, 199);
	plot_vline(base, 319, 0, 400);
	
	plot_bitmap32(base, 320, 200, player_bitmap, 32);
	plot_bitmap32(base, 320, 232, alien1_bitmap_1, 32);
	plot_bitmap32(base, 320, 264, alien2_bitmap_1, 32);
	plot_bitmap32(base, 320, 296, alien3_bitmap_1, 32);
	plot_bitmap32(base, 320, 328, mothership, 32);

	return 0;
}
