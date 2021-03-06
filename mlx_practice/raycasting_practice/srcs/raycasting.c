#include "../includes/raycasting.h"

// TEMPORARY WOLRDMAP DEFINEMENT
#define mapWidth 24
#define mapHeight 24


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static double func_deltaDist(double raydir)
{
	return (1 / raydir);
}

static void config_rayinfo(t_cub *cub, int screen_x)
{
	t_rayinfo *ray;

	ray->camerax = (2 * screen_x) / (double)SCREEN_W - 1;
	ray = &(cub->ray);
	ray->raydirx = cub->player.dirx + cub->player.planex * ray->camerax;
	ray->raydiry = cub->player.diry + cub->player.planey * ray->camerax;

	ray->mapx = (int)cub->player.posx;
	ray->mapy = (int)cub->player.posy;
	ray->deltadistx = func_deltaDist(ray->raydirx);
	ray->deltadisty = func_deltaDist(ray->raydiry);
}

static void	set_sidedist(t_cub *cub, double *sideDX, double *sideDY)
{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		*sideDX = (cub->player.posx - cub->ray.mapx) * (cub->ray.deltadistx);
	}
	else
	{
		cub->ray.stepx = 1;
		*sideDX = (cub->ray.mapx + 1.0 - cub->player.posx) * (cub->ray.deltadistx);
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		*sideDY = (cub->player.posy - cub->ray.mapy) * (cub->ray.deltadisty);
	}
	else
	{
		cub->ray.stepy = -1;
		*sideDY = (cub->ray.mapy + 1.0 - cub->player.posy) * (cub->ray.deltadisty);
	}
}

static void	config_hit_wall(t_cub *cub, double sidex, double sidey)
{
	int		is_hit;

	while (is_hit == !HIT)
	{
		if (comp_double(sidey, sidex) > 0)
		{
			sidex += cub->ray.deltadistx;
			cub->ray.mapx += (cub->ray.stepx);
			cub->ray.side = west;
			if (cub->ray.raydirx > 0)
				cub->ray.side = east;
		}
		if (comp_double(sidex, sidey) > 0)
		{
			sidey += cub->ray.deltadisty;
			cub->ray.mapy += (cub->ray.stepy);
			cub->ray.side = south;
			if (cub->ray.raydiry > 0)
				cub->ray.side = north;
		}
		if (worldMap[cub->ray.mapy][cub->ray.mapx] > 0)
			is_hit = HIT;
	}
}

static void	set_perpwalldist(t_cub *cub)
{
	t_rayinfo	*ray;
	int			xweight;
	int			yweight;

	xweight = (1 - ray->stepx) / 2;
	yweight = (1 - ray->stepy) / 2;
	ray = &(cub->ray);
	if (ray->side == north || ray->side == south)
	{
		ray->perpwalldist = \
			(ray->mapx - (cub->player.posx) + xweight) / ray->raydirx;
	}
	else
	{
		ray->perpwalldist = \
			(ray->mapy - (cub->player.posy) + yweight) / ray->raydiry;
	}
}

void		draw_to_buffer(t_cub *cub)
{
	t_img *image;

	cub = cub->img
}

void untextured_rayC(t_cub *cub)
{
	int			screen_x;
	int			isHit;
	t_rayinfo	*ray;
	double sideDistX;
	double sideDistY;

	ray = &(cub->ray);
	isHit = !HIT;
	for (screen_x = 0; screen_x < SCREEN_W; screen_x++)
	{
		config_rayinfo(cub, screen_x);
		set_sidedist(cub, &sideDistX, &sideDistY);
		set_perpwalldist(cub);
	}

}

int		main()
{
	t_cub cub;

	init_cub(&cub);
	untextured_rayC(&cub);
	// 내 이미지를 쓰레드로 돌리는건가?
	mlx_loop(cub.mlx_ptr);
}
