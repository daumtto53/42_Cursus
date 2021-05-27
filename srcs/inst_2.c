/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:41:47 by mchun             #+#    #+#             */
/*   Updated: 2021/05/27 14:50:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_all(t_ll **ab_array)
{
	swap_ab(ab_array, STACK_A);
	swap_ab(ab_array, STACK_B);
}

void	rev_all(t_ll **ab_array)
{
	rev_ab(ab_array, STACK_A);
	rev_ab(ab_array, STACK_B);
}

void	rrev_all(t_ll **ab_array)
{
	rrev_ab(ab_array, STACK_A);
	rrev_ab(ab_array, STACK_B);
}
