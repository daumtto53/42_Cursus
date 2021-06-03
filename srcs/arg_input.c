/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:14:17 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 20:03:56 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_arg_digit(char *ch)
{
	if (*ch == '-' && *(ch + 1) == '\0')
		return (0);
	if (*ch == '-')
		ch++;
	while (*ch)
	{
		if (!ft_isdigit(*ch))
			return (0);
		ch++;
	}
	return (1);
}

static int	is_arg_int_range(long num)
{
	return (num <= INT_MAX && num >= INT_MIN);
}

static int	is_arg_overlap(t_ll **ab_array, int num)
{
	t_ll	*l_list;
	t_node	*node;

	l_list = ab_array[STACK_A];
	if (l_list->size == 0)
		return (0);
	node = l_list->head;
	while (node->next != l_list->head)
	{
		if (node->data == num)
			return (1);
		node = node->next;
	}
	if (node->data == num)
		return (1);
	return (0);
}

int			input_args(t_ll **ab_array, int arg_num, char **argv)
{
	long	input_num;

	while (--arg_num > 0)
	{
		if (!is_arg_digit(argv[arg_num]))
			return (-1);
		input_num = ft_atol(argv[arg_num]);
		if (!is_arg_int_range(input_num))
			return (-1);
		if (is_arg_overlap(ab_array, input_num))
			return (-1);
		linked_list_push(ab_array, STACK_A, input_num);
	}
	return (1);
}
