/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:54:10 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 18:57:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_freq(t_freq *freq)
{
	freq->push_opp = 0;
	freq->rotate_opp = 0;
	freq->non_rotated = 0;
	freq->rotate_this = 0;
}

void	restore_position(t_ll **ab_array, int stack_num, t_freq *freq)
{
	int		surplus_inst;
	t_ll	*stack;
	int		min_inst;

	stack = ab_array[stack_num];
	min_inst = freq->rotate_opp;
	if (freq->rotate_opp - freq->rotate_this > 0)
	{
		min_inst = freq->rotate_this;
		surplus_inst = freq->rotate_opp - freq->rotate_this;
		while (surplus_inst-- > 0)
			rrev_ab(ab_array, !stack_num);
	}
	if (freq->rotate_this - freq->rotate_opp > 0)
	{
		min_inst = freq->rotate_opp;
		surplus_inst = freq->rotate_this - freq->rotate_opp;
		while (surplus_inst-- > 0)
			rrev_ab(ab_array, stack_num);
	}
	while (min_inst-- > 0)
		rrev_all(ab_array);
}

static void	sort_3_elements(t_ll **ab_array, int d_0, int d_1, int d_2)
{
	if (d_1 > d_2 && d_2 > d_0)
	{
		rrev_ab(ab_array, STACK_A);
		swap_ab(ab_array, STACK_A);
	}
	else if (d_2 > d_0 && d_0 > d_1)
		swap_ab(ab_array, STACK_A);
	else if (d_1 > d_0 && d_0 > d_2)
		rrev_ab(ab_array, STACK_A);
	else if (d_0 > d_1 && d_1 > d_2)
	{
		swap_ab(ab_array, STACK_A);
		rrev_ab(ab_array, STACK_A);
	}
	else if (d_0 > d_2 && d_2 > d_1)
		rev_ab(ab_array, STACK_A);
	return ;
}

void	sort_less_than_3(t_ll **ab_array)
{
	t_node	*node;
	int		data[3];

	node = ab_array[STACK_A]->tail;
	data[0] = node->data;
	data[1] = node->prev->data;
	data[2] = node->prev->prev->data;
	if (ab_array[STACK_A]->size == 2)
	{
		if (node->data > node->prev->data)
			swap_ab(ab_array, STACK_A);
	}
	else if (ab_array[STACK_A]->size == 3)
		sort_3_elements(ab_array, data[0], data[1], data[2]);
}
