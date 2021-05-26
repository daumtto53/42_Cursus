/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:31 by mchun             #+#    #+#             */
/*   Updated: 2021/05/26 20:33:44 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ab_array(t_ll **ab_array)
{
	elim_linked_list(ab_array, STACK_A);
	elim_linked_list(ab_array, STACK_B);
	free(ab_array[STACK_A]);
	free(ab_array[STACK_B]);
	free(ab_array);
}

//for testing
void	traverse_list(t_ll **ab_array)
{
	t_ll	*list =  ab_array[STACK_A];
	t_node	*node = list->head;

	while (node->next != list->head)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}
