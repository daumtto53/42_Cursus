/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 22:51:53 by mchun            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_ll	**ab_array;
	int		*sorted_arg;
	int		**piv_array;

	if (argc == 1)
		return (0);
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	if (input_args(ab_array, argc, argv) == -1)
		print_err_n_exit();
	if (is_already_sorted(ab_array))
		return (0);
	if (ab_array[STACK_A]->size <= 3)
	{
		sort_less_than_3(ab_array);
		return (0);
	}
	sorted_arg = init_sorted_arg(ab_array, argc);
	if (!sorted_arg)
		print_err_n_exit();
	piv_array = init_piv_array(sorted_arg, argc - 1);
	if (!piv_array)
		print_err_n_exit();
	begin_sort_a(ab_array, piv_array, argc - 1);
	return (0);
}
