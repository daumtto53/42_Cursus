/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/07/01 16:16:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	philosopher_start(t_attr *attr, t_philo *p)
{
	pthread_mutex_lock(&attr->chopsticks[p->first_chop]);
	act_taken_fork(attr, p);
	pthread_mutex_lock(&attr->chopsticks[p->second_chop]);
	act_taken_fork(attr, p);
	act_eat(attr, p);
	pthread_mutex_lock(&attr->die_mutex);
	if (p->num_eat == attr->iteration)
	{
		pthread_mutex_lock(&attr->eat_mutex);
		attr->num_finish_eat++;
		printf("%d finished eating\n", p->philo_index + 1);
		pthread_mutex_unlock(&attr->eat_mutex);
	}
	pthread_mutex_unlock(&attr->die_mutex);
	act_sleep(attr, p);
	act_think(attr, p);
	return (PHILO_SUCC);
}

int			philo_infinite(t_attr *attr, t_philo *p)
{
	while (attr->is_dead == PHILO_FALSE)
		philosopher_start(attr, p);
	return (1);
}

int			philo_iterate(t_attr *attr, t_philo *p)
{
	while (attr->is_dead == PHILO_FALSE && \
		attr->num_finish_eat < attr->phil_num)
		philosopher_start(attr, p);
	return (PHILO_SUCC);
}
