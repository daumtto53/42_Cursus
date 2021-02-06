/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:11 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 23:06:48 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_nbr_interface(t_info *i, va_list *ap)
{
	if (i->len == FT_PF_HH)
		return ((char)va_arg(*ap, int));
	else if (i->len == FT_PF_H)
		return ((short)va_arg(*ap, int));
	else if (i->len == FT_PF_I)
		return ((short)va_arg(*ap, int));
	else if (i->len == FT_PF_L)
		return ((long)va_arg(*ap, long));
	else
		return ((long long)va_arg(*ap, long long));
}

static int		uint_zero(unsigned long long num, t_info *i)
{
	int		padd_len;

	padd_len = -1;
	if (i->width > ft_digitlen_ubase(num, 10))
		padd_len = (i->width - ft_digitlen_ubase(num, 10));
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_base_fd(num, 10, 1, BASE_DOWN);
	return ((i->width > ft_digitlen_ubase(num, 10)) ? \
				i->width : ft_digitlen_ubase(num, 10));
}

static int		uint_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;
	int		ret_len;

	digit_len = ft_digitlen_ubase(num, 10);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > prec_len + digit_len) ? \
		i->width - (prec_len + digit_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_base_fd(num, 10, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (i->width > i->prec + digit_len)
		ret_len = (i->width);
	else
		ret_len = i->prec + digit_len;
	return (ret_len);
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

	num = get_nbr_interface(info, ap);
	if (info->flag & F_ZERO)
		*len += (uint_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (uint_preczero(info));
	else
		*len += (uint_normal(num, info));
}
