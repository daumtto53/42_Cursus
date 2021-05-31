/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:08:39 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 19:37:03 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	push_ab(t_ll **ab_array, int num_stack)
{
	int		stack_num_push;
	int		stack_num_pop;
	int		popped_data;

	stack_num_pop = !num_stack;
	stack_num_push = num_stack;

	if (ab_array[stack_num_pop]->size == 0)
		return ;
	linked_list_pop(ab_array, stack_num_pop, &popped_data);
	linked_list_push(ab_array, stack_num_push, popped_data);
}

void	swap_ab(t_ll **ab_array, int num_stack)
{
	t_ll	*stacks;
	t_node	*aux[3];

	stacks = ab_array[num_stack];
	if (stacks->size == 1 || stacks->size == 0)
		return ;
	aux[0] = stacks->tail->prev->prev;
	aux[1] = stacks->tail->prev;
	aux[2] = stacks->tail;
	if (stacks->size == 2)
	{
		stacks->head = aux[2];
		stacks->tail = aux[1];
	}
	else
	{
		aux[0]->next = aux[2];
		//aux[0]->prev = aux[1];
		aux[1]->next = stacks->head;
		aux[2]->next = aux[1];
		aux[1]->prev = aux[2];
		aux[2]->prev = aux[0];
		stacks->head->prev = aux[1];
		stacks->tail = aux[1];
	}
}

void	rev_ab(t_ll **ab_array, int num_stack)
{
	t_ll	*stacks = ab_array[num_stack];

	printf("REV_AB\n");
	stacks->head = stacks->tail;
	stacks->tail = stacks->tail->prev;
}

void	rrev_ab(t_ll **ab_array, int num_stack)
{
	t_ll	*stacks = ab_array[num_stack];

	printf("RREV_AB\n");
	stacks->tail = stacks->head;
	stacks->head = stacks->head->next;
}
