#include <osbind.h>
#include "raster.h"
#include "player.c"

int main()
{
	void *base = Physbase();

	plot_hline(base, 0, 620, 199);
	plot_vline(base, 319, 0, 400);
	
	plot_bitmap32(base, 320, 200, player_bitmap, 32);

	return 0;
}
