/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:17:51 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 15:17:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

static int	count_sprite_num(t_cub *cub)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < cub->map.map_h)
	{
		j = -1;
		while (++j < cub->map.map_w)
			if (cub->map.map[i][j] == '2')
				count++;
	}
	return (count);
}

static int	alloc_sprite_arrays(t_cub *cub)
{
	cub->sprite_arr = (t_sprite *)ft_calloc(cub->sprite_num, sizeof(t_sprite));
	cub->sprite_dist = (double *)ft_calloc(cub->sprite_num, sizeof(double));
	cub->sprite_order = (int *)ft_calloc(cub->sprite_num, sizeof(int));
	if (!cub->sprite_arr || !cub->sprite_dist || !cub->sprite_order)
	{
		free(cub->sprite_arr);
		free(cub->sprite_dist);
		free(cub->sprite_order);
		return (-1);
	}
	return (1);
}

static void	assign_sprite_pos(t_cub *cub)
{
	int		i;
	int		j;
	int		assigned_sprite;

	i = -1;
	j = -1;
	assigned_sprite = 0;
	while (++i < cub->map.map_h)
	{
		j = -1;
		while (++j < cub->map.map_w)
		{
			if (cub->map.map[i][j] == '2')
			{
				cub->sprite_arr[assigned_sprite].x = (j + 0.5) * 1.0;
				cub->sprite_arr[assigned_sprite].y = (i + 0.5) * 1.0;
				cub->sprite_arr[assigned_sprite].tex_num = TEXTURE_SP_1;
				assigned_sprite++;
			}
		}
	}
}

int			init_sprite(t_cub *cub)
{
	cub->sprite_num = count_sprite_num(cub);
	if (alloc_sprite_arrays(cub) == -1)
		return (-1);
	assign_sprite_pos(cub);
	return (1);
}
