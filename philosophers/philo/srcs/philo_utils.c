/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:52:50 by mchun             #+#    #+#             */
/*   Updated: 2021/07/30 17:30:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_atoll(char *src)
{
	long long	num;
	int			i;
	int			negative;

	if (!src)
		return (0);
	negative = 1;
	i = 0;
	while (src[i] == '\f' || src[i] == '\r' || src[i] == '\t' \
		|| src[i] == '\v' || src[i] == ' ' || src[i] == '\n')
		i++;
	if (src[i] == '-')
	{
		negative = -1;
		i++;
	}
	num = 0;
	while (src[i] >= '0' && src[i] <= '9')
		num = (num * 10) + (src[i++] - '0');
	return (negative * num);
}

void	terminate_data(t_attr *attr, t_philo *philo)
{
	int		i;

	i = -1;
	if (philo != NULL)
		while (++i < attr->phil_num)
			pthread_mutex_destroy(&attr->chopsticks[i]);
	free(attr->chopsticks);
	pthread_mutex_destroy(&attr->die_mutex);
	pthread_mutex_destroy(&attr->eat_mutex);
	free(attr->phil_tid);
	free(philo);
	free(attr);
	return ;
}
