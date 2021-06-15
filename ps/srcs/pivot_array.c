/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:44:08 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 22:50:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			get_pivot_array_size_a(int *arr, int left, int right, int count)
{
	int		k;
	int		piv_a;
	int		piv_b;

	if (right - left <= 2)
		return (count);
	k = (right - left + 1) / 3;
	piv_a = left + k;
	piv_b = left + 2 * k;
	count = get_pivot_array_size_a(arr, piv_b + 1, right, count);
	count = get_pivot_array_size_b(arr, piv_a + 1, piv_b, count);
	count = get_pivot_array_size_b(arr, left, piv_a, count);
	return (count + 1);
}

int			get_pivot_array_size_b(int *arr, int left, int right, int count)
{
	int		k;
	int		piv_a;
	int		piv_b;

	if (right - left <= 2)
		return (count);
	k = (right - left + 1) / 3;
	piv_a = left + k;
	piv_b = left + 2 * k;
	count = get_pivot_array_size_a(arr, piv_b + 1, right, count);
	count = get_pivot_array_size_a(arr, piv_a + 1, piv_b, count);
	count = get_pivot_array_size_b(arr, left, piv_a, count);
	return (count + 1);
}

int			**create_pivot_array(int *arr, int arr_size)
{
	int		**new_piv_arr;
	int		piv_array_size;
	int		*piv_ab;
	int		i;

	piv_array_size = get_pivot_array_size_a(arr, 0, arr_size - 1, 0);
	new_piv_arr = (int **)malloc(sizeof(int *) * piv_array_size);
	if (!new_piv_arr)
		return (NULL);
	i = 0;
	while (i < piv_array_size)
	{
		piv_ab = (int *)malloc(sizeof(int) * 2);
		if (!piv_ab)
			return (NULL);
		new_piv_arr[i++] = piv_ab;
	}
	return (new_piv_arr);
}

int			**assign_piv_array_a(int **piv_arr, int *arr, int left, int right)
{
	int		k;
	int		piv_a;
	int		piv_b;

	if (right - left <= 2)
		return (piv_arr - 1);
	k = (right - left + 1) / 3;
	piv_a = left + k;
	piv_b = left + 2 * k;
	(*piv_arr)[0] = arr[piv_a];
	(*piv_arr)[1] = arr[piv_b];
	piv_arr = assign_piv_array_a(piv_arr + 1, arr, piv_b + 1, right);
	piv_arr = assign_piv_array_b(piv_arr + 1, arr, piv_a + 1, piv_b);
	piv_arr = assign_piv_array_b(piv_arr + 1, arr, left, piv_a);
	return (piv_arr);
}

int			**assign_piv_array_b(int **piv_arr, int *arr, int left, int right)
{
	int		k;
	int		piv_a;
	int		piv_b;

	if (right - left <= 2)
		return (piv_arr - 1);
	k = (right - left + 1) / 3;
	piv_a = left + k;
	piv_b = left + 2 * k;
	(*piv_arr)[0] = arr[piv_a];
	(*piv_arr)[1] = arr[piv_b];
	piv_arr = assign_piv_array_a(piv_arr + 1, arr, piv_b + 1, right);
	piv_arr = assign_piv_array_a(piv_arr + 1, arr, piv_a + 1, piv_b);
	piv_arr = assign_piv_array_b(piv_arr + 1, arr, left, piv_a);
	return (piv_arr);
}
