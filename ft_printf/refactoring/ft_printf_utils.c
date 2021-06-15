/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:22:16 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 16:17:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdio.h>

int		is_valid_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == '%' || \
				c == 'd' || c == 'i' || c == 'u' || \
				c == 'X' || c == 'x');
}

void	debug_p_info(t_info *p)
{

	printf("type : %c\n", p->type);
	printf("width : %d\n", p->width);
	printf("precision : %d\n", p->prec);
	printf("flag : %d\n", p->flag);
}
