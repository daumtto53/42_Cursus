/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:41:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/01 17:20:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_all(t_ll **ab_array)
{
	swap_ab(ab_array, STACK_A);
	swap_ab(ab_array, STACK_B);
}

void	rev_all(t_ll **ab_array)
{
	t_ll	*stack_a;
	t_ll	*stack_b;

	stack_a = ab_array[STACK_A];
	stack_b = ab_array[STACK_B];

	stack_a->head = stack_a->tail;
	stack_a->tail = stack_a->tail->prev;
	stack_b->head = stack_b->tail;
	stack_b->tail = stack_b->tail->prev;
	inst_count++;
	printf("###### REV_ALL ######\n");
}

void	rrev_all(t_ll **ab_array)
{
	t_ll	*stack_a;
	t_ll	*stack_b;

	stack_a = ab_array[STACK_A];
	stack_b = ab_array[STACK_B];

	stack_a->tail = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b->tail = stack_b->head;
	stack_b->head = stack_b->head->next;
	inst_count++;
	printf("##### RREV_ALL ##### \n");
}
