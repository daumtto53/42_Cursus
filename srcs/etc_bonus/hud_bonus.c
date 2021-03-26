/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:19:09 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 15:19:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	print_status(t_cub *cub)
{
	char *s;
	char *p;

	s = ft_itoa(cub->player.posx);
	p = ft_itoa(cub->player.posy);
	mlx_string_put(cub->mlx_ptr, cub->win, 10, 50, 0x00FFFFFF, "position x : ");
	mlx_string_put(cub->mlx_ptr, cub->win, 100, 50, 0x00FFFFFF, s);
	mlx_string_put(cub->mlx_ptr, cub->win, 10, 70, 0x00FFFFFF, "position y : ");
	mlx_string_put(cub->mlx_ptr, cub->win, 100, 70, 0x00FFFFFF, p);
	free(s);
	free(p);
}
