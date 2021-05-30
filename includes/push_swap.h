/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:53 by mchun             #+#    #+#             */
/*   Updated: 2021/05/30 13:16:14 by mchun            ###   ########.fr       */
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

// rough.c

//utils.c
int		*init_sorted_arg(t_ll **ab_array, int argc);
void	quick_sort(int *arr, int left, int right);
void	print_err_n_exit(void);

//custom.c
void	traverse_list(t_ll **ab_array, int num_stack);
void	traverse_array(int *arr, int size);

//pivot_array.c
int		**init_piv_array(int *arr, int arr_size);

//sort_less_n_equal_4.c
void	sort_a_132(t_ll **ab_array);
void	sort_a_321(t_ll **ab_array);
void	sort_a_312(t_ll **ab_array);
void	sort_a_213(t_ll **ab_array);
void	sort_a_231(t_ll **ab_array);

