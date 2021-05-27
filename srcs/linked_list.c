/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:29 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 13:52:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linked_list.h"

static void	init_linked_list_data(t_ll **ab_arr)
{
	ab_arr[STACK_A]->head = NULL;
	ab_arr[STACK_A]->tail = NULL;
	ab_arr[STACK_A]->size = 0;
	ab_arr[STACK_B]->head = NULL;
	ab_arr[STACK_B]->tail = NULL;
	ab_arr[STACK_B]->size = 0;
	return ;
}

int		init_linked_list(t_ll ***ab_arr)
{
	t_ll	**ab_array;

	ab_array = (t_ll **)malloc(sizeof(t_ll *) * 2);
	if (!ab_array)
		return (ft_print_error());
	ab_array[STACK_A] = (t_ll *)malloc(sizeof(t_ll));
	if (!ab_array[STACK_A])
	{
		free(ab_array);
		return (ft_print_error());
	}
	ab_array[STACK_B] = (t_ll *)malloc(sizeof(t_ll));
	if (!ab_array[STACK_B])
	{
		free(ab_array[STACK_A]);
		free(ab_array);
		return (ft_print_error());
	}
	init_linked_list_data(ab_array);
	*ab_arr = ab_array;
	return (1);
}

int		linked_list_push(t_ll **ab_arr, int	num_stack, int data)
{
	t_node	*new_node;
	t_ll	*l_list;

	l_list = ab_arr[num_stack];
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (ft_print_error());
		//malloc 에러 시 t_ll, 안의 모든 노드들 삭제하고 프로그램 종료.
	new_node->data = data;
	if (l_list->size == 0)
		l_list->head = new_node;
	else
	{
		l_list->tail->next = new_node;
		l_list->head->prev = new_node;
	}
	new_node->next = l_list->head;
	new_node->prev = l_list->tail;
	l_list->tail = new_node;
	l_list->size++;
	return (1);
}

int		linked_list_pop(t_ll **ab_arr, int num_stack, int *data)
{
	t_node	*aux_node;
	t_ll 	*l_list;

	l_list = ab_arr[num_stack];
	if (l_list->size == 0)
		return (ft_print_error());
	else if (l_list->size == 1)
	{
		*data = l_list->tail->data;
		free(l_list->tail);
		l_list->head = NULL;
		l_list->tail = NULL;
	}
	else
	{
		*data = l_list->tail->data;
		aux_node = l_list->tail;
		l_list->tail = l_list->tail->prev;
		l_list->tail->next = l_list->head;
		l_list->head->prev = l_list->tail;
		free(aux_node);
	}
	l_list->size--;
	return (1);
}

void	elim_linked_list(t_ll **ab_arr, int num_stack)
{
	t_node	*aux_node;
	t_node	*node;
	t_ll	*l_list;

	l_list = ab_arr[num_stack];
	if (!l_list->head)
		return ;
	node = l_list->head;
	while (l_list->tail != node)
	{
		aux_node = node;
		node = node->next;
		free(aux_node);
	}
	free(node);
}

