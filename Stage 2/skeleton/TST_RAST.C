#include <osbind.h>
#include "raster.h"
#include "player.c"

int main()
{
	void *base = Physbase();

	plot_hline(base, 300, 400, 200);
	plot_vline(bsae, 300, 150, 300);
	
	plot_bitmap32(base, 320, 200, player_bitmap, 32);

	return 0;
}
