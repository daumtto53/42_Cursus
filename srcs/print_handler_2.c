/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 16:00:26 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*xud_substr_maker(t_info *info, int num)
{
	char	*str;
	int		i;

	if (info->type == 'd' || info->type == 'i')
	{
		num = (num < 0) ? num * -1 : num;
		str = ft_itoa(num);
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
			ft_toupper(str + i);
	}
	return (str);
}

int		printer_type_xud(t_info *i, va_list *ap, int *len)
{
	int		num;
	int		blank_num;
	char	*str;
	int		sign;

	sign = 0;
	num = va_arg(*ap, int);
	if ((str = xud_substr_maker(i, num)) == NULL)
		return (-1);
	if ((i->type == 'd' || i->type == 'i') && num < 0)
		sign = 1;
	i->prec = (i->prec > ft_strlen(str)) ? i->prec - ft_strlen(str) : 0;
	blank_num = i->width - (sign + ft_strlen(str) + i->prec);
	if (i->flag & F_ZERO && i->width > (sign + ft_strlen(str) + i->prec))
	{
		ft_putchar_fd('-', 1);
		sign = 0;
	}
	printer_type_xud2(i, str, sign, blank_num);
	if (i->width > (sign + ft_strlen(str) + i->prec))
		*len += i->width;
	else
		*len += (sign + ft_strlen(str) + i->prec);
	free(str);
	return (1);
}

void	printer_type_xud2(t_info *info, char *str, int sign, int blank_num)
{
	char	fill;

	fill = '-';
	if (info->flag == F_ZERO)
		fill = '0';
	if (info->flag & F_LJUST)
	{
		if (sign)
			ft_putchar_fd('-', 1);
		while (info->prec--)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
		while (blank_num--)
			ft_putchar_fd(fill, 1);
	}
	else
	{
		while (blank_num--)
			ft_putchar_fd(fill, 1);
		if (sign && !(info->flag & F_ZERO))
			ft_putchar_fd('-', 1);
		while (info->prec--)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
	}
}
