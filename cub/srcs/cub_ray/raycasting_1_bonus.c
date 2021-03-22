#include "../../includes/raycasting.h"
#include "../../includes/debug.h"
#include "../../includes/x11_key.h"

static void config_rayinfo(t_cub *cub, int screen_x)
{
	t_rayinfo *ray;

	ray = &(cub->ray);
	// needs normalization on camera plane.
	ray->camerax = (2 * screen_x) / (double)cub->screen_x - 1;
	// ray's direction vector == dir vector + plane vector * ratio
	ray->raydirx = cub->player.dirx + cub->player.planex * ray->camerax;
	ray->raydiry = cub->player.diry + cub->player.planey * ray->camerax;

	ray->mapx = (int)cub->player.posx;
	ray->mapy = (int)cub->player.posy;
	ray->deltadistx = func_deltadist(ray->raydirx);
	ray->deltadisty = func_deltadist(ray->raydiry);
}

static void	set_sidedist(t_cub *cub, double *sidedx, double *sidedy)
{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		*sidedx = (cub->player.posx - cub->ray.mapx) * (cub->ray.deltadistx);
	}
	else
	{
		cub->ray.stepx = 1;
		*sidedx = (cub->ray.mapx + 1.0 - cub->player.posx) * (cub->ray.deltadistx);
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		*sidedy = (cub->player.posy - cub->ray.mapy) * (cub->ray.deltadisty);
	}
	else
	{
		cub->ray.stepy = 1;
		*sidedy = (cub->ray.mapy + 1.0 - cub->player.posy) * (cub->ray.deltadisty);
	}
}

static void	config_hit_wall(t_cub *cub, double *sidex, double *sidey)
{
	int		is_hit;

	is_hit = !HIT;
	while (is_hit != HIT)
	{
		//if (comp_double(*sidey, *sidex) > 0)
		if (*sidey > *sidex)
		{
			*sidex += cub->ray.deltadistx;
			cub->ray.mapx += (cub->ray.stepx);
			cub->ray.side = east;
			if (cub->ray.raydirx > 0)
				cub->ray.side = west;
		}
		else
		{
			*sidey += cub->ray.deltadisty;
			cub->ray.mapy += (cub->ray.stepy);
			cub->ray.side = north;
			if (cub->ray.raydiry > 0)
				cub->ray.side = south;
		}
		if (cub->map.map[cub->ray.mapy][cub->ray.mapx] == '1')
			is_hit = HIT;
	}
}

static void	set_perpwalldist(t_cub *cub)
{
	t_rayinfo	*ray;
	int			xweight;
	int			yweight;

	ray = &(cub->ray);
	xweight = (1 - ray->stepx) / 2;
	yweight = (1 - ray->stepy) / 2;
	if (ray->side == east || ray->side == west)
	{
		ray->perpwalldist = \
			(ray->mapx - (cub->player.posx) + xweight) / ray->raydirx;
	}
	else if (ray->side == south || ray->side == north)
	{
		ray->perpwalldist = \
			(ray->mapy - (cub->player.posy) + yweight) / ray->raydiry;
	}
}

int untextured_rayc(t_cub *cub, int argc)
{
	int			screen_x;
	int			color;
	double sidedistx;
	double sidedisty;

	//draw_simple_floor_ceiling(cub);
	ceiling_floor_rayc(cub);
	for (screen_x = 0; screen_x < cub->screen_x; screen_x++)
	{
		config_rayinfo(cub, screen_x);
		set_sidedist(cub, &sidedistx, &sidedisty);
		config_hit_wall(cub, &sidedistx, &sidedisty);
		set_perpwalldist(cub);
		draw_img_line_textured(cub, screen_x);
		cub->perp_buff[screen_x] = cub->ray.perpwalldist;
		//draw_img_line_untxt(cub, screen_x);
	}
	sprite_rayc(cub);
	if (argc == 3)
		return (0);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img.img_ptr, 0, 0);
	take_action(cub);
	return (0);
}
