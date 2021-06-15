/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_event_handler_2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:23:18 by mchun             #+#    #+#             */
/*   Updated: 2021/03/30 15:14:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/x11_key.h"
#include "../../includes/debug.h"

static void	keyrelease_wasd(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_W)
		cub->player.keypress_flag &= ~WPRESSED;
	if (keycode == L_KEYSYM_A)
		cub->player.keypress_flag &= ~APRESSED;
	if (keycode == L_KEYSYM_S)
		cub->player.keypress_flag &= ~SPRESSED;
	if (keycode == L_KEYSYM_D)
		cub->player.keypress_flag &= ~DPRESSED;
}

static void	keyrelease_left_right(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_LEFT)
		cub->player.keypress_flag &= ~LEFTPRESSED;
	if (keycode == L_KEYSYM_RIGHT)
		cub->player.keypress_flag &= ~RIGHTPRESSED;
}

int			event_keyrelease(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	keyrelease_left_right(keycode, cub);
	keyrelease_wasd(keycode, cub);
	return (0);
}

int			event_destroy(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	free_cub_struct(cub);
	kill_background_music();
	exit(0);
}

int			event_xicon(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	free_cub_struct(cub);
	kill_background_music();
	exit(0);
}
