/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:01:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 23:12:34 by mchun            ###   ########.fr       */
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

static int		hex_zero(long long num, t_info *i)

{
	int		padd_len;

	padd_len = -1;
	if (i->width > ft_digitlen_ubase(num, 16))
		padd_len = (i->width - ft_digitlen_ubase(num, 16));
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (num == LLONG_MIN)
		ft_putstr_fd("8000000000000000", 1);
	else if (i->type == 'x')
		ft_putnbr_base_fd(num, 16, 1, BASE_DOWN);
	else
		ft_putnbr_base_fd(num, 16, 1, BASE_UP);
	return ((i->width > ft_digitlen_ubase(num, 16)) ? \
				i->width : ft_digitlen_ubase(num, 16));
}

static int		hex_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;
	int		ret_len;

	digit_len = ft_digitlen_ubase(num, 16);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > prec_len + digit_len) ? \
		i->width - (prec_len + digit_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	if (i->type == 'X')
		ft_putnbr_base_fd(num, 16, 1, BASE_UP);
	else
		ft_putnbr_base_fd(num, 16, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (i->width > i->prec + digit_len)
		ret_len = (i->width);
	else
		ret_len = prec_len + digit_len;
	return (ret_len);
}

static int		hex_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

void	printer_type_hex(t_info *info, va_list *ap, int *len)
{
	unsigned long long num;

	num = get_nbr_interface(info, ap);
	if (info->flag & F_ZERO)
		*len += (hex_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (hex_preczero(info));
	else
		*len += (hex_normal(num, info));
}
