/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:25:44 by mchun             #+#    #+#             */
/*   Updated: 2021/07/01 21:42:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_thread(void *arg)
{
	t_philo		*p;
	t_attr		*attr;

	p = (t_philo *)arg;
	attr = p->attr;
	if (!is_5th_arg(attr))
		philo_infinite(attr, p);
	else
		philo_iterate(attr, p);
	return (NULL);
}

static void	philosopher_died(t_attr *attr, t_philo *phil_arr, int i)
{
	attr->is_dead = PHILO_TRUE;
	usleep(500);
	printf("%llu ms:\t\t%d died\n", get_timestamp(attr), \
		phil_arr[i].philo_index + 1);
	pthread_mutex_unlock(&attr->die_mutex);
	return ;
}

static void	monitor(t_attr *attr, t_philo *phil_arr)
{
	struct timeval	tv;
	uint64_t		current_time;
	int				i;

	while (1)
	{
		if (attr->phil_num == attr->num_finish_eat)
			break ;
		gettimeofday(&tv, NULL);
		current_time = get_time_in_ms(&tv);
		i = -1;
		pthread_mutex_lock(&attr->die_mutex);
		while (++i < attr->phil_num)
			if (attr->is_dead == PHILO_FALSE && \
				current_time - phil_arr[i].last_eat >= attr->phil_die)
			{
				philosopher_died(attr, phil_arr, i);
				return ;
			}
		if (!attr->is_dead)
			pthread_mutex_unlock(&attr->die_mutex);
		usleep(100);
	}
	return ;
}

int			main(int argc, char **argv)
{
	t_attr		*attr;
	t_philo		*phil_arr;
	pthread_t	*tid_arr;
	int			i;

	if (init_structure(&attr, &phil_arr, argv, argc) == PHILO_ERR)
		return (PHILO_ERR);
	tid_arr = init_tid_arr(attr);
	if (!tid_arr)
		return (PHILO_ERR);
	init_start_time_ms(phil_arr, attr);
	i = -1;
	while (++i < attr->phil_num)
		pthread_create(tid_arr + i, NULL, \
			(void *)philo_thread, (void *)(phil_arr + i));
	i = -1;
	monitor(attr, phil_arr);
	while (++i < attr->phil_num)
		pthread_join(tid_arr[i], NULL);
	if (attr->iteration != INT_MAX && attr->num_finish_eat == attr->phil_num)
		printf("finished_eating\n");
	terminate_data(attr, phil_arr, tid_arr);
	return (0);
}
