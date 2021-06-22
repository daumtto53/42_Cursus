/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:09 by mchun             #+#    #+#             */
/*   Updated: 2021/06/22 20:42:25 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

// void		*philo_thread(void *arg)
// {

// }

int			main(int argc, char **argv)
{
	t_attr		attr;
	pthread_t	*tid_arr;
	int			i;

	if (argc != 5 || argc != 6)
	{
		return (0);
	}
	init_attr(&attr, argv, argc);
	tid_arr = init_tid_arr(&attr);
	if (!tid_arr)
	i = 0;
	while (i < attr.phil_num)
	{
		pthread_create(tid_arr + i, NULL, (void *)philo_thread, (void *)&attr); sfsdf
	}

	i = 0;
	whlie (i < attr.phil_num)
	{
		pthread_join(tid_arr[i], NULL);
	}
	terminate_data(&attr, tid_arr);

}
