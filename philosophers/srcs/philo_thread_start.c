/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:44 by mchun             #+#    #+#             */
/*   Updated: 2021/06/29 18:02:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int		left_philosopher_start(t_attr *attr, t_philo *p)
{
	pthread_mutex_lock(&attr->chopsticks[p->first_chop]);
	act_taken_fork(attr, p);
	pthread_mutex_lock(&attr->chopsticks[p->second_chop]);
	act_taken_fork(attr, p);								// fork * 2
	act_eat(attr, p);										// eat
	if (p->num_eat == attr->iteration)
	{
		pthread_mutex_lock(&attr->eat_mutex);
		attr->num_finish_eat++;
		pthread_mutex_unlock(&attr->eat_mutex);
	}
	act_sleep(attr, p);										// sleep
	act_think(attr, p);
	return (PHILO_SUCC);
}

int		philo_infinite(t_attr *attr, t_philo *p)
{
	while (attr->is_dead == PHILO_FALSE)
		left_philosopher_start(attr, p);
	return (1);
}

//at least를 고정횟수로 생각했기 때문에, 고정횟수가아닌 최소횟수로 생각해야함.
int		philo_iterate(t_attr *attr, t_philo *p)
{
	while (attr->is_dead == PHILO_FALSE && attr->num_finish_eat < attr->iteration)				//at least :
		left_philosopher_start(attr, p);
	return (PHILO_SUCC);
}
