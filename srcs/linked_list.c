/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:29 by mchun             #+#    #+#             */
/*   Updated: 2021/05/26 15:14:57 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linked_list.h"
#include "../includes/push_swap.h"

int		init_linked_list(t_ll ***ab_arr)
{
	t_ll	**ab_array;

	ab_array = (t_ll **)malloc(sizeof(t_ll *) * 2);
	if (!ab_array)
		return (print_error());
	ab_array[STACK_A] = (t_ll *)malloc(sizeof(t_ll));
	if (!ab_array[STACK_A])
	{
		free(ab_array);
		return (print_error());
	}
	ab_array[STACK_B] = (t_ll *)malloc(sizeof(t_ll));
	if (!ab_array[STACK_B])
	{
		free(ab_array[STACK_A]);
		free(ab_array);
		return (print_error());
	}
	init_linked_list_data(ab_array);
	*ab_arr = ab_array;
	return (0);
}

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

void	linked_list_push(t_ll **ab_arr, int	num_stack)
{

}

void	linked_list_pop(t_ll **ab_arr, int num_stack)
{

}

void	delete_linked_list(t_ll **ab_arr, int num_stack)
{

}

