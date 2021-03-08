#include "../includes/raycasting.h"
#include "../includes/debug.h"

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
