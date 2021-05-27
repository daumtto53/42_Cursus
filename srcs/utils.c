/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:31 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 13:30:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// exit() 사용하면 되므로 사용할 이유가 없어졌음.
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

int		count_linked_list_num(t_ll **ab_array)
{
	t_ll	*list = ab_array[STACK_A];
	t_node	*node = list->head;
	int		count;

	count = 0;
	while (node->next != list->head)
	{
		count++;
		node = node->next;
	}
	count++;
	return (count);
}
