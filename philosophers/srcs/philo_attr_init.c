/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_attr_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:20:46 by mchun             #+#    #+#             */
/*   Updated: 2021/06/30 20:45:59 by mchun            ###   ########.fr       */
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
	attr->chopsticks = NULL;
	pthread_mutex_init(&attr->die_mutex, NULL);
	pthread_mutex_init(&attr->eat_mutex, NULL);
}

static int	valid_attr(t_attr *attr)
{
	if (attr->iteration <= 0 || attr->phil_sleep <= 0 || \
		attr->phil_die <= 0 || attr->phil_eat <= 0 || attr->phil_num <= 0)
		return (PHILO_FALSE);
	return (PHILO_TRUE);
}

static int	init_chopsticks(t_attr *attr)
{
	pthread_mutex_t	*m_arr;
	int				i;

	m_arr = malloc(sizeof(pthread_mutex_t) * (attr->phil_num));
	if (!m_arr)
		return (PHILO_ERR);
	i = -1;
	while (++i < attr->phil_num)
		pthread_mutex_init(&(m_arr[i]), NULL);
	attr->chopsticks = m_arr;
	return (PHILO_SUCC);
}

int			init_philosopher(t_philo **phil_arr, t_attr *at)
{
	int		i;

	i = -1;
	*phil_arr = (t_philo *)malloc(sizeof(t_philo) * at->phil_num);
	if (!*phil_arr)
		return (PHILO_ERR);
	while (++i < at->phil_num)
	{
		(*phil_arr)[i].hand = i % 2;
		(*phil_arr)[i].philo_index = i;
		(*phil_arr)[i].attr = at;
		(*phil_arr)[i].last_eat = -1;
		(*phil_arr)[i].num_eat = 0;
		if (i % 2 == LEFT)
		{
			(*phil_arr)[i].first_chop = (i - 1 + at->phil_num) % at->phil_num;
			(*phil_arr)[i].second_chop = i % at->phil_num;
		}
		else
		{
			(*phil_arr)[i].first_chop = i % at->phil_num;
			(*phil_arr)[i].second_chop = (i - 1 + at->phil_num) % at->phil_num;
		}
	}
	return (PHILO_SUCC);
}

int			init_structure(t_attr **attr, t_philo **p_arr, char **argv, int ac)
{
	if (!(ac == 5 || ac == 6))
		return (PHILO_ERR);
	*attr = (t_attr *)malloc(sizeof(t_attr));
	if (!*attr)
		return (PHILO_ERR);
	init_arg(*attr, argv, ac);
	if ((*attr)->phil_num == 1)
	{
		act_only_one_philosopher(*attr);
		terminate_data(*attr, NULL, NULL);
		return (PHILO_ERR);
	}
	if (!valid_attr(*attr))
	{
		terminate_data(*attr, NULL, NULL);
		return (PHILO_ERR);
	}
	if (init_chopsticks(*attr) == PHILO_ERR)
	{
		terminate_data(*attr, NULL, NULL);
		return (PHILO_ERR);
	}
	if (init_philosopher(p_arr, *attr) == PHILO_ERR)
		return (PHILO_ERR);
	return (PHILO_SUCC);
}
