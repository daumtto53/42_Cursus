/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:09 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 20:11:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

pthread_mutex_t	mutex;

void		*philo_thread(void *arg)
{
	t_philo		*p;
	t_attr		*attr;

	p = (t_philo *)arg;
	attr = p->attr;

	//ptrhead_data transfer test
	pthread_mutex_lock(attr->chopsticks + 0);
	printf("hand : %d\tphilo_index : %d\tphil_num : %d\n\titeration:%d\tphil_die:%lld\teat:%lld\tsleep:%lld\n\n", p->hand, p->philo_index, p->attr->phil_num, p->attr->iteration, p->attr->phil_die, p->attr->phil_eat, p->attr->phil_sleep);
	pthread_mutex_unlock(attr->chopsticks + 0);

	//pthread_data

	if (!is_5th_arg(attr))
		philo_infinite(attr, p);
	else
		philo_iterate(attr, p);
	return (NULL);
}

int			main(int argc, char **argv)
{
	pthread_mutex_init(&mutex, NULL);
	t_attr		attr;
	pthread_t	*tid_arr;
	int			i;

	if (!(argc == 5 || argc == 6))
		return (PHILO_FALSE);
	if (init_attr(&attr, argv, argc) == PHILO_ERR)
		return (PHILO_ERR);
	tid_arr = init_tid_arr(&attr);
	if (!tid_arr)
	{
		free_attr(&attr);
		return (PHILO_ERR);
	}
	i = -1;
	while (++i < attr.phil_num)
		pthread_create(tid_arr + i, NULL, (void *)philo_thread, (void *)&attr.phil_arr[i]);
	i = -1;
	while (++i < attr.phil_num)
		pthread_join(tid_arr[i], NULL);
	terminate_data(&attr, tid_arr);
}
