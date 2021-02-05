/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:17:17 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 21:10:33 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

 int		printer_type_c(unsigned int k, t_info *info)
{
	unsigned char	c;
	char			fill;
	int				padd_len;

	c = (unsigned char)k;
	fill = (info->flag & F_ZERO) ? '0' : ' ';
	padd_len = (info->width > 1) ? info->width - 1 : 0;
	while (!(info->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	ft_putchar_fd(c, 1);
	while (info->flag & F_LJUST && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	return ((info->width > 1) ? info->width : 1);
}
