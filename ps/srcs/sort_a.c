/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:19:25 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 13:33:20 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_a_less_n_equal_3(t_ll **ab_array, int sort_num)
{
	int		comp[3];

	comp[0] = ab_array[STACK_A]->tail->data;
	comp[1] = ab_array[STACK_A]->tail->prev->data;
	comp[2] = ab_array[STACK_A]->tail->prev->prev->data;
	if (sort_num == 2)
	{
		if (comp[0] > comp[1])
			swap_ab(ab_array, STACK_A);
	}
	if (sort_num == 3)
	{
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
	return ;
}

static void	partition_a(t_ll **ab, int **piv_arr, int sort_num, t_freq *f)
{
	t_node	*node;
	int		node_data;

	while (sort_num-- > 0)
	{
		node = ab[STACK_A]->tail;
		node_data = node->data;
		if ((*piv_arr)[1] < node->data)
		{
			rev_ab(ab, STACK_A);
			f->rotate_this++;
		}
		else
		{
			push_ab(ab, STACK_B);
			f->push_opp++;
			if ((*piv_arr)[0] < node_data)
			{
				rev_ab(ab, STACK_B);
				f->rotate_opp++;
			}
		}
	}
}

static void	partition_begin(t_ll **ab, int **piv_arr, int sort_num, t_freq *f)
{
	t_node	*node;
	int		node_data;

	while (sort_num-- > 0)
	{
		node = ab[STACK_A]->tail;
		node_data = node->data;
		if ((*piv_arr)[1] < node_data)
		{
			rev_ab(ab, STACK_A);
			f->rotate_this++;
		}
		else
		{
			push_ab(ab, STACK_B);
			f->push_opp++;
			if ((*piv_arr)[0] >= node_data)
			{
				rev_ab(ab, STACK_B);
				f->rotate_opp++;
			}
		}
	}
}

void		begin_sort_a(t_ll **ab_array, int **piv_arr, int sort_num)
{
	t_freq	freq;
	int		**piv_arr_cpy;

	init_freq(&freq);
	partition_begin(ab_array, piv_arr, sort_num, &freq);
	freq.non_rotated = freq.push_opp - freq.rotate_opp;
	piv_arr_cpy = piv_arr;
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_this);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.non_rotated);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.rotate_opp);
}

int			**sort_a(t_ll **ab_array, int **piv_arr, int sort_num)
{
	t_freq	freq;
	int		**piv_arr_cpy;

	if (sort_num <= 3)
	{
		sort_a_less_n_equal_3(ab_array, sort_num);
		return (piv_arr - 1);
	}
	init_freq(&freq);
	partition_a(ab_array, piv_arr, sort_num, &freq);
	restore_position(ab_array, STACK_A, &freq);
	freq.non_rotated = freq.push_opp - freq.rotate_opp;
	piv_arr_cpy = piv_arr;
	piv_arr_cpy = sort_a(ab_array, piv_arr_cpy + 1, freq.rotate_this);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.rotate_opp);
	piv_arr_cpy = sort_b(ab_array, piv_arr_cpy + 1, freq.non_rotated);
	return (piv_arr_cpy);
}
