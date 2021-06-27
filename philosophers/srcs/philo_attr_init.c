/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_attr_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:20:46 by mchun             #+#    #+#             */
/*   Updated: 2021/06/27 16:03:13 by mchun            ###   ########.fr       */
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
	attr->is_dead = PHILO_FALSE;
	attr->num_finish_eat = 0;
	pthread_mutex_init(&attr->die_mutex, NULL);
	pthread_mutex_init(&attr->eat_mutex, NULL);
}

static int		valid_attr(t_attr *attr)
{
	if (attr->iteration <= 0 || attr->phil_sleep <= 0 || \
		attr->phil_die <= 0 || attr->phil_eat <= 0 || attr->phil_num <= 0)
		return (PHILO_FALSE);
	return (PHILO_TRUE);
}

int		init_philosopher(t_philo **phil_arr, t_attr *attr)
{
	int		i;

	i = -1;
	*phil_arr = (t_philo *)malloc(sizeof(t_philo) * attr->phil_num);
	if (!*phil_arr)
		return (PHILO_ERR);
	while (++i < attr->phil_num)
	{
		(*phil_arr)[i].hand = i % 2;
		(*phil_arr)[i].philo_index = i;
		(*phil_arr)[i].attr = attr;			//referencing each other
		(*phil_arr)[i].last_eat = -1;
		(*phil_arr)[i].num_eat = 0;
	}
	return (PHILO_SUCC);
}

static int	init_chopsticks(t_attr *attr)
{
	pthread_mutex_t	*m_arr;
	int				i;
	int				state;
	int				j;

	m_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (attr->phil_num));
	if (!m_arr)
		return (PHILO_ERR);
	i = -1;
	while (++i < attr->phil_num)
	{
		state = pthread_mutex_init(&(m_arr[i]), NULL);
		if (state)
		{
			j = -1;
			while (++j < i -1)		//destory mutex till normal mut_init
				pthread_mutex_destroy(&(m_arr[j]));
			return (PHILO_ERR);
		}
	}
	attr->chopsticks = m_arr;
	return (PHILO_SUCC);
}

int		init_attr(t_attr **attr, char **argv, int argc)
{
	*attr = (t_attr *)malloc(sizeof(t_attr));
	if (!*attr)
		return (PHILO_ERR);
	init_arg(*attr, argv, argc);
	if (!valid_attr(*attr))
		return (PHILO_ERR);
	if (init_chopsticks(*attr) == PHILO_ERR)			//clean philo_t malloced.
		return (PHILO_ERR);
	return (PHILO_SUCC);
}
