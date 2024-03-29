/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:01:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 14:11:57 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void						print_0x(t_info *i, unsigned long long num)
{
	if (i->flag & F_POUND && i->type == 'x' && num != 0)
		ft_putstr_fd("0x", 1);
	else if (i->flag & F_POUND && i->type == 'X' && num != 0)
		ft_putstr_fd("0X", 1);
}

static int					hex_zero(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		ox_len;

	padd_len = -1;
	ox_len = (i->flag & F_POUND && num != 0) ? 2 : 0;
	if (i->width > ft_digitlen_ubase(num, 16) + ox_len)
		padd_len = (i->width - (ft_digitlen_ubase(num, 16) + ox_len));
	if (i->flag & F_POUND && i->type == 'x' && num != 0)
		ft_putstr_fd("0x", 1);
	else if (i->flag & F_POUND && i->type == 'X' && num != 0)
		ft_putstr_fd("0X", 1);
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (i->type == 'x')
		ft_putunbr_base_fd(num, 16, 1, BASE_DOWN);
	else
		ft_putunbr_base_fd(num, 16, 1, BASE_UP);
	return ((i->width > ox_len + ft_digitlen_ubase(num, 16)) ? \
				i->width : ox_len + ft_digitlen_ubase(num, 16));
}

static int					hex_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;
	int		ox_len;

	digit_len = ft_digitlen_ubase(num, 16);
	ox_len = (i->flag & F_POUND && num != 0) ? 2 : 0;
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > prec_len + digit_len + ox_len) ? \
		i->width - (prec_len + digit_len + ox_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	print_0x(i, num);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	if (i->type == 'X')
		ft_putunbr_base_fd(num, 16, 1, BASE_UP);
	else
		ft_putunbr_base_fd(num, 16, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	return ((i->width > prec_len + digit_len + ox_len) ? \
			i->width : prec_len + digit_len + ox_len);
}

static int					hex_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

void						printer_type_hex(t_info *i, \
		va_list *ap, long long *len)
{
	unsigned long long num;

	if (i->len == FT_PF_HH)
		num = ((unsigned char)va_arg(*ap, int)) & UCHAR_MAX;
	else if (i->len == FT_PF_H)
		num = ((unsigned short)va_arg(*ap, int)) & USHRT_MAX;
	else if (i->len == FT_PF_I)
		num = ((unsigned int)va_arg(*ap, int)) & UINT_MAX;
	else if (i->len == FT_PF_L)
		num = ((unsigned long)va_arg(*ap, long)) & ULONG_MAX;
	else
		num = ((unsigned long long)va_arg(*ap, long long));
	if (i->flag & F_ZERO)
		*len += (hex_zero(num, i));
	else if (i->flag & F_PREC && num == 0 && i->prec == 0)
		*len += (hex_preczero(i));
	else
		*len += (hex_normal(num, i));
}
