/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:02:26 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 10:21:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	long			num;
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
		num += ((long)nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
