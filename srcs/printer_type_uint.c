/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:11 by mchun             #+#    #+#             */
/*   Updated: 2021/02/07 14:34:36 by mchun            ###   ########.fr       */
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

static int		uint_zero(unsigned long long num, t_info *i)
{
	int		padd_len;

	padd_len = -1;
	if (i->width > ft_digitlen_ubase(num, 10))
		padd_len = (i->width - ft_digitlen_ubase(num, 10));
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putunbr_base_fd(num, 10, 1, BASE_DOWN);
	return ((i->width > ft_digitlen_ubase(num, 10)) ? \
				i->width : ft_digitlen_ubase(num, 10));
}

static int		uint_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;

	digit_len = ft_digitlen_ubase(num, 10);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > prec_len + digit_len) ? \
		i->width - (prec_len + digit_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putunbr_base_fd(num, 10, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	return ((i->width > prec_len + digit_len) ? i->width : prec_len + digit_len);
}

static int		uint_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

void	printer_type_uint(t_info *info, va_list *ap, int *len)
{
	unsigned long long num;

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
		*len += (uint_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (uint_preczero(info));
	else
		*len += (uint_normal(num, info));
}
