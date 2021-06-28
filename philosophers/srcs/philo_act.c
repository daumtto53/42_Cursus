/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:24:29 by mchun             #+#    #+#             */
/*   Updated: 2021/06/28 22:42:14 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_taken_fork(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE || attr->num_finish_eat >= attr->phil_num)
		return ;
	printf("%llu ms: \t%d has taken a fork\n", get_timestamp(attr), p->philo_index);
}

void	act_eat(t_attr *attr, t_philo *p)
{
	struct timeval	tv;

	if (attr->is_dead || attr->num_finish_eat >= attr->phil_num)
	{
		pthread_mutex_unlock(&(attr->chopsticks[p->first_chop]));
		pthread_mutex_unlock(&(attr->chopsticks[p->second_chop]));
		return ;
	}
	printf("%llu ms: \t%d is eating\n", get_timestamp(attr), p->philo_index);
	p->num_eat++;
	gettimeofday(&tv, NULL);
	if (attr->is_dead == PHILO_FALSE)
	{
		p->last_eat = get_time_in_ms(&tv);
		p->revision_time = relative_time(attr);
	}
	usleep(attr->phil_eat * MILI_TO_MICRO);
	pthread_mutex_unlock(&(attr->chopsticks[p->first_chop]));
	pthread_mutex_unlock(&(attr->chopsticks[p->second_chop]));
	gettimeofday(&tv, NULL);
	p->revision_time = relative_time(attr) - attr->phil_eat;
	printf("get_time_in_ms : %llu, attr->phil_eat : %llu\n", get_time_in_ms(&tv), attr->phil_eat);
	// printf("thread %d : current_time - last_time : %ld\t current_time : %ld, last_time : %ld\n", p->philo_index, get_time_in_ms(&tv) - p->last_eat, get_time_in_ms(&tv), p->last_eat);
}

void	act_sleep(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE || attr->num_finish_eat >= attr->phil_num)
		return ;
	printf("%llu ms: \t%d is sleeping\n", get_timestamp(attr), p->philo_index);
	usleep(attr->phil_sleep * MILI_TO_MICRO);
}

void	act_think(t_attr *attr, t_philo *p)
{
	if (attr->is_dead == PHILO_TRUE || attr->num_finish_eat >= attr->phil_num)
		return ;
	printf("%llu ms: \t%d is thinking\n", get_timestamp(attr), p->philo_index);
}
