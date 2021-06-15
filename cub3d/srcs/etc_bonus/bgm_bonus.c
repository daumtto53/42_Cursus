/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:19:06 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 15:19:19 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	play_background_music(void)
{
	int	a;

	a = system("canberra-gtk-play -f ./animal_crossing.wav --loop=100 &");
	a += 1;
}

void	kill_background_music(void)
{
	int	a;

	a = system("pkill canberra-gtk-pl");
	a += 1;
}
