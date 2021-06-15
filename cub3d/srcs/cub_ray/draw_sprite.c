/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:26:10 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 13:11:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	sprite_rayc_calculator(t_cub *cub, t_sprite_op *op, int i, int line)
{
	int		y;
	int		color;
	int		tex_num;

	while (line++ < op->drawend_x)
		if (op->trans_y > 0 && line > 0 && line < cub->screen_x && \
				op->trans_y < cub->perp_buff[line])
		{
			op->texx = \
				(int)((line - (-1 * op->sprite_w / 2 + op->sprite_scx)) * \
					TEXTURE_W / op->sprite_w);
			if (op->texx >= TEXTURE_W)
				op->texx = TEXTURE_W - 1;
			y = op->drawstart_y;
			while (++y < op->drawend_y)
			{
				op->texy = (y - cub->screen_y / 2 + op->sprite_h / 2);
				op->texy = ((op->texy * TEXTURE_H) / op->sprite_h) & 63;
				tex_num = cub->sprite_arr[cub->sprite_order[i]].tex_num;
				color = cub->tex_arr[tex_num][TEXTURE_W * op->texy + op->texx];
				if ((color & 0x00FFFFFF) != 0)
					buff_drawer(cub, line, y, color);
			}
		}
}
