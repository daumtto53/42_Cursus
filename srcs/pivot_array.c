/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:44:08 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 15:29:52 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_pivot_array_size(int *arr, int left, int right, int count)
{
	int		k;
	int		piv_a;
	int		piv_b;

	if (right - left <= 2)
		return (count);
	k = (right - left + 1) / 3;
	piv_a = left + k;
	piv_b = left + 2 * k;
	printf("left, right, count : %d %d %d\n", left, right, count);
	count = get_pivot_array_size(arr, left, piv_a, count);
	count = get_pivot_array_size(arr, piv_a + 1, piv_b, count);
	count = get_pivot_array_size(arr, piv_b + 1, right, count);
	return (count + 1);
}

static int		**create_pivot_array(int *arr, int arr_size)
{
	int		**new_piv_arr;
	int		piv_array_size;
	int		*piv_ab;
	int		i;

	piv_array_size = get_pivot_array_size(arr, 0, arr_size - 1, 0);
	printf("piv_array_size : %d\n", piv_array_size);
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

static int		**assign_piv_array(int **piv_arr, int *arr, int left, int right)
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
	piv_arr = assign_piv_array(piv_arr + 1, arr, left, piv_a);
	piv_arr = assign_piv_array(piv_arr + 1, arr, piv_a + 1, piv_b);
	piv_arr = assign_piv_array(piv_arr + 1, arr, piv_b + 1, right);
	return (piv_arr);
}

int		**init_piv_array(int *arr, int arr_size)
{
	int **piv_array;
	int	**piv_array_cpy;

	piv_array = create_pivot_array(arr, arr_size);
	if (!piv_array)
		return (NULL);
	piv_array_cpy = piv_array;
	assign_piv_array(piv_array_cpy, arr, 0, arr_size - 1);		//error?
	int		size;
	size = get_pivot_array_size(arr, 0, arr_size - 1, 0);
	printf("size : %d\n", size);
	for (int i = 0 ; i < size; i++)
		printf("%d %d\t", piv_array[i][0], piv_array[i][1]);
	return (piv_array);
}
