/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_untexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:29:02 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 00:29:03 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void			buff_drawer(t_cub *cub, int x, int y, unsigned int color)
{
	int		*img_buff;

	img_buff = cub->img.img_buff;
	img_buff[cub->screen_x * y + x] = color;
}
