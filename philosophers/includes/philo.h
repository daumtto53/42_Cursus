/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/06/23 21:16:19 by mchun            ###   ########.fr       */
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
# define MILI_TO_MICRO	1000

typedef struct	s_attr	t_attr;
typedef struct	s_philo	t_philo;

typedef struct		s_philo
{
	int		hand;
	int		philo_index;
	int		last_eat;
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

//philo_utils.c
long long			ft_atoll(char *src);
void		free_attr(t_attr *attr);
void		terminate_data(t_attr *attr, pthread_t *tid_arr);

//philo_attr_init.c
int					init_attr(t_attr *attr, char **argv, int argc);
//philo_thread_init.c
pthread_t			*init_tid_arr(t_attr *attr);
//philo_act.c
int		is_5th_arg(t_attr *attr);
//philo_thread_start.c
int		philo_iterate(t_attr *attr, t_philo *p);
int		philo_infinite(t_attr *attr, t_philo *p);

void	act_taken_fork(t_attr *attr, t_philo *p);
void	act_eat(t_attr *attr, t_philo *p);
void	act_sleep(t_attr *attr, t_philo *p);
void	act_think(t_attr *attr, t_philo *p);
int		act_die(t_attr *attr, t_philo *p);

#endif
