/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:37:41 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 21:09:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_s(char *str, t_info *info)
{
	int		strlength;
	char	fill;
	int		padd_len;

	fill = (info->flag & F_ZERO) ? '0' : ' ';
	if (str == NULL)
		str = "null";
	if (info->flag & F_PREC && info->prec < (int)ft_strlen(str))
		strlength = info->prec;
	else
		strlength = ft_strlen(str);
	padd_len = (info->width > strlength) ? strlength - info->width : 0;
	while (!(info->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	write(1, str, strlength);
	while (info->flag & F_LJUST && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	return ((info->width > strlength) ? info->width : strlength);
}
