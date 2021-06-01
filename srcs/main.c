/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/01 18:40:20 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int inst_count = 0;

int		main(int argc, char **argv)
{
	t_ll	**ab_array;
	int		*sorted_arg;
	int		**piv_array;

	if (argc == 1)
		return (0);
	//연결리스트 초기화
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	printf("LINKED_LIST_INITIALIZED.\n");
	//연결리스트에 인자 검사 -> 연결리스트에 인자 push
	if (input_args(ab_array, argc, argv) == -1)
		print_err_n_exit();
	// if sorted ?
	if (is_already_sorted(ab_array))
		return (0);
	sorted_arg = init_sorted_arg(ab_array, argc);
	if (!sorted_arg)
		print_err_n_exit();
	piv_array = init_piv_array(sorted_arg, argc - 1);
	if (!piv_array)
		print_err_n_exit();

	printf("\n-----\n");
	traverse_ab(ab_array);

	sort_a(ab_array, piv_array, argc - 1);

	printf("------FINAL_OUTPUT-----\n");
	traverse_ab(ab_array);

	printf("\n-----inst_count : %d----\n", inst_count);
	return(0);
}
