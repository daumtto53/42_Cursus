/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:19:25 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 18:07:02 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_a_less_n_equal_3(t_ll **ab_array, int sort_num)
{
	int		comp[3];

	printf("SORT_A_LESS_N_EQUAL_3\n");
	comp[0] = ab_array[STACK_A]->tail->data;
	comp[1] = ab_array[STACK_A]->tail->prev->data;
	comp[2] = ab_array[STACK_A]->tail->prev->prev->data;
	if (sort_num == 1)
	{
		printf("sort_num == 1\n");
		return ;
	}
	else if (sort_num == 2)
	{
		printf("sort_num == 2\n");
		if (comp[0] > comp[1])
			swap_ab(ab_array, STACK_A);
	}
	else if (sort_num == 3)
	{
		printf("sort_num == 3\n");
		if (comp[1] > comp[2] && comp[2] > comp[0])
			sort_a_132(ab_array);
		else if (comp[0] > comp[1] && comp[1] > comp[2])
			sort_a_321(ab_array);
		else if (comp[0] > comp[2] && comp[2] > comp[1])
			sort_a_312(ab_array);
		else if (comp[2] > comp[0] && comp[0] > comp[1])
			sort_a_213(ab_array);
		else if (comp[1] > comp[0] && comp[0] > comp[2])
			sort_a_231(ab_array);
	}
	else
		printf("SORT_A_LESS_THAN_EQUAL_3 : wrong sort_num in arg\n");
	traverse_ab(ab_array);
	return ;
}

int		**sort_a(t_ll **ab_array, int **piv_arr, int sort_num)
{
	t_freq	freq;
	t_node	*node;
	int		**piv_arr_cpy;
	int		node_data;

	printf("SORT_A\n");
	if (sort_num <= 3)
	{
		printf("SORT_NUM < = 3\n");
		sort_a_less_n_equal_3(ab_array, sort_num); // 정렬해야 할 원소 개수가 3개 이하일 때.
		return (piv_arr - 1);
	}
	init_freq(&freq);
	node = ab_array[STACK_A]->tail;							//partition_A 함수로 나눌 수 있을 듯..?
	while (sort_num-- > 0)
	{
		node_data = node->data;
		if ((*piv_arr)[1] < node->data)
		{
			rev_ab(ab_array, STACK_A);
			freq.rotate_this++;
		}
		else
		{
			push_ab(ab_array, STACK_B);
			freq.push_opp++;
			if ((*piv_arr)[0] < node_data)
			{
				rev_ab(ab_array, STACK_B);
				freq.rotate_opp++;
			}
		}
		traverse_ab(ab_array);
		node = ab_array[STACK_A]->tail;
	}
	restore_position(ab_array, STACK_A, &freq);

	traverse_ab(ab_array);

	freq.non_rotated = freq.push_opp - freq.rotate_opp;
	piv_arr_cpy = piv_arr;
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_this);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.rotate_opp);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.non_rotated);
	return (piv_arr_cpy);
}
