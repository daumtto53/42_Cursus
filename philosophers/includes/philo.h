/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 14:42:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# define LEFT			0
# define RIGHT			1
# define PHILO_SUCC		1
# define PHILO_ERR		-1
# define PHILO_TRUE		1
# define PHILO_FALSE	0

typedef struct	s_attr	t_attr;
typedef struct	s_philo	t_philo;

typedef struct		s_philo
{
	int		hand;
	int		philo_index;
	t_attr	*attr;
}					t_philo;

typedef struct		s_attr
{
	int				phil_num;
	int				iteration;
	long long		phil_die;
	long long		phil_eat;
	long long		phil_sleep;
	t_philo			*phil_arr;
	pthread_mutex_t	*chopsticks;
}					t_attr;


long long			ft_atoll(char *src);

int					init_attr(t_attr *attr, char **argv, int argc);

pthread_t			*init_tid_arr(t_attr *attr);

pthread_t	*init_tid_arr(t_attr *attr);

#endif
