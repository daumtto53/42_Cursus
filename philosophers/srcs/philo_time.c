/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:38:40 by mchun             #+#    #+#             */
/*   Updated: 2021/06/24 20:24:51 by mchun            ###   ########.fr       */
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

int		is_phil_dead(t_attr *attr, t_philo *p, long *dead_time)
{
	struct timeval tv;

	if (p->last_eat == -1)
		return (PHILO_FALSE);
	gettimeofday(&tv, NULL);
	printf("interval : %ld\n", get_time_in_ms(&tv) - p->last_eat);
	if (get_time_in_ms(&tv) - p->last_eat >= attr->phil_die)
	{
		*dead_time = get_time_in_ms(&tv);
		printf("interval : %ld\n", get_time_in_ms(&tv) - p->last_eat);
		attr->is_dead = PHILO_TRUE;
		return (PHILO_TRUE);
	}
	else
	{
		return (PHILO_FALSE);
	}
	return (PHILO_FALSE);
}

int		init_start_time_ms(t_attr *attr)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == PHILO_ERR)
		return (PHILO_ERR);
	attr->start_time_ms = get_time_in_ms(&tv);
	return PHILO_SUCC;
}
