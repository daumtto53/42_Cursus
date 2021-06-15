/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:06:11 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 19:20:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		is_valid_instruction(char *line)
{
	char	*l;

	l = line;
	if ((l[0] == 'p' && l[1] == 'a' && l[2] == '\0') || \
		(l[0] == 'p' && l[1] == 'b' && l[2] == '\0') || \
		(l[0] == 'r' && l[1] == 'a' && l[2] == '\0') || \
		(l[0] == 'r' && l[1] == 'b' && l[2] == '\0') || \
		(l[0] == 'r' && l[1] == 'r' && l[2] == '\0') || \
		(l[0] == 's' && l[1] == 'a' && l[2] == '\0') || \
		(l[0] == 's' && l[1] == 'b' && l[2] == '\0') || \
		(l[0] == 's' && l[1] == 's' && l[2] == '\0') || \
		(l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\0') || \
		(l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\0') || \
		(l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\0'))
		return (1);
	else
		return (0);
}

void	execute_instruction(t_ll **ab_array, char *line)
{
	char	*l;

	l = line;
	if (l[0] == 'p' && l[1] == 'a' && l[2] == '\0')
		checker_push_ab(ab_array, STACK_A);
	if (l[0] == 'p' && l[1] == 'b')
		checker_push_ab(ab_array, STACK_B);
	if (l[0] == 'r' && l[1] == 'a' && l[2] == '\0')
		checker_rev_ab(ab_array, STACK_A);
	if (l[0] == 'r' && l[1] == 'b' && l[2] == '\0')
		checker_rev_ab(ab_array, STACK_B);
	if (l[0] == 'r' && l[1] == 'r' && l[2] == '\0')
		checker_rev_all(ab_array);
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\0')
		checker_swap_ab(ab_array, STACK_A);
	if (l[0] == 's' && l[1] == 'b' && l[2] == '\0')
		checker_swap_ab(ab_array, STACK_B);
	if (l[0] == 's' && l[1] == 's' && l[2] == '\0')
		checker_swap_all(ab_array);
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\0')
		checker_rrev_ab(ab_array, STACK_A);
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\0')
		checker_rrev_ab(ab_array, STACK_B);
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\0')
		checker_rrev_all(ab_array);
}

int		is_valid_result(t_ll **ab_array, int size)
{
	if (!is_already_sorted(ab_array, size))
		return (0);
	if (ab_array[STACK_B]->size != 0)
		return (0);
	return (1);
}

void	print_checker_result(int is_valid)
{
	if (is_valid)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
