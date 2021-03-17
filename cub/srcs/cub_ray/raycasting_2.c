#include "../../includes/raycasting.h"
#include "../../includes/debug.h"
#include "../../includes/x11_key.h"

static void	init_ceilfloor(t_cub *cub, t_ceilfloor *cf, int y)
{
	cf->raydirx0 = cub->player.dirx - cub->player.planex;
	cf->raydirx1 = cub->player.dirx + cub->player.planex;
	cf->raydiry0 = cub->player.diry - cub->player.planey;
	cf->raydiry1 = cub->player.diry + cub->player.planey;
	cf->standardy = y - cub->screen_y / 2;
	cf->rowdistance = (cub->screen_y * 0.5) / cf->standardy;
	cf->stepx = cf->rowdistance * (cf->raydirx1 - cf->raydirx0) / cub->screen_x;
	cf->stepy = cf->rowdistance * (cf->raydiry1 - cf->raydiry0) / cub->screen_x;
	cf->ceilfloorx = cub->player.posx + cf->rowdistance * cf->raydirx0;
	cf->ceilfloory = cub->player.posy + cf->rowdistance * cf->raydiry0;
}

void	ceiling_floor_rayc(t_cub *cub)
{
	t_ceilfloor cf;
	int y;
	int	x;
	unsigned int	color_floor;
	unsigned int	color_ceil;

	y = -1;
	while (++y < cub->screen_y)
	{
		init_ceilfloor(cub, &cf, y);
		x = -1;
		while (++x < cub->screen_x)
		{
			cf.cellx = (int)(cf.ceilfloorx);
			cf.celly = (int)(cf.ceilfloory);
			cf.texx = (int)(TEXTURE_W * (cf.ceilfloorx - cf.cellx)) & (TEXTURE_W - 1);
			cf.texy = (int)(TEXTURE_H * (cf.ceilfloory - cf.celly)) & (TEXTURE_H - 1);
			cf.ceilfloorx += cf.stepx;
			cf.ceilfloory += cf.stepy;
			color_floor = cub->tex_arr[TEXTURE_FLOOR][TEXTURE_W * cf.texy + cf.texx];
			buff_drawer(cub, x, y, color_floor);
			color_ceil = cub->tex_arr[TEXTURE_CEILING][TEXTURE_W * cf.texy + cf.texx];
			buff_drawer(cub, x, cub->screen_y - 1 - y, color_ceil);
		}
	}
}
