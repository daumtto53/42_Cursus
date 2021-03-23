/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:39:01 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 14:33:22 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/debug.h"
#include "../../includes/x11_key.h"

static void	config_rayinfo_b(t_cub *cub, int screen_x)
{
	t_rayinfo *ray;

	ray = &(cub->ray);
	ray->camerax = (2 * screen_x) / (double)cub->screen_x - 1;
	ray->raydirx = cub->player.dirx + cub->player.planex * ray->camerax;
	ray->raydiry = cub->player.diry + cub->player.planey * ray->camerax;
	ray->mapx = (int)cub->player.posx;
	ray->mapy = (int)cub->player.posy;
	ray->deltadistx = func_deltadist(ray->raydirx);
	ray->deltadisty = func_deltadist(ray->raydiry);
}

static void	set_sidedist_b(t_cub *cub, double *sidedx, double *sidedy)
{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		*sidedx = (cub->player.posx - cub->ray.mapx) * (cub->ray.deltadistx);
	}
	else
	{
		cub->ray.stepx = 1;
		*sidedx = (cub->ray.mapx + 1.0 - cub->player.posx) * \
			(cub->ray.deltadistx);
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		*sidedy = (cub->player.posy - cub->ray.mapy) * (cub->ray.deltadisty);
	}
	else
	{
		cub->ray.stepy = 1;
		*sidedy = (cub->ray.mapy + 1.0 - cub->player.posy) * \
			(cub->ray.deltadisty);
	}
}

static void	config_hit_wall_b(t_cub *cub, double *sidex, double *sidey)
{
	int		is_hit;

	is_hit = !HIT;
	while (is_hit != HIT)
	{
		if (*sidey > *sidex)
		{
			*sidex += cub->ray.deltadistx;
			cub->ray.mapx += (cub->ray.stepx);
			cub->ray.side = west;
			if (cub->ray.raydirx > 0)
				cub->ray.side = east;
		}
		else
		{
			*sidey += cub->ray.deltadisty;
			cub->ray.mapy += (cub->ray.stepy);
			cub->ray.side = south;
			if (cub->ray.raydiry > 0)
				cub->ray.side = north;
		}
		if (cub->map.map[cub->ray.mapy][cub->ray.mapx] == '1')
			is_hit = HIT;
	}
}

static void	set_perpwalldist_b(t_cub *cub)
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

int			untextured_rayc(t_cub *cub, int argc)
{
	int			screen_x;
	double		sidedistx;
	double		sidedisty;

	ceiling_floor_rayc(cub);
	screen_x = -1;
	while (++screen_x < cub->screen_x)
	{
		config_rayinfo_b(cub, screen_x);
		set_sidedist_b(cub, &sidedistx, &sidedisty);
		config_hit_wall_b(cub, &sidedistx, &sidedisty);
		set_perpwalldist_b(cub);
		draw_img_line_textured(cub, screen_x);
		cub->perp_buff[screen_x] = cub->ray.perpwalldist;
	}
	sprite_rayc(cub);
	if (argc == 3)
		return (0);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img.img_ptr, 0, 0);
	take_action(cub);
	return (0);
}
