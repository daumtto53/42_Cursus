/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:53 by mchun             #+#    #+#             */
/*   Updated: 2021/02/10 11:18:38 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	put_sign(int sign, t_info *i)
{
	char	c;

	if (sign == -1)
		c = '-';
	else if (sign != -1 && i->flag & F_SPACE)
		c = ' ';
	else if (sign != -1 && i->flag & F_PLUS)
		c = '+';
	else
	{
		c = '+';
		return ;
	}
	ft_putchar_fd(c, 1);
}

int			int_zero(long long num, t_info *i)
{
	int		padd_len;
	int		sign;

	padd_len = -1;
	sign = (num < 0) ? -1 : 1;
	if (i->width > (pf_is_sign(num, i) + ft_digitlen_base(num, 10)))
		padd_len = (i->width - \
			(pf_is_sign(num, i) + ft_digitlen_base(num, 10)));
	if (pf_is_sign(num, i))
		put_sign(sign, i);
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (num == LLONG_MIN)
		ft_putstr_fd("9223372036854775808", 1);
	else
		ft_putnbr_base_fd(sign * num, 10, 1, BASE_DOWN);
	return ((i->width > pf_is_sign(num, i) + ft_digitlen_base(num, 10)) ? \
				i->width : pf_is_sign(num, i) + ft_digitlen_base(num, 10));
}

int			int_normal(long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;
	int		sign;

	digit_len = ft_digitlen_base(num, 10);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > pf_is_sign(num, i) + prec_len + digit_len) ? \
		(i->width - (pf_is_sign(num, i) + prec_len + digit_len)) : -1;
	sign = (num < 0) ? -1 : 1;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (pf_is_sign(num, i))
		put_sign(sign, i);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_base_fd(num * sign, 10, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	return ((i->width > pf_is_sign(num, i) + prec_len + digit_len) ? \
				i->width : (pf_is_sign(num, i) + prec_len + digit_len));
}

static int	int_preczero(t_info *i)
{
	int		padd_len;
	int		positive;

	positive = 1;
	padd_len = i->width - (pf_is_sign(positive, i));
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (pf_is_sign(positive, i))
		put_sign(positive, i);
	while (i->flag & F_LJUST && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (pf_is_sign(positive, i) && i->width == 0)
		return (1);
	else
		return (i->width);
}

void		printer_type_int(t_info *info, va_list *ap, long long *len)
{
	long long	num;

	if (info->len == FT_PF_HH)
		num = (char)va_arg(*ap, int) & (char)-1;
	else if (info->len == FT_PF_H)
		num = (short)va_arg(*ap, int) & (short)-1;
	else if (info->len == FT_PF_I)
		num = (int)va_arg(*ap, int) & (int)-1;
	else if (info->len == FT_PF_L)
		num = (long)va_arg(*ap, long) & (long)-1L;
	else
		num = (long long)va_arg(*ap, long long);
	if (info->flag & F_ZERO)
		*len += (int_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (int_preczero(info));
	else
		*len += (int_normal(num, info));
}
