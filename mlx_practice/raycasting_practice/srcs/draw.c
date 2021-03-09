#include "../includes/raycasting.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"

void	draw_simple_floor_ceiling(t_cub *cub)
{
#if DEBUG_LEVEL >= 0
	printf("draw_simple_floor_ceiling START\n");
#endif
	int		screen_x;
	int		floor_h;
	int		ceiling_h;
	int		half_height;

	half_height = SCREEN_H / 2;
	screen_x = 0;
	floor_h = 0;
	ceiling_h = half_height;
	while (screen_x < SCREEN_W)
	{
		while (floor_h < half_height)
		{
			buff_drawer(cub, screen_x, floor_h, COLOR_FLOOR);
			buff_drawer(cub, screen_x, ceiling_h, COLOR_CEILING);
			floor_h++;
			ceiling_h++;
		}
		screen_x++;
		floor_h = 0;
		ceiling_h = half_height;

	}
}
