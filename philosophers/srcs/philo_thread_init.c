/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:33:54 by mchun             #+#    #+#             */
/*   Updated: 2021/06/22 21:02:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_t	*init_tid_arr(t_attr *attr)
{
	pthread_t	*tid_arr;

	tid_arr = (pthread_t *)malloc(sizeof(pthread_t) * attr->phil_num);
	if (!tid_arr)
		return (NULL);
	return (tid_arr);
}

