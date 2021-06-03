/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:40:48 by mchun             #+#    #+#             */
/*   Updated: 2021/06/03 19:58:34 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "../gnl/includes/get_next_line.h"

void	print_checker_result(int is_valid);
int		is_valid_result(t_ll **ab_array, int size);
void	execute_instruction(t_ll **ab_array, char *line);
int		is_valid_instruction(char *line);

void	checker_rrev_ab(t_ll **ab_array, int num_stack);
void	checker_rev_ab(t_ll **ab_array, int num_stack);
void	checker_swap_ab(t_ll **ab_array, int num_stack);
void	checker_push_ab(t_ll **ab_array, int num_stack);

void	checker_swap_all(t_ll **ab_array);
void	checker_rev_all(t_ll **ab_array);
void	checker_rrev_all(t_ll **ab_array);

#endif
