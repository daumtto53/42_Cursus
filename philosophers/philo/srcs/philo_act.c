/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:24:29 by mchun             #+#    #+#             */
/*   Updated: 2021/07/30 17:37:02 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_taken_fork(t_attr *attr, t_philo *p)
{
	pthread_mutex_lock(&attr->chopsticks[p->first_chop]);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	printf("%llu ms: \t%d has taken a fork\n", \
		get_timestamp(attr), p->philo_index + 1);
	pthread_mutex_lock(&attr->chopsticks[p->second_chop]);
	if (attr->status == DEAD || attr->status == FINISH_EAT)
		return ;
	printf("%llu ms: \t%d has taken a fork\n", \
		get_timestamp(attr), p->philo_index + 1);
}

void	act_eat(t_attr *attr, t_philo *p)
{
	printf("%llu ms: \t%d is eating\n", \
		get_timestamp(attr), p->philo_index + 1);
	p->last_eat = get_time_ms();
	p->num_eat++;
	if (p->num_eat == attr->iteration)
	{
		pthread_mutex_lock(&attr->eat_mutex);
		attr->finished_philo++;
		pthread_mutex_unlock(&attr->eat_mutex);
	}
	smart_sleep(attr, attr->phil_eat);
	pthread_mutex_unlock(&(attr->chopsticks[p->second_chop]));
	pthread_mutex_unlock(&(attr->chopsticks[p->first_chop]));
}

void	act_sleep(t_attr *attr, t_philo *p)
{
	printf("%llu ms: \t%d is sleeping\n", \
		get_timestamp(attr), p->philo_index + 1);
	smart_sleep(attr, attr->phil_sleep);
}

void	act_think(t_attr *attr, t_philo *p)
{
	printf("%llu ms: \t%d is thinking\n", \
		get_timestamp(attr), p->philo_index + 1);
}

int	act_only_one_philosopher(t_attr *attr)
{
	printf("0 ms:\t1 has taken a fork\n");
	smart_sleep(attr, attr->phil_die);
	printf("%llu ms:\t1 dead\n", attr->phil_die);
	return (1);
}
