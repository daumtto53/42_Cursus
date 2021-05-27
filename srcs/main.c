/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 16:50:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_ll	**ab_array;
	int		*sorted_arg;

	if (argc == 1)
		return (0);
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	printf("initialized\n");
	if (input_args(ab_array, argc, argv) == -1)
		print_err_n_exit();
	sorted_arg = init_sorted_arg(ab_array, argc);
	if (!sorted_arg)
		print_err_n_exit();
	traverse_array(sorted_arg, argc - 1);
	quick_sort(sorted_arg, 0, argc - 2);
	traverse_array(sorted_arg, argc - 1);
	return(0);
}
