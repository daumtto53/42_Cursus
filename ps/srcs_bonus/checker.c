/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:27:10 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 19:57:01 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

static int	main_checker(t_ll **ab_array, int size)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (*line == '\0')
		{
			print_checker_result(is_valid_result(ab_array, size));
			return (1);
		}
		else if (!is_valid_instruction(line))
			print_err_n_exit();
		execute_instruction(ab_array, line);
		if (is_already_sorted(ab_array, size))
		{
			ft_putstr_fd("OK\n", 1);
			return (1);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_ll	**ab_array;

	if (argc == 1)
		return (0);
	if (init_linked_list(&ab_array) == -1)
		return (-1);
	if (input_args(ab_array, argc, argv) == -1)
		print_err_n_exit();
	if (main_checker(ab_array, argc - 1))
		return (1);
	print_checker_result(is_valid_result(ab_array, argc - 1));
	return (0);
}
