/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:38:40 by mchun             #+#    #+#             */
/*   Updated: 2021/06/27 21:05:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_in_ms(struct timeval *tv)
{
	long	sec;
	int		usec;

	sec = tv->tv_sec;
	usec = tv->tv_usec;
	return ((sec * 1000) + (usec / 1000));
}

long	get_timestamp(t_attr *attr)
{
	long			start_ms;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == PHILO_ERR)
		return (PHILO_ERR);
	start_ms = attr->start_time_ms;
	return (get_time_in_ms(&tv) - start_ms);
}

int		init_start_time_ms(t_philo *phil_arr, t_attr *attr)
{
	struct timeval tv;
	int				i;

	if (gettimeofday(&tv, NULL) == PHILO_ERR)
		return (PHILO_ERR);
	attr->start_time_ms = get_time_in_ms(&tv);
	i = 0;
	while (i < attr->phil_num)
	{
		phil_arr[i].last_eat = attr->start_time_ms;
		i++;
	}
	return PHILO_SUCC;
}
