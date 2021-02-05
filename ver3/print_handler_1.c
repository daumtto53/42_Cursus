/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/02/01 18:01:48 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_c(t_info *info, va_list *ap, int *len)
{
	unsigned char	c;
	int				blank_num;

	blank_num = info->width;
	c = (unsigned char)va_arg(*ap, int);
	if (info->flag & F_LJUST)
	{
		ft_putchar_fd(c, 1);
		while (--blank_num > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--blank_num > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	if (info->width > 1)
		*len += info->width;
	else
		*len += 1;
	return (1);
}

int		printer_type_s(t_info *i, va_list *ap, int *len)
{
	int		strlength;
	int		blank_num;
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	strlength = ft_strlen(s);
	if (0 <= i->prec && i->prec <= (int)ft_strlen(s) && i->flag & F_PREC)
		strlength = i->prec;
	blank_num = i->width - strlength;
	if (i->flag & F_LJUST)
	{
		write(1, s, strlength);
		while (blank_num-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (blank_num-- > 0)
			ft_putchar_fd(' ', 1);
		write(1, s, strlength);
	}
	*len += ((i->width > strlength) ? i->width : strlength);
	return (1);
}

char	*printer_type_p_helper(t_info *i, char *p)
{
	if (p == NULL && !(i->flag & F_PREC))
		p = ft_numtox((long long)0);
	else if (p == NULL && i->flag & F_PREC)
		p = ft_strjoin("", "");
	else
		p = ft_numtox((long long)p);
	return (p);
}

int		printer_type_p(t_info *i, va_list *ap, int *len)
{
	char	*p;
	int		blank_num;

	p = va_arg(*ap, char *);
	if ((p = printer_type_p_helper(i, p)) == NULL)
		return (-1);
	blank_num = i->width - (ft_strlen(p) + 2);
	if (i->flag & F_LJUST)
	{
		write(1, "0x", 2);
		write(1, p, ft_strlen(p));
		while (blank_num-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (blank_num-- > 0)
			ft_putchar_fd(' ', 1);
		write(1, "0x", 2);
		write(1, p, ft_strlen(p));
	}
	*len += ((i->width > (int)ft_strlen(p) + 2) \
				? i->width : (int)ft_strlen(p) + 2);
	free(p);
	return (1);
}

int		printer_type_perc(t_info *info, int *len)
{
	int		blank_num;
	char	fill;

	fill = ((info->flag & F_ZERO) ? '0' : ' ');
	blank_num = info->width;
	if (info->flag & F_LJUST)
	{
		ft_putchar_fd('%', 1);
		while (--blank_num > 0)
			ft_putchar_fd(fill, 1);
	}
	else
	{
		while (--blank_num > 0)
			ft_putchar_fd(fill, 1);
		ft_putchar_fd('%', 1);
	}
	if (info->width > 1)
		*len += info->width;
	else
		*len += 1;
	return (1);
}
