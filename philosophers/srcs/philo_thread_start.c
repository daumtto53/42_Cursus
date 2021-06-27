/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/06/27 15:45:30 by mchun            ###   ########.fr       */
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
	act_taken_fork(attr, p);
	pthread_mutex_lock(&chopstick[right_chopstick]);
	act_taken_fork(attr, p);								// fork * 2
	act_eat(attr, p, left_chopstick, right_chopstick);										// eat
	act_sleep(attr, p);										// sleep
	act_think(attr, p);
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
	act_eat(attr, p, right_chopstick, left_chopstick);										// eat
	act_sleep(attr, p);										// sleep
	act_think(attr, p);
	return (PHILO_SUCC);
}

void	*check_death(void *arg)
{
	t_attr *attr;
	t_philo *p;
	struct timeval	tv;
	long			current_time;

	p = (t_philo *)arg;
	attr = p->attr;
	while (1)
	{
		gettimeofday(&tv, NULL);
		current_time = get_time_in_ms(&tv);
		pthread_mutex_lock(&attr->die_mutex);
		if (attr->is_dead == PHILO_FALSE && (current_time - p->last_eat) >= attr->phil_die)
		{
			attr->is_dead = PHILO_TRUE;
			printf("%d is_dead, interval : %ld, current_time : %ld, last_eat : %ld\n", p->philo_index, current_time - p->last_eat, current_time, p->last_eat);
			break;
		}
		pthread_mutex_unlock(&attr->die_mutex);
	}
	return (NULL);
}

int		philo_infinite(t_attr *attr, t_philo *p)
{
	pthread_t	tid;

	while (attr->is_dead == PHILO_FALSE)
	{
		pthread_create(&tid, NULL, check_death, (void *)p);
		if (p->hand == LEFT)
			left_philosopher_start(attr, p);
		else
			right_philosopher_start(attr, p);
		pthread_detach(tid);
	}
	return (1);
}

//at least를 고정횟수로 생각했기 때문에, 고정횟수가아닌 최소횟수로 생각해야함.
int		philo_iterate(t_attr *attr, t_philo *p)
{
	int		iter;

	iter = -1;
	while (++iter < attr->iteration)				//at least :
	{
		if (p->hand == LEFT)
			left_philosopher_start(attr, p);
		else
			right_philosopher_start(attr, p);
		if (attr->is_dead == PHILO_TRUE)
			break ;
	}
	return (PHILO_SUCC);
}
