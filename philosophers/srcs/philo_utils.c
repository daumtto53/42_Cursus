/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:52:50 by mchun             #+#    #+#             */
/*   Updated: 2021/06/24 14:38:36 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_atoll(char *src)
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

void		free_attr(t_attr *attr)
{
	int		i;

	// free mutex
	i = -1;
	while (++i < attr->phil_num)
		pthread_mutex_destroy(&(attr->chopsticks[i]));
	// free philosophers
	free(attr->phil_arr);
}

void		terminate_data(t_attr *attr, pthread_t *tid_arr)
{
	free(tid_arr);
	free_attr(attr);
	return ;
}

int		is_5th_arg(t_attr *attr)
{
	return !(attr->iteration == INT_MAX);
}
