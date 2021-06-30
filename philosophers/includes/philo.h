/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/06/30 18:18:59 by mchun            ###   ########.fr       */
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

typedef struct			s_attr
{
	uint64_t			start_time_ms;
	int					phil_num;
	int					iteration;
	uint64_t			phil_die;
	uint64_t			phil_eat;
	uint64_t			phil_sleep;
	int					is_dead;
	int					num_finish_eat;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		die_mutex;
	pthread_mutex_t		*chopsticks;
}						t_attr;

typedef struct			s_philo
{
	int					hand;
	int					philo_index;
	uint64_t			last_eat;
	int					num_eat;
	int					first_chop;
	int					second_chop;
	uint64_t			revision_time;
	t_attr				*attr;
}						t_philo;

long long				ft_atoll(char *src);

void					terminate_data(t_attr *attr, t_philo *philo, \
							pthread_t *tid_arr);

int						init_structure(t_attr **attr, t_philo **p, \
							char **argv, int argc);

pthread_t				*init_tid_arr(t_attr *attr);

int						is_5th_arg(t_attr *attr);

int						philo_iterate(t_attr *attr, t_philo *p);
int						philo_infinite(t_attr *attr, t_philo *p);

void					act_taken_fork(t_attr *attr, t_philo *p);
void					act_eat(t_attr *attr, t_philo *p);
void					act_sleep(t_attr *attr, t_philo *p);
void					act_think(t_attr *attr, t_philo *p);
int						act_only_one_philosopher(t_attr *attr);

uint64_t				get_time_in_ms(struct timeval *tv);
int						init_start_time_ms(t_philo *phil_arr, t_attr *attr);
uint64_t				get_timestamp(t_attr *attr);
void					smart_sleep(t_attr *attr, uint64_t usec);

#endif
