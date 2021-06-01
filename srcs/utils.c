/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:31 by mchun             #+#    #+#             */
/*   Updated: 2021/06/01 18:39:19 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*init_sorted_arg(t_ll **ab_array, int argc)
{
	int		*ret;
	t_node	*node;
	int		ret_size;

	ret_size = argc - 1;
	node = ab_array[STACK_A]->head;
	ret = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ret)
		return (ret);
	argc--;
	while (--argc >= 0)
	{
		ret[argc] = node->data;
		node = node->next;
	}
	traverse_array(ret, ret_size);
	quick_sort(ret, 0, ret_size - 1);
	traverse_array(ret, ret_size);
	return (ret);
}

static int		partition(int *arr, int left, int right)
{
	int		i;
	int		j;
	int		piv;
	int		aux;

	i = left;
	j = right;
	piv = arr[left];
	while (i < j)
	{
		while (arr[j] > piv)
			j--;
		while (i < j && piv >= arr[i])
			i++;
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
	}
	arr[left] = arr[i];
	arr[i] = piv;
	return (i);
}

void	quick_sort(int *arr, int left, int right)
{
	int		piv_index;

	if (left >= right)
		return ;
	piv_index = partition(arr, left, right);
	quick_sort(arr, left, piv_index - 1);
	quick_sort(arr, piv_index + 1, right);
}

void	print_err_n_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int		is_already_sorted(t_ll **ab_array)
{
	int		list_size;
	t_node	*node;

	list_size = ab_array[STACK_A]->size;
	if (list_size == 1)
		return (0);
	node = ab_array[STACK_A]->tail;
	while (list_size-- > 1)
	{
		if (node->data > node->prev->data)
			return (0);
		node = node->prev;
	}
	printf("is_already_sorted\n");
	return (1);
}
