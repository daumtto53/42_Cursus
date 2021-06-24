/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/06/24 19:53:18 by mchun            ###   ########.fr       */
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
	long	last_eat;					//
	t_attr	*attr;
}					t_philo;

typedef struct		s_attr
{
	long			start_time_ms;
	int				phil_num;
	int				iteration;
	long long		phil_die;
	long long		phil_eat;
	long long		phil_sleep;
	int				is_dead;			//
	int				num_finish_eat;
	t_philo			*phil_arr;
	pthread_mutex_t	die_mutex;
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
void	act_die(t_attr *attr, t_philo *p);

//philo_time.c
long	get_time_in_ms(struct timeval *tv);
int		init_start_time_ms(t_attr *attr);
long	get_timestamp(t_attr *attr);
int		is_phil_dead(t_attr *attr, t_philo *p, long *dead_time);

#endif
