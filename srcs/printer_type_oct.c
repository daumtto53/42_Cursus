/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:54:23 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 14:02:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	num_conversion(unsigned long long n, t_info *i)
{
	if (i->len == FT_PF_HH)
		n &= UCHAR_MAX;
	else if (i->len == FT_PF_H)
		n &= USHRT_MAX;
	else if (i->len == FT_PF_I)
		n &= UINT_MAX;
	else if (i->len == FT_PF_L)
		n &= ULONG_MAX;
	else
		n &= n * 1;
	return (n);
}

static int					oct_zero(unsigned long long num, t_info *i)
{
	int		pound_flag;
	int		padd_len;

	padd_len = -1;
	if (i->width > ft_digitlen_ubase(num, 8))
		padd_len = (i->width - ft_digitlen_ubase(num, 8));
	pound_flag = (num != 0 && i->flag & F_POUND && padd_len <= 0);
	if (pound_flag)
		ft_putchar_fd('0', 1);
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putunbr_base_fd(num, 8, 1, BASE_DOWN);
	return ((i->width > ft_digitlen_ubase(num, 8) + pound_flag) ? \
				i->width : ft_digitlen_ubase(num, 8) + pound_flag);
}

static int					oct_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;

	digit_len = ft_digitlen_ubase(num, 8);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	prec_len = (num != 0 && i->flag & F_POUND && prec_len <= 0) ? \
					prec_len + 1 : prec_len;
	padd_len = (i->width > prec_len + digit_len) ? \
		i->width - (prec_len + digit_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putunbr_base_fd(num, 8, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	prec_len = (num != 0 && i->flag & F_POUND) ? prec_len + 1 : prec_len;
	return ((i->width > prec_len + digit_len) ? \
				i->width : prec_len + digit_len);
}

static int					oct_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

void						printer_type_oct(t_info *info, \
	va_list *ap, long long *len)
{
	unsigned long long	num;

	if (info->len == FT_PF_HH)
		num = ((unsigned char)va_arg(*ap, int));
	else if (info->len == FT_PF_H)
		num = ((unsigned short)va_arg(*ap, int));
	else if (info->len == FT_PF_I)
		num = ((unsigned int)va_arg(*ap, int));
	else if (info->len == FT_PF_L)
		num = ((unsigned long)va_arg(*ap, long));
	else
		num = ((unsigned long long)va_arg(*ap, long long));
	num = num_conversion(num, info);
	if (info->flag & F_ZERO)
		*len += (oct_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (oct_preczero(info));
	else
		*len += (oct_normal(num, info));
}
