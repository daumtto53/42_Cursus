/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:31 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 16:49:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*init_sorted_arg(t_ll **ab_array, int argc)
{
	int		*ret;
	t_node	*node;

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
		while (arr[j] < piv)
			j--;
		while (i < j && piv <= arr[i])
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
