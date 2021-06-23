/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_attr_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:20:46 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 14:42:46 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static void	init_arg(t_attr *attr, char **argv, int argc)
{
	if (argc == 6)
		attr->iteration = ft_atoll(argv[5]);
	else
		attr->iteration = INT_MAX;
	attr->phil_num = ft_atoll(argv[1]);
	attr->phil_die = ft_atoll(argv[2]);
	attr->phil_eat = ft_atoll(argv[3]);
	attr->phil_sleep = ft_atoll(argv[4]);
}

static int		valid_attr(t_attr *attr)
{
	if (attr->iteration <= 0 || attr->phil_sleep <= 0 || \
		attr->phil_die <= 0 || attr->phil_eat <= 0 || attr->phil_num <= 0)
		return (PHILO_FALSE);
	return (PHILO_TRUE);
}

static int		init_philosopher(t_attr *attr)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	attr->phil_arr = (t_philo *)malloc(sizeof(t_philo) * attr->phil_num);
	if (!(attr->phil_arr))
		return (PHILO_ERR);
	while (++i < attr->phil_num)
	{
		attr->phil_arr[i].hand = i % 2;
		attr->phil_arr[i].philo_index = i;
		attr->phil_arr[i].attr = attr;			//referencing each other
	}
	return (PHILO_SUCC);
}

static int	init_chopsticks(t_attr *attr)
{
	pthread_mutex_t	*m_arr;

	m_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * attr->phil_num);
	if (!m_arr)
		return (PHILO_ERR);
	attr->chopsticks = m_arr;
	return (PHILO_SUCC);
}

int		init_attr(t_attr *attr, char **argv, int argc)
{
	init_arg(attr, argv, argc);
	if (!valid_attr(attr))
		return (PHILO_ERR);
	if (init_philosopher(attr) == PHILO_ERR)
		return (PHILO_ERR);
	if (init_chopsticks(attr) == PHILO_ERR)			//clean philo_t malloced.
		return (PHILO_ERR);
	return (PHILO_SUCC);
}