/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:37:51 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 00:38:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

static void	init_mlx(t_cub *cub, t_conf *conf)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	mlx_get_screen_size(cub->mlx_ptr, &cub->screen_x, &cub->screen_y);
	if (conf->resolution_w < cub->screen_x)
		cub->screen_x = conf->resolution_w;
	if (conf->resolution_h < cub->screen_y)
		cub->screen_y = conf->resolution_h;
	cub->win = mlx_new_window(cub->mlx_ptr, cub->screen_x, \
			cub->screen_y, "TITLE");
	if (cub->win == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
}

static void	init_img(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, \
		cub->screen_x, cub->screen_y);
	if (cub->img.img_ptr == NULL)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	cub->img.img_buff = \
		(int *)mlx_get_data_addr(cub->img.img_ptr, \
			&cub->img.bpp, &cub->img.linelen, &cub->img.endian);
	if (cub->img.img_buff == NULL)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	cub->img.img_h = cub->screen_y;
	cub->img.img_w = cub->screen_x;
}

static void	init_player(t_cub *cub, t_conf *conf)
{
	cub->player.dirx = 0.0;
	cub->player.diry = 0.0;
	cub->player.posx = conf->posx;
	cub->player.posy = conf->posy;
	cub->player.planex = 0.0;
	cub->player.planey = 0.0;
	if (conf->dir == 'N')
		cub->player.diry = 1.0;
	else if (conf->dir == 'S')
		cub->player.diry = -1.0;
	else if (conf->dir == 'W')
		cub->player.dirx = -1.0;
	else
		cub->player.dirx = 1.0;
	if (conf->dir == 'N')
		cub->player.planex = 0.66;
	else if (conf->dir == 'S')
		cub->player.planex = -0.66;
	else if (conf->dir == 'W')
		cub->player.planey = 0.66;
	else
		cub->player.planey = -0.66;
	cub->player.keypress_flag = 0;
}

static void	init_map(t_cub *cub, t_conf *conf)
{
	cub->map.map = conf->dyn.map;
	cub->map.map_h = conf->map_h;
	cub->map.map_w = conf->map_w;
}

void		init_cub(t_cub *cub, t_conf *conf)
{
	double	*perpbuff;

	init_mlx(cub, conf);
	init_img(cub);
	perpbuff = (double *)ft_calloc(cub->screen_x, sizeof(double));
	if (!perpbuff)
	{
		print_err(CUSTOM_ERR_MALLOC_FAIL);
		exit(0);
	}
	cub->perp_buff = perpbuff;
	cub->color_ceil = conf->color_ceil;
	cub->color_floor = conf->color_floor;
	init_player(cub, conf);
	init_map(cub, conf);
	load_texture(cub, conf);
	init_sprite(cub);
}
