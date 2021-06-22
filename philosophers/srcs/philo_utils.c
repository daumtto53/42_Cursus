/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:52:50 by mchun             #+#    #+#             */
/*   Updated: 2021/06/22 20:39:48 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long atoull(char *src)
{
	long long	num;
	int			i;
	int			negative;

	if (!src)
		return (0);
	negative = 1;
	i = 0;
	while (src[i] == '\f' || src[i] == '\r' || src[i] == '\t' \
		|| src[i] == '\v' || src[i] == ' ' || src[i] == '\n')
	i++;

	if (src[i] == '-')
	{
		negative = -1;
		i++;
	}
	num = 0;
	while (src[i] >= '0' && src[i] <= '9')
		num = (num * 10) + (src[i++] - '0');
	return (negative * num);
}
