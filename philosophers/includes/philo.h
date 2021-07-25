/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/07/25 23:40:40 by mchun            ###   ########.fr       */
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
# include <stdint.h>

# define LEFT			0
# define RIGHT			1
# define PHILO_SUCC		1
# define PHILO_ERR		-1
# define PHILO_TRUE		1
# define PHILO_FALSE	0
# define DEAD			1
# define FINISH_EAT		2
# define MILI_TO_MICRO	1000

typedef struct s_attr
{
	uint64_t			start_time_ms;
	uint64_t			phil_die;
	uint64_t			phil_eat;
	uint64_t			phil_sleep;
	int					phil_num;
	int					iteration;
	int					status;
	int					finished_philo;
	pthread_t			*phil_tid;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		die_mutex;
	pthread_mutex_t		*chopsticks;
}						t_attr;

typedef struct s_philo
{
	int					hand;
	int					philo_index;
	uint64_t			last_eat;
	int					num_eat;
	int					first_chop;
	int					second_chop;
	t_attr				*attr;
}						t_philo;

long long				ft_atoll(char *src);

void					terminate_data(t_attr *attr, t_philo *philo);

int						init_structure(t_attr **attr, t_philo **p, \
							char **argv, int argc);

int						philosopher(void *phil);

void					act_taken_fork(t_attr *attr, t_philo *p);
void					act_eat(t_attr *attr, t_philo *p);
void					act_sleep(t_attr *attr, t_philo *p);
void					act_think(t_attr *attr, t_philo *p);
int						act_only_one_philosopher(t_attr *attr);

uint64_t				get_time_in_ms(struct timeval *tv);
int						init_start_time_ms(t_philo *phil_arr, t_attr *attr);
uint64_t				get_timestamp(t_attr *attr);
void					smart_sleep(t_attr *attr, uint64_t usec);
uint64_t				get_time_ms(void);

#endif
