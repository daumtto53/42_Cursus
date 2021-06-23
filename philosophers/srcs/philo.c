/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:09 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 14:45:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

void		*philo_thread(void *arg)
{
	t_attr *attr;

	attr = (t_attr *)arg;

}

int			main(int argc, char **argv)
{
	t_attr		attr;
	pthread_t	*tid_arr;
	int			i;

	if (!(argc == 5 || argc == 6))
		return (PHILO_FALSE);
	init_attr(&attr, argv, argc);
	tid_arr = init_tid_arr(&attr);

	for (int j = 0; j < attr.phil_num; j++)
	{
		printf("philo_index : %d\t philo_hand : %d\t attr : %d, %lld, %lld\n", attr.phil_arr[j].philo_index, attr.phil_arr[j].hand, attr.phil_arr[j].attr->phil_num, attr.phil_arr[j].attr->phil_die, attr.phil_arr[j].attr->phil_sleep);
	}
	exit(0);
	if (!tid_arr)
	{
		free_attr(&attr);
		return (PHILO_ERR);
	}
	i = 0;
	while (i < attr.phil_num)
	{
		return (1);
		pthread_create(tid_arr + i, NULL, (void *)philo_thread, (void *)&attr);
	}

	i = 0;
	whlie (i < attr.phil_num)
	{
		pthread_join(tid_arr[i], NULL);
	}
	terminate_data(&attr, tid_arr);
}
