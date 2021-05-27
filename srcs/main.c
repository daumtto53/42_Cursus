/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:18:47 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 13:52:41 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_ll	**ab_array;

	if (argc == 1)
		return (0);
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	printf("initialized\n");
	if (input_args(ab_array, argc, argv) == -1)
	{
		printf("free\n");
		exit(1);
	}
	return(0);
}
