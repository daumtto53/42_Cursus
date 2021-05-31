/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_less_n_equal_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 23:36:56 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 13:03:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_123(t_ll **ab_array)
{
	rev_ab(ab_array, STACK_B);
	swap_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
}

void	sort_b_132(t_ll **ab_array)
{
	rev_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
}

void	sort_b_213(t_ll **ab_array)
{
	rev_ab(ab_array, STACK_B);
	swap_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_B);
}

void	sort_b_231(t_ll **ab_array)
{
	swap_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
}

void	sort_b_312(t_ll **ab_array)
{
	push_ab(ab_array, STACK_A);
	swap_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
}

void	sort_b_321(t_ll **ab_array)
{
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
}
