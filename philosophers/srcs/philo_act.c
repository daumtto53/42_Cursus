/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:24:29 by mchun             #+#    #+#             */
/*   Updated: 2021/07/01 16:43:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_taken_fork(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%llu ms: \t%d has taken a fork\n", \
		get_timestamp(attr), p->philo_index + 1);
}

void	act_eat(t_attr *attr, t_philo *p)
{
	struct timeval	tv;

	if (attr->is_dead == PHILO_TRUE)
	{
		pthread_mutex_unlock(&(attr->chopsticks[p->first_chop]));
		pthread_mutex_unlock(&(attr->chopsticks[p->second_chop]));
		return ;
	}
	pthread_mutex_lock(&attr->die_mutex);
	printf("%llu ms: \t%d is eating\n", \
		get_timestamp(attr), p->philo_index + 1);
	p->num_eat++;
	pthread_mutex_unlock(&attr->die_mutex);
	gettimeofday(&tv, NULL);
	if (attr->is_dead == PHILO_FALSE)
		p->last_eat = get_time_in_ms(&tv);
	smart_sleep(attr, attr->phil_eat);
	pthread_mutex_unlock(&(attr->chopsticks[p->first_chop]));
	pthread_mutex_unlock(&(attr->chopsticks[p->second_chop]));
}

void	act_sleep(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%llu ms: \t%d is sleeping\n", \
		get_timestamp(attr), p->philo_index + 1);
	smart_sleep(attr, attr->phil_sleep);
}

void	act_think(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE)
		return ;
	printf("%llu ms: \t%d is thinking\n", \
		get_timestamp(attr), p->philo_index + 1);
}

int		act_only_one_philosopher(t_attr *attr)
{
	printf("0 ms:\t1 has taken a fork\n");
	smart_sleep(attr, attr->phil_die);
	printf("%llu ms:\t1 dead\n", attr->phil_die);
	return (1);
}
