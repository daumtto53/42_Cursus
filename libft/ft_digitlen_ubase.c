/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen_ubase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:10:48 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 22:59:51 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlen_base(unsigned long long num, int base)
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
		num /= base;
	}
	return (count);
}
