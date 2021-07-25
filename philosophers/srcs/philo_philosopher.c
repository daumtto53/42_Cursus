/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/07/26 00:27:47 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void		monitor_dead(void *philo)
{
	t_philo	*p;
	t_attr	*attr;
	uint64_t time;

	p = (t_philo *)philo;
	attr = p->attr;
	while (attr->status != DEAD && attr->status != FINISH_EAT)
	{
		time = get_time_ms();
		if (time - p->last_eat > attr->phil_die)
		{
			printf("%d is dead\n", p->philo_index + 1);
			printf("time_ms : %lu, last_eat : %lu, dead time : %lu, die_time : %lu\n", time, p->last_eat, time - p->last_eat, attr->phil_die);
			pthread_mutex_lock(&attr->die_mutex);
			attr->status = DEAD;
			pthread_mutex_unlock(&attr->die_mutex);
			break;
		}
		usleep(150);
	}
}

static void		routine(t_attr *attr, t_philo *p)
{
	act_taken_fork(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
	{
		pthread_mutex_unlock(&attr->chopsticks[p->first_chop]);
		pthread_mutex_unlock(&attr->chopsticks[p->second_chop]);
		return ;
	}
	act_eat(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	act_sleep(attr, p);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	act_think(attr, p);
}

int				philosopher(void *phil)
{
	t_philo		*p;
	t_attr		*attr;
	pthread_t	monitor_dead_tid;

	p = (t_philo *)phil;
	attr = p->attr;
	if (pthread_create(&monitor_dead_tid, NULL, (void *)monitor_dead, p) < 0)
		return (PHILO_ERR);
	if (p->hand == LEFT)
		smart_sleep(attr, attr->phil_eat);
	p->last_eat = get_time_ms();
	while (attr->status != DEAD && attr->status != FINISH_EAT)
		routine(attr, phil);
	return (PHILO_SUCC);
}
