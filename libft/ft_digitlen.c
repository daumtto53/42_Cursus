/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:10:48 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 11:15:56 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digitlen(long num)
{
	int			count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}
