/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:38:40 by mchun             #+#    #+#             */
/*   Updated: 2021/07/26 16:40:01 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_time_ms(void)
{
	uint64_t		sec;
	uint64_t		usec;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec;
	usec = tv.tv_usec;
	return ((sec * (uint64_t)1000) + (usec / (uint64_t)1000));
}

uint64_t	get_time_in_ms(struct timeval *tv)
{
	uint64_t	sec;
	uint64_t	usec;

	sec = tv->tv_sec;
	usec = tv->tv_usec;
	return ((sec * (uint64_t)1000) + (usec / (uint64_t)1000));
}

uint64_t	get_timestamp(t_attr *attr)
{
	uint64_t		start_ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start_ms = attr->start_time_ms;
	return (get_time_in_ms(&tv) - start_ms);
}

int			init_start_time_ms(t_philo *phil_arr, t_attr *attr)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	attr->start_time_ms = get_time_in_ms(&tv);
	i = 0;
	while (i < attr->phil_num)
	{
		phil_arr[i].last_eat = attr->start_time_ms;
		i++;
	}
	return (PHILO_SUCC);
}

void		smart_sleep(t_attr *attr, uint64_t ms)
{
	struct timeval	tv;
	uint64_t		start_time;

	gettimeofday(&tv, NULL);
	start_time = get_time_in_ms(&tv);
	while (attr->status != DEAD)
	{
		gettimeofday(&tv, NULL);
		if (get_time_in_ms(&tv) - start_time >= ms)
			break ;
		usleep(150);
	}
}
