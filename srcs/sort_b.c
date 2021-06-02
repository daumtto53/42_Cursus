/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:00:07 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 21:41:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_b_less_n_equal_3(t_ll **ab_array, int sort_num)
{
	int		comp[3];

	comp[0] = ab_array[STACK_B]->tail->data;
	comp[1] = ab_array[STACK_B]->tail->prev->data;
	comp[2] = ab_array[STACK_B]->tail->prev->prev->data;
	if (sort_num == 1)
		push_ab(ab_array, STACK_A);
	else if (sort_num == 2)
	{
		if (comp[0] < comp[1])
			swap_ab(ab_array, STACK_B);
		push_ab(ab_array, STACK_A);
		push_ab(ab_array, STACK_A);
	}
	else if (sort_num == 3)
	{
		if (comp[0] < comp[1] && comp[1] < comp[2])
			sort_b_123(ab_array);
		else if (comp[1] > comp[2] && comp[2] > comp[0])
			sort_b_132(ab_array);
		else if (comp[2] > comp[0] && comp[0] > comp[1])
			sort_b_213(ab_array);
		else if (comp[1] > comp[0] && comp[0] > comp[2])
			sort_b_231(ab_array);
		else if (comp[0] > comp[2] && comp[2] > comp[1])
			sort_b_312(ab_array);
		else if (comp[0] > comp[1] && comp[1] > comp[2])
			sort_b_321(ab_array);
	}
}

int		**sort_b(t_ll **ab_array, int **piv_arr, int sort_num)
{
	t_freq	freq;
	t_node	*node;
	int		**piv_arr_cpy;
	int		node_data;

	if (sort_num <= 3)
	{
		sort_b_less_n_equal_3(ab_array, sort_num); // 정렬해야 할 원소 개수가 3개 이하일 때.
		return (piv_arr - 1);
	}
	init_freq(&freq);
	node = ab_array[STACK_B]->tail;							//partition_A 함수로 나눌 수 있을 듯..?
	while (sort_num-- > 0)
	{
		node_data = node->data;
		if ((*piv_arr)[0] >= node_data)
		{
			rev_ab(ab_array, STACK_B);
			freq.rotate_this++;
		}
		else
		{
			push_ab(ab_array, STACK_A);
			freq.push_opp++;
			if ((*piv_arr)[1] >= node_data)
			{
				rev_ab(ab_array, STACK_A);
				freq.rotate_opp++;
			}
		}
		node = ab_array[STACK_B]->tail;
	}
	freq.non_rotated = freq.push_opp - freq.rotate_opp;
	piv_arr_cpy = piv_arr;
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.non_rotated);
	restore_position(ab_array, STACK_B, &freq);
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_opp);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.rotate_this);
	return (piv_arr_cpy);
}

void	sort_b_321(t_ll **ab_array)
{
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
}
