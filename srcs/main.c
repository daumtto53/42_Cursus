/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/05/31 15:49:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	// 연결리스트 검증 완료.
	sorted_arg = init_sorted_arg(ab_array, argc);
	if (!sorted_arg)
		print_err_n_exit();
	piv_array = init_piv_array(sorted_arg, argc - 1);
	if (!piv_array)
		print_err_n_exit();
	sort_a(ab_array, piv_array, argc - 1);

	printf("STACK A IN MAIN : \n");
	traverse_list(ab_array, STACK_A);
	printf("STACK B IN MAIN : \n");
	traverse_list(ab_array, STACK_B);
	return(0);
}
