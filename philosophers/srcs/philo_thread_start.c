/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 21:34:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int		left_philosopher_start(t_attr *attr, t_philo *p)
{
	pthread_mutex_t		*chopstick;
	int					left_chopstick;
	int					right_chopstick;

	chopstick = attr->chopsticks;
	left_chopstick = (p->philo_index - 1 + attr->phil_num) % attr->phil_num;
	right_chopstick = (p->philo_index) % attr->phil_num;
	pthread_mutex_lock(&chopstick[left_chopstick]);
	pthread_mutex_lock(&chopstick[right_chopstick]);
	printf("thread %d eating.... locked : %d\t%d\n", p->philo_index, left_chopstick, right_chopstick);
	pthread_mutex_unlock(&chopstick[left_chopstick]);
	pthread_mutex_unlock(&chopstick[right_chopstick]);
	return (PHILO_SUCC);
}

static int		right_philosopher_start(t_attr *attr, t_philo *p)
{
	pthread_mutex_t		*chopstick;
	int					left_chopstick;
	int					right_chopstick;

	chopstick = attr->chopsticks;
	left_chopstick = (p->philo_index - 1 + attr->phil_num) % attr->phil_num;
	right_chopstick = (p->philo_index) % attr->phil_num;
	pthread_mutex_lock(&chopstick[right_chopstick]);
	act_taken_fork(attr, p);
	pthread_mutex_lock(&chopstick[left_chopstick]);
	act_taken_fork(attr, p);								// fork * 2
	act_eat(attr, p);										// eat
	act_sleep(attr, p);										// sleep
	act_think(attr, p);
	pthread_mutex_unlock(&chopstick[right_chopstick]);
	pthread_mutex_unlock(&chopstick[left_chopstick]);
	return (PHILO_SUCC);
}

int		philo_infinite(t_attr *attr, t_philo *p)
{
	int		dead;

	while (1)
	{
		if (p->hand == LEFT)
			dead = left_philosopher_start(attr, p);
		else
			dead = right_philosopher_start(attr, p);
	}
	return (dead);
}

int		philo_iterate(t_attr *attr, t_philo *p)
{
	int		iter;
	int		left_chopstick;
	int		right_chopstick;
	int		dead;

	iter = -1;
	while (++iter < attr->iteration)
	{
		if (p->hand == LEFT)
			left_philosopher_start(attr, p);
		else
			right_philosopher_start(attr, p);
		usleep(1 * 1000 * 1000);
	}
	return (dead);
}
