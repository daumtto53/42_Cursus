/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:00:07 by mchun             #+#    #+#             */
/*   Updated: 2021/05/30 14:13:23 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		**sort_b(t_ll **ab_array, int **piv_arr, int sort_num)
{
	t_freq	freq;
	t_node	*node;
	int		**piv_arr_cpy;

	if (sort_num <= 3)
	{
		sort_b_less_n_equal_3(ab_array, sort_num); // 정렬해야 할 원소 개수가 3개 이하일 때.
		return (piv_arr - 1);
	}
	init_freq(&freq);
	node = ab_array[STACK_B]->head;							//partition_A 함수로 나눌 수 있을 듯..?
	while (sort_num-- > 0)
	{
		if ((*piv_arr)[0] <= node->data)
		{
			rev_ab(ab_array, STACK_B);
			freq.rotate_this++;
		}
		else
		{
			push_ab(ab_array, STACK_A);
			freq.push_opp++;
			if ((*piv_arr)[1] <= node->data)
			{
				rev_ab(ab_array, STACK_B);
				freq.rotate_opp++;
			}
		}
		node = node->next;
	}
	//
	freq.non_rotated = freq.push_opp - freq.rotate_opp;
	piv_arr_cpy = piv_arr;
	ab_array[0]->size = freq.rotate_this;
	ab_array[1]->size = freq.push_opp;
	//
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.non_rotated);
	restore_position(ab_array, STACK_B, &freq);
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_opp);
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_this);
	return (piv_arr_cpy);
}
