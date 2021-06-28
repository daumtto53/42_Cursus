/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:09 by mchun             #+#    #+#             */
/*   Updated: 2021/06/28 22:42:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*philo_thread(void *arg)
{
	t_philo		*p;
	t_attr		*attr;

	p = (t_philo *)arg;
	attr = p->attr;
	// printf("thread : f %d\ts %d\t num_eat:%d\t index:\t%d\n", p->first_chop, p->second_chop, p->num_eat, p->philo_index);
	if (!is_5th_arg(attr))
		philo_infinite(attr, p);
	else
		philo_iterate(attr, p);
	return (NULL);
}

void	monitor(t_attr *attr, t_philo *phil_arr)
{
	struct timeval	tv;
	uint64_t			current_time;
	int		i;

	while (1)
	{
		if (attr->phil_num == attr->num_finish_eat)
			break;
		gettimeofday(&tv, NULL);
		current_time = get_time_in_ms(&tv);
		i = -1;
		pthread_mutex_lock(&attr->die_mutex);
		while (++i < attr->phil_num)
		{
			if (attr->is_dead == PHILO_FALSE && current_time - attr->start_time_ms > attr->phil_die + phil_arr[i].revision_time)
			{
				printf("current_time : %llu\t, revisiontime : %llu\t, phil_die : %llu\n", current_time, phil_arr[i].revision_time, attr->phil_die);
				attr->is_dead = PHILO_TRUE;
				printf("%d is_dead, interval : %llu, current_time : %llu, last_eat : %llu", phil_arr[i].philo_index, current_time - phil_arr[i].last_eat, current_time, phil_arr[i].last_eat);
				pthread_mutex_unlock(&attr->die_mutex);
				return ;
			}
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

	i = -1;
	if (!(argc == 5 || argc == 6))
		return (PHILO_FALSE);
	if (init_attr(&attr, argv, argc) == PHILO_ERR)
		return (PHILO_ERR);
	if (init_philosopher(&phil_arr, attr) == PHILO_ERR)
		return (PHILO_ERR);
	tid_arr = init_tid_arr(attr);
	if (!tid_arr)
	{
		free_attr(attr);
		return (PHILO_ERR);
	}
	init_start_time_ms(phil_arr, attr);
	i = -1;
	while (++i < attr->phil_num)
		pthread_create(tid_arr + i, NULL, (void *)philo_thread, (void *)(phil_arr + i));
	i = -1;
	monitor(attr, phil_arr);
	while (++i < attr->phil_num)
		pthread_join(tid_arr[i], NULL);
	printf("num_finish_eat : %d, attr->iteration : %d\n", attr->num_finish_eat, attr->iteration);
	if (attr->iteration != INT_MAX && attr->num_finish_eat == attr->phil_num)
		printf("finished_eating\n");
	// terminate_data(&attr, tid_arr);
	return (0);
}
