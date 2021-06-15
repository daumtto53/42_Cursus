/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:32:06 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 13:08:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/debug.h"
#include "../../includes/x11_key.h"
#include "../../includes/debug.h"

static int	is_collision(t_cub *cub, int x, int y)
{
	char	**map;

	map = cub->map.map;
	return (map[y][x] == '1' || map[y][x] == '2');
}

static void	key_pressed_1(t_cub *cub)
{
	t_player *p;

	p = &(cub->player);
	if (p->keypress_flag & RIGHTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, -1 * DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, -1 * DELTATHETA);
	}
	if (p->keypress_flag & LEFTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, DELTATHETA);
	}
	if (p->keypress_flag & WPRESSED)
	{
		if (!is_collision(cub, (int)(p->posx + p->dirx * MOVESPEED), \
				(int)p->posy))
			p->posx += p->dirx * MOVESPEED;
		if (!is_collision(cub, (int)p->posx, \
				(int)(p->posy + p->diry * MOVESPEED)))
			p->posy += p->diry * MOVESPEED;
	}
}

static void	key_pressed_2(t_cub *cub)
{
	t_player *p;

	p = &(cub->player);
	if (p->keypress_flag & DPRESSED)
	{
		if (!is_collision(cub, (int)(p->posx + p->planex * MOVESPEED), \
				(int)p->posy))
			p->posx += p->planex * MOVESPEED;
		if (!is_collision(cub, (int)p->posx, \
				(int)(p->posy + p->planey * MOVESPEED)))
			p->posy += p->planey * MOVESPEED;
	}
	if (p->keypress_flag & APRESSED)
	{
		if (!is_collision(cub, (int)(p->posx - p->planex * MOVESPEED), \
				(int)p->posy))
			p->posx -= p->planex * MOVESPEED;
		if (!is_collision(cub, (int)p->posx, \
				(int)(p->posy - p->planey * MOVESPEED)))
			p->posy -= p->planey * MOVESPEED;
	}
}

static void	key_pressed_3(t_cub *cub)
{
	t_player *p;

	p = &(cub->player);
	if (p->keypress_flag & SPRESSED)
	{
		if (!is_collision(cub, (int)(p->posx - p->dirx * MOVESPEED), \
				(int)p->posy))
			p->posx -= p->dirx * MOVESPEED;
		if (!is_collision(cub, (int)p->posx, \
			(int)(p->posy - p->diry * MOVESPEED)))
			p->posy -= p->diry * MOVESPEED;
	}
}

void		take_action(t_cub *cub)
{
	key_pressed_1(cub);
	key_pressed_2(cub);
	key_pressed_3(cub);
}
