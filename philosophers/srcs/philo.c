/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:25:44 by mchun             #+#    #+#             */
/*   Updated: 2021/07/26 00:27:44 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_eat(void *philo)
{
	t_philo	*p;
	t_attr	*attr;

	p = (t_philo *)philo;
	attr = p->attr;
	while (attr->status != DEAD && attr->status != FINISH_EAT)
	{
		if (attr->finished_philo == attr->phil_num)
		{
			printf("Finished meals\n");
			pthread_mutex_lock(&attr->die_mutex);
			attr->status = FINISH_EAT;
			pthread_mutex_unlock(&attr->die_mutex);
		}
		usleep(150);
	}
	return (NULL);
}

static int	thread_start(t_attr *attr, t_philo *phil_arr)
{
	pthread_t	monitor_tid;
	pthread_t	*phil_tid;
	int			i;

	phil_tid  = attr->phil_tid;
	attr->start_time_ms = get_time_ms();
	i = -1;
	while (++i < attr->phil_num)
	{
		phil_arr[i].last_eat = attr->start_time_ms;
		if (pthread_create(phil_tid + i, NULL, (void *)philosopher, (phil_arr + i)) < 0)
			return (PHILO_ERR);
		usleep(30);
	}
	if (pthread_create(&monitor_tid, NULL, &monitor_eat, phil_arr) < 0)
		return (PHILO_ERR);
	pthread_detach(monitor_tid);
	i = -1;
	while (++i < attr->phil_num)
		pthread_join(phil_tid[i], NULL);
	return (PHILO_SUCC);
}

int			main(int argc, char **argv)
{
	t_attr		*attr;
	t_philo		*phil_arr;

	if (init_structure(&attr, &phil_arr, argv, argc) == PHILO_ERR)
		return (PHILO_ERR);
	thread_start(attr, phil_arr);
	terminate_data(attr, phil_arr);
	return (0);
}
