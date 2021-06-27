/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:24:29 by mchun             #+#    #+#             */
/*   Updated: 2021/06/27 15:40:02 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_taken_fork(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%ld ms: \t%d has taken a fork\n", get_timestamp(attr), p->philo_index);
}

void	act_eat(t_attr *attr, t_philo *p, int first, int second)
{
	struct timeval	tv;

	if (attr->is_dead)
	{
		pthread_mutex_unlock(&(attr->chopsticks[first]));
		pthread_mutex_unlock(&(attr->chopsticks[second]));
	}
	gettimeofday(&tv, NULL);
	printf("%ld ms: \t%d is eating\n", get_timestamp(attr), p->philo_index);
	if (attr->is_dead == PHILO_FALSE)
		p->last_eat = get_time_in_ms(&tv);
	pthread_mutex_unlock(&(attr->chopsticks[first]));
	pthread_mutex_unlock(&(attr->chopsticks[second]));
	usleep(attr->phil_eat * MILI_TO_MICRO);
}

void	act_sleep(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%ld ms: \t%d is sleeping\n", get_timestamp(attr), p->philo_index);
	usleep(attr->phil_sleep * MILI_TO_MICRO);
}

void	act_think(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%ld ms: \t%d is thinking\n", get_timestamp(attr), p->philo_index);
}
