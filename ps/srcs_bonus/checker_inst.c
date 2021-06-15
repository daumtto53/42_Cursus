/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:41:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 19:50:08 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker_swap_all(t_ll **ab_array)
{
	checker_swap_ab(ab_array, STACK_A);
	checker_swap_ab(ab_array, STACK_B);
}

void	checker_rev_all(t_ll **ab_array)
{
	t_ll	*stack_a;
	t_ll	*stack_b;

	stack_a = ab_array[STACK_A];
	stack_b = ab_array[STACK_B];
	if (stack_a->size != 0)
	{
		stack_a->head = stack_a->tail;
		stack_a->tail = stack_a->tail->prev;
	}
	if (stack_b->size != 0)
	{
		stack_b->head = stack_b->tail;
		stack_b->tail = stack_b->tail->prev;
	}
}

void	checker_rrev_all(t_ll **ab_array)
{
	t_ll	*stack_a;
	t_ll	*stack_b;

	stack_a = ab_array[STACK_A];
	stack_b = ab_array[STACK_B];
	if (stack_a->size != 0)
	{
		stack_a->tail = stack_a->head;
		stack_a->head = stack_a->head->next;
	}
	if (stack_b->size != 0)
	{
		stack_b->tail = stack_b->head;
		stack_b->head = stack_b->head->next;
	}
}
