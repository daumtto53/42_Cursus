/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/31 02:01:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdio.h>
char	*xud_substr_maker(t_info *info, long num)
{
	char	*str;
	int		i;

	str = NULL;
	if (info->prec == 0 && num == 0 && info->flag & F_PREC)
		return ("");
	if (info->type == 'd' || info->type == 'i')
	{
		num = (num < 0) ? (num * -1) : (num);
		str = ft_ltoa((long)num);
	}
	else if (info->type == 'x' || info->type == 'X')
		str = ft_utox(num);
	else if (info->type == 'u')
		str = ft_utoa(num);
	if (str == NULL)
		return (NULL);
	if (info->type == 'X')
	{
		i = ft_strlen(str);
		while (--i >= 0)
			str[i] = ft_toupper(str[i]);
	}
	return (str);
}

int		printer_type_xud(t_info *i, va_list *ap, int *len)
{
	long		num;
	int			blank_num;
	char		*str;
	int			sign;

	sign = 0;
	num = va_arg(*ap, int);
	if ((str = xud_substr_maker(i, num)) == NULL)
		return (-1);
	if ((i->type == 'd' || i->type == 'i') && num < 0)
		sign = 1;
	i->prec = (i->prec > (int)ft_strlen(str)) ? i->prec - (int)ft_strlen(str) : 0;
	blank_num = i->width - (sign + (int)ft_strlen(str) + i->prec);
	printf("%d\n", i->flag & F_ZERO);
	if (i->flag & F_ZERO && i->width > (sign + (int)ft_strlen(str) + i->prec) && num < 0)
	{
		ft_putchar_fd('-', 1);
		sign = 0;
	}
	if (i->width > (sign + (int)ft_strlen(str) + i->prec))
		*len += i->width;
	else
		*len += (sign + (int)ft_strlen(str) + i->prec);
	printer_type_xud2(i, str, sign, blank_num);
	return (1);
}

void	printer_type_xud2(t_info *info, char *str, int sign, int blank_num)
{
	char	fill;

	fill = ' ';
	if (info->flag & F_ZERO)
		fill = '0';
	if (info->flag & F_LJUST)
	{
		if (sign)
			ft_putchar_fd('-', 1);
		while (info->prec-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
		while (blank_num-- > 0)
			ft_putchar_fd(fill, 1);
	}
	else
	{
		while (blank_num-- > 0)
			ft_putchar_fd(fill, 1);
		if (sign && !(info->flag & F_ZERO))
			ft_putchar_fd('-', 1);
		while (info->prec-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
	}
}
