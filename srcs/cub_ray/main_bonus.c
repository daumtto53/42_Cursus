/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:38:26 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 14:50:51 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/debug.h"
#include "../../includes/x11_key.h"
#include "../../includes/bmp.h"

#include <unistd.h>

int		main(int argc, char **argv)
{
	t_cub	cub;
	t_conf	conf;

	parse_conf_cub(argc, argv, &conf);
	init_cub(&cub, &conf);
	untextured_rayc(&cub, argc);
	play_background_music(&cub);
	if (argc == 3)
	{
		bmp_maker(&cub);
		parse_error_cleaner(&conf);
		free_cub_struct(&cub);
	}
	else
	{
		mlx_hook(cub.win, KEYPRESS, KEYPRESSMASK, event_keypress, &cub);
		mlx_hook(cub.win, KEYRELEASE, KEYRELEASEMASK, event_keyrelease, &cub);
		mlx_hook(cub.win, DESTORY_NOTIFY, 0, event_destroy, &cub);
		mlx_hook(cub.win, CLIENTMESSAGE, 0, event_xicon, &cub);
		mlx_loop_hook(cub.mlx_ptr, untextured_rayc, &cub);
		mlx_loop(cub.mlx_ptr);
	}
	return (0);
}
