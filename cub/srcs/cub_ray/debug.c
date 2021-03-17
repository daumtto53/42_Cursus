#include "../../includes/raycasting.h"

void	debug_rayinfo(t_cub *cub)
{
	t_rayinfo *i = &(cub->ray);

	printf("camerax : %lf\nraydirx : %lf, raydiry : %lf\n \
			perpwalldist : %lf\n\
			deltadistx, deltadisty : %lf %lf\n\
			side : %d\n\
			mapx : %d, mapy : %d, stepx : %d, stepy : %d\n",\
			i->camerax, i->raydirx, i->raydiry, i->perpwalldist,\
			i->deltadistx, i->deltadisty, i->side, i->mapx, i->mapy, i->stepx, i->stepy);
}

void	debug_config_hit_wall(t_cub *cub, double sx, double sy)
{
	t_rayinfo *i = &(cub->ray);

	printf("side : %d, mapx : %d, mapy : %d\n\
	sidex : %lf, sidey %lf\n", i->side, i->mapx, i->mapy, sx, sy);
}

void	debug_print_buffer(t_cub *cub)
{
	int i, j;
	int *img_map = cub->img.img_buff;

	for (i = 0; i < cub->screen_y; i++)
	{
		for (j = 0; j < cub->screen_x; j++)
		{
			printf("%#x ", img_map[cub->screen_x * i + j]);
		}
		printf("\n");
	}
}

void	debug_texture_rgb(t_cub *cub, int tex_num)
{
	int i, j;
	int *tex_map = cub->tex_arr[tex_num];

	for (i = 0; i < TEXTURE_H; i++)
	{
		for (j = 0; j < TEXTURE_W; j++)
		{
			printf("%#x ", tex_map[TEXTURE_W * i + j]);
		}
		printf("\n");
	}
}
