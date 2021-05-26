/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/05/26 20:38:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_ll	**ab_array;
	int		data;

	if (argc == 1)
		return (0);
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	printf("initialized\n");
	if (input_args(ab_array, argc, argv) == -1)
	{
		free_ab_array(ab_array);
		printf("free\n");
		return (-1);
	}
	traverse_list(ab_array);
	linked_list_push(ab_array, STACK_A, 200);
	traverse_list(ab_array);
	linked_list_pop(ab_array, STACK_A, &data);
	printf("popped data : %d\n", data);
	traverse_list(ab_array);
	return(0);
}
