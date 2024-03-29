/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_less_n_equal_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:03:21 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 21:39:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_132(t_ll **ab_array)
{
	rev_ab(ab_array, STACK_A);
	swap_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
}

void	sort_a_321(t_ll **ab_array)
{
	push_ab(ab_array, STACK_B);
	swap_ab(ab_array, STACK_A);
	rev_ab(ab_array, STACK_A);
	rev_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
}

void	sort_a_312(t_ll **ab_array)
{
	push_ab(ab_array, STACK_B);
	rev_ab(ab_array, STACK_A);
	rev_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
}

void	sort_a_213(t_ll **ab_array)
{
	swap_ab(ab_array, STACK_A);
}

void	sort_a_231(t_ll **ab_array)
{
	push_ab(ab_array, STACK_B);
	push_ab(ab_array, STACK_B);
	rev_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	push_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_A);
}
