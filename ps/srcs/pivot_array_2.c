/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_array_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:33:33 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 19:51:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		**init_piv_array(int *arr, int arr_size)
{
	int		**piv_array;
	int		**piv_array_cpy;
	int		size;

	piv_array = create_pivot_array(arr, arr_size);
	if (!piv_array)
		return (NULL);
	piv_array_cpy = piv_array;
	assign_piv_array_a(piv_array_cpy, arr, 0, arr_size - 1);
	size = get_pivot_array_size_a(arr, 0, arr_size - 1, 0);
	return (piv_array);
}
