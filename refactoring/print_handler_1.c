/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 00:28:42 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/ft_printf.h"
#include "ft_printf.h"

int		printer_type_c_2(t_info *info, va_list *ap, int *len)
{
	unsigned char	c;
	int				blank_num;

	blank_num = info->width;
	c = (unsigned char)va_arg(*ap, int);
	if (info->flag & F_LJUST)
	{
		ft_putchar_fd(c, 1);
		while (--blank_num)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--blank_num)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	if (info->width > 1)
		*len += info->width;
	else
		*len += 1;
	return (1);
}

int		printer_type_s_2(t_info *info, va_list *ap, int *len)
{
	int		strlength;
	int		blank_num;
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	strlength = ft_strlen(str);
	if (0 <= info->prec && info->prec <= ft_strlen(str) && info->flag & F_PREC)
		strlength = info->prec;
	blank_num = info->width - strlength;
	if (info->flag & F_LJUST)
	{
		write(1, str, strlength);
		while (blank_num--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (blank_num--)
			ft_putchar_fd(' ', 1);
		write(1, str, strlength);
	}
	*len += ((info->width > strlength) ? info->width : strlength);
	return (1);
}

int		printer_type_p_2(t_info *info, va_list *ap, int *len)
{
	char	*p;
	int		blank_num;

	p = va_arg(*ap, char *);
	p = (p == NULL) ? 0 : p;
	if ((p = ft_numtox((long long)p)) == NULL)
		return (-1);
	blank_num = info->width - (ft_strlen(p) + 2);
	if (info->flag & F_LJUST)
	{
		write(1, "0x", 2);
		write(1, p, ft_strlen(p));
		while (blank_num--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (blank_num--)
			ft_putchar_fd(' ', 1);
		write(1, "0x", 2);
		write(1, p, ft_strlen(p));
	}
	*len += ((info->width > ft_strlen(p) + 2) ? info->width : ft_strlen(p) + 2);
	return (1);
}

int		printer_type_perc(t_info *info, int *len)
{
	char	product;
	char	fill;

	fill = ((info->flag & F_ZERO) ? '0' : ' ');
	product = '%';


}
