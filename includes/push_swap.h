/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:53 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 22:51:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "linked_list.h"
# include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_freq
{
	int		push_opp;
	int		rotate_opp;
	int		rotate_this;
	int		non_rotated;
}				t_freq;

int				input_args(t_ll **ab_array, int arg_num, char **argv);

void			push_ab(t_ll **ab_array, int num_stack);
void			swap_ab(t_ll **ab_array, int num_stack);
void			rev_ab(t_ll **ab_array, int num_stack);
void			rrev_ab(t_ll **ab_array, int num_stack);

void			rrev_all(t_ll **ab_array);
void			rev_all(t_ll **ab_array);
void			swap_all(t_ll **ab_array);

int				*init_sorted_arg(t_ll **ab_array, int argc);
void			quick_sort(int *arr, int left, int right);
void			print_err_n_exit(void);
int				is_already_sorted(t_ll **ab_array);

void			traverse_list(t_ll **ab_array, int num_stack);
void			traverse_array(int *arr, int size);
void			traverse_ab(t_ll **ab_array);

int				**init_piv_array(int *arr, int arr_size);
int				get_pivot_array_size_a(int *a, int left, int right, int count);
int				get_pivot_array_size_b(int *a, int left, int right, int count);
int				**assign_piv_array_a(int **p_arr, int *ar, int left, int right);
int				**assign_piv_array_b(int **p_arr, int *ar, int left, int right);
int				**create_pivot_array(int *arr, int arr_size);

int				**sort_a(t_ll **ab_array, int **piv_arr, int sort_num);
void			begin_sort_a(t_ll **ab_array, int **piv_arr, int sort_num);

void			sort_a_132(t_ll **ab_array);
void			sort_a_321(t_ll **ab_array);
void			sort_a_312(t_ll **ab_array);
void			sort_a_213(t_ll **ab_array);
void			sort_a_231(t_ll **ab_array);

int				**sort_b(t_ll **ab_array, int **piv_arr, int sort_num);

void			sort_b_321(t_ll **ab_array);
void			sort_b_312(t_ll **ab_array);
void			sort_b_231(t_ll **ab_array);
void			sort_b_213(t_ll **ab_array);
void			sort_b_132(t_ll **ab_array);
void			sort_b_123(t_ll **ab_array);

void			init_freq(t_freq *freq);
void			restore_position(t_ll **ab_array, int stack_num, t_freq *freq);
void			sort_less_than_3(t_ll **ab_array);

#endif
