/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:53 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 16:49:34 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "linked_list.h"
#include "../libft/libft.h"

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
