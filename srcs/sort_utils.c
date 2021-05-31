/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:54:10 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 18:56:40 by mchun            ###   ########.fr       */
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
	printf("min_inst %d\t\t rotate_opp : %d\t\t rotate_this %d\n", min_inst, freq->rotate_opp, freq->rotate_this);
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
