/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:09 by mchun             #+#    #+#             */
/*   Updated: 2021/06/27 19:12:17 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*philo_thread(void *arg)
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

int			main(int argc, char **argv)
{
	t_attr		*attr;
	t_philo		*phil_arr;
	pthread_t	*tid_arr;
	int			i;

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
	i = -1;
	init_start_time_ms(phil_arr, attr);
	while (++i * 2 < attr->phil_num)
		pthread_create(tid_arr + i * 2, NULL, (void *)philo_thread, (void *)(phil_arr + i * 2));
	i = -1;
	while (++i * 2 + 1< attr->phil_num)
		pthread_create(tid_arr + i * 2 + 1, NULL, (void *)philo_thread, (void *)(phil_arr + i * 2 + 1));
	i = -1;
	while (++i < attr->phil_num)
		pthread_join(tid_arr[i], NULL);
	printf("num_finish_eat : %d, attr->iteration : %d\n", attr->num_finish_eat, attr->iteration);
	if (attr->iteration != INT_MAX && attr->num_finish_eat == attr->phil_num)
		printf("finished_eating\n");
	// terminate_data(&attr, tid_arr);
	return (0);
}
