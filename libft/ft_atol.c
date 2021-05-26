/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:02:26 by mchun             #+#    #+#             */
/*   Updated: 2021/05/26 14:13:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_atol(const char *nptr)
{
	long long		num;
	size_t			i;
	long			sign;

	num = 0;
	i = 0;
	sign = 1;
	while ((nptr[i]) && ft_isspace(nptr[i]))
		i++;
	if ((nptr[i]) && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		num *= 10;
		num += ((long long)nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
