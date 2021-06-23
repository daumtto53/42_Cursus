/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:24:29 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 21:10:57 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_taken_fork(t_attr *attr, t_philo *p)
{
	printf("timestamp_in_ms\t%d has taken a fork\n", p->philo_index);
}

void	act_eat(t_attr *attr, t_philo *p)
{
	printf("timestamp_in_ms\t%d has taken a fork\n", p->philo_index);
	usleep(attr->phil_eat * MILI_TO_MICRO);
}

void	act_sleep(t_attr *attr, t_philo *p)
{
	printf("timestamp_in_ms\t%d has taken a fork\n", p->philo_index);
	usleep(attr->phil_sleep * MILI_TO_MICRO);
}

void	act_think(t_attr *attr, t_philo *p)
{
	printf("timestamp_in_ms\t%d has taken a fork\n", p->philo_index);
}

int		act_die(t_attr *attr, t_philo *p)
{
	printf("timestamp_in_ms\t%d has taken a fork\n", p->philo_index);
	return (PHILO_FALSE);
}
