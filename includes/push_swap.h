/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:53 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 14:25:27 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "linked_list.h"
#include "../libft/libft.h"

typedef struct	s_freq
{
	int		push_opp;		//pa, pb
	int		rotate_opp;		//rb, ra
	int		rotate_this;	//rb, ra
	int		non_rotated;
}				t_freq;
// arg_input.c
int			input_args(t_ll **ab_array, int arg_num, char **argv);

// inst.c
void	push_ab(t_ll **ab_array, int num_stack);
void	swap_ab(t_ll **ab_array, int num_stack);
void	rev_ab(t_ll **ab_array, int num_stack);
void	rrev_ab(t_ll **ab_array, int num_stack);

// inst_2.c
void	rrev_all(t_ll **ab_array);
void	rev_all(t_ll **ab_array);
void	swap_all(t_ll **ab_array);

//utils.c
int		*init_sorted_arg(t_ll **ab_array, int argc);
void	quick_sort(int *arr, int left, int right);
void	print_err_n_exit(void);
int		is_already_sorted(t_ll **ab_array);

//custom.c
void	traverse_list(t_ll **ab_array, int num_stack);
void	traverse_array(int *arr, int size);
void	traverse_ab(t_ll **ab_array);

//pivot_array.c
int		**init_piv_array(int *arr, int arr_size);
int		get_pivot_array_size_a(int *arr, int left, int right, int count);
int		get_pivot_array_size_b(int *arr, int left, int right, int count);
int		**assign_piv_array_a(int **piv_arr, int *arr, int left, int right);
int		**assign_piv_array_b(int **piv_arr, int *arr, int left, int right);

//sort_a.c
int		**sort_a(t_ll **ab_array, int **piv_arr, int sort_num);
void	begin_sort_a(t_ll **ab_array, int **piv_arr, int sort_num);

//sort_a_less_n_equal_4.c
void	sort_a_132(t_ll **ab_array);
void	sort_a_321(t_ll **ab_array);
void	sort_a_312(t_ll **ab_array);
void	sort_a_213(t_ll **ab_array);
void	sort_a_231(t_ll **ab_array);

//sort_b.c
int		**sort_b(t_ll **ab_array, int **piv_arr, int sort_num);

//sort_b_less_n_equal_4.c
void	sort_b_321(t_ll **ab_array);
void	sort_b_312(t_ll **ab_array);
void	sort_b_231(t_ll **ab_array);
void	sort_b_213(t_ll **ab_array);
void	sort_b_132(t_ll **ab_array);
void	sort_b_123(t_ll **ab_array);

// sort_utils.c
void	init_freq(t_freq *freq);
void	restore_position(t_ll **ab_array, int stack_num, t_freq *freq);
void	sort_less_than_3(t_ll **ab_array);

extern int inst_count;
