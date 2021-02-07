/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_csp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/02/07 13:02:50 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printer_type_c(t_info *info, va_list *ap, int *len)
{
	unsigned char	c;
	int				blank_num;

	blank_num = info->width - 1;
	c = (unsigned char)va_arg(*ap, int);
	while (!(info->flag & F_LJUST) && blank_num-- > 0)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	while (info->flag & F_LJUST && blank_num-- > 0)
		ft_putchar_fd(' ', 1);
	if (info->width > 1)
		*len += info->width;
	else
		*len += 1;
}

void	printer_type_s(t_info *i, va_list *ap, int *len)
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
	while (!(i->flag & F_LJUST) && blank_num-- > 0)
		ft_putchar_fd(' ', 1);
	write(1, s, strlength);
	while (i->flag & F_LJUST && blank_num-- > 0)
		ft_putchar_fd(' ', 1);
	*len += ((i->width > strlength) ? i->width : strlength);
}

// void	printer_type_p(t_info *i, va_list *ap, int *len)
// {
// 	unsigned long long	num;
// 	int					padd_len;

// 	num = (unsigned long long)va_arg(*ap, char *);
// 	if (num == 0 && (i->flag & F_PREC))
// 	{
// 		write(1, "0x", 2);
// 		while (i->width-- > 0)
// 			ft_putchar_fd(' ', 1);
// 		return ;
// 	}
// 	padd_len = i->width - (ft_digitlen_base(num, 16) + 2);
// 	while (!(i->flag & F_LJUST) && padd_len-- > 0)
// 		ft_putchar_fd(' ', 1);
// 	write(1, "0x", 2);
// 	ft_putunbr_base_fd(num, 16, 1, BASE_DOWN);
// 	while (i->flag & F_LJUST && padd_len-- > 0)
// 		ft_putchar_fd(' ', 1);
// 	*len += ((i->width > (int)ft_digitlen_base(num, 16) + 2) \
// 				? i->width : (int)ft_digitlen_base(num, 16) + 2);
// }

static char	*printer_type_p_helper(t_info *i, char *p)
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

void	printer_type_perc(t_info *info, int *len)
{
	char			fill;
	int				blank_num;

	fill = (info->flag & F_ZERO) ? '0' : ' ';
	blank_num = info->width - 1;
	while (!(info->flag & F_LJUST) && blank_num-- > 0)
		ft_putchar_fd(fill, 1);
	ft_putchar_fd('%', 1);
	while (info->flag & F_LJUST && blank_num-- > 0)
		ft_putchar_fd(fill, 1);
	if (info->width > 1)
		*len += info->width;
	else
		*len += 1;
}
