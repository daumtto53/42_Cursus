/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/06/22 18:48:32 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define LEFT	0
# define RIGHT	1

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct		philo_s
{
	int		hand;
	int		philo_index;
}					philo_t;

typedef struct		attr_s
{
	int		phil_num;
	int		iteration;
	unsigned long long		phil_die;
	unsigned long long		phil_eat;
	unsigned long long		phil_sleep;
}					attr_t;

#endif
