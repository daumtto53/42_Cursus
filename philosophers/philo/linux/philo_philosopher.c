/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/07/30 17:34:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_dead(void *philo)
{
	t_philo		*p;
	t_attr		*attr;
	uint64_t	time;

	p = (t_philo *)philo;
	attr = p->attr;
	while (attr->status != DEAD && attr->status != FINISH_EAT)
	{
		time = get_time_ms();
		pthread_mutex_lock(&attr->eat_mutex);
		if (time > p->last_eat + attr->phil_die && attr->status != DEAD && \
				attr->status != FINISH_EAT)
		{
			attr->status = DEAD;
			pthread_mutex_unlock(&attr->eat_mutex);
			printf("%lu ms: \t%d is dead\n", \
						get_timestamp(attr), p->philo_index + 1);
			break ;
		}
		pthread_mutex_unlock(&attr->eat_mutex);
		usleep(100);
	}
	return (NULL);
}

static void	routine(t_attr *attr, t_philo *p)
{
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	act_taken_fork(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
	{
		pthread_mutex_unlock(&attr->chopsticks[p->second_chop]);
		pthread_mutex_unlock(&attr->chopsticks[p->first_chop]);
		return ;
	}
	act_eat(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	act_sleep(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	act_think(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	usleep(50);
}

void	*philosopher(void *phil)
{
	t_philo		*p;
	t_attr		*attr;
	pthread_t	monitor_dead_tid;

	p = (t_philo *)phil;
	attr = p->attr;
	if (pthread_create(&monitor_dead_tid, NULL, (void *)monitor_dead, p) < 0)
		return (NULL);
	pthread_detach(monitor_dead_tid);
	if (p->hand == RIGHT)
		smart_sleep(attr, attr->phil_eat / 2);
	while (attr->status != DEAD && attr->status != FINISH_EAT)
		routine(attr, phil);
	return (NULL);
}
