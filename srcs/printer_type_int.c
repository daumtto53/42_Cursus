/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:53 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 23:34:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_nbr_interface(t_info *i, va_list *ap)
{
	long long num;

	if (i->len == FT_PF_HH)
		num = (char)va_arg(*ap, int);
	else if (i->len == FT_PF_H)
		num = (short)va_arg(*ap, int);
	else if (i->len == FT_PF_I)
		num = (int)va_arg(*ap, int);
	else if (i->len == FT_PF_L)
		num = (long)va_arg(*ap, long);
	else
		num = (long long)va_arg(*ap, long long);
	return (num);
}

int		int_zero(long long num, t_info *i)
{
	int		padd_len;
	int		sign;

	padd_len = -1;
	sign = (num < 0) ? -1 : 1;
	if (i->width > (sign == -1) + ft_digitlen_base(num, 10))
		padd_len = (i->width - ((sign == -1) - ft_digitlen_base(num, 10)));
	if (sign < 0)
		ft_putchar_fd('-', 1);
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (num == LLONG_MIN)
		ft_putstr_fd("9223372036854775808", 1);
	else
		ft_putnbr_base_fd(sign * num, 10, 1, BASE_DOWN);
	return ((i->width > (sign == -1) + ft_digitlen_base(num, 10)) ? \
				i->width : (sign == -1) + ft_digitlen_base(num, 10));
}

 int		int_normal(long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;
	int		sign;
	int		temp;

	digit_len = ft_digitlen_base(num, 10);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	temp = prec_len;
	padd_len = (i->width > (num < 0) + prec_len + digit_len) ? \
		(i->width - ((num < 0) + prec_len + digit_len)) : -1;
	sign = (num < 0) ? -1 : 1;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (sign == -1)
		ft_putchar_fd('-', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_base_fd(num * sign , 10, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	return ((i->width > (num < 0) + temp + digit_len) ? \
				i->width : ((num < 0) + temp + digit_len));
}

static int		int_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

void	printer_type_int(t_info *info, va_list *ap, int *len)
{
	long long num;

	num = get_nbr_interface(info, ap);
	if (info->flag & F_ZERO)
		*len += (int_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (int_preczero(info));
	else
		*len += (int_normal(num, info));
}
