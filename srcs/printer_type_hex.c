/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:01:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/07 11:46:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	num_conversion(unsigned long long n, t_info *i)
{
	printf("sssssss%llu\n", n);
	if (i->len == FT_PF_HH)
		n &= UCHAR_MAX;
	else if (i->len == FT_PF_H)
		n &= USHRT_MAX;
	else if (i->len == FT_PF_I)
		n = (UINT_MAX) & (unsigned int)n;
	else if (i->len == FT_PF_L)
		n &= ULONG_MAX;
	else
		n &= n * 1;
	return (n);
}

static int		hex_zero(unsigned long long num, t_info *i)
{
	int		padd_len;

	padd_len = -1;
	if (i->width > ft_digitlen_ubase(num, 16))
		padd_len = (i->width - ft_digitlen_ubase(num, 16));
	while (padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (i->type == 'x')
		ft_putunbr_base_fd(num, 16, 1, BASE_DOWN);
	else
		ft_putunbr_base_fd(num, 16, 1, BASE_UP);
	return ((i->width > ft_digitlen_ubase(num, 16)) ? \
				i->width : ft_digitlen_ubase(num, 16));
}

static int		hex_normal(unsigned long long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	int		digit_len;

	digit_len = ft_digitlen_ubase(num, 16);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	padd_len = (i->width > prec_len + digit_len) ? \
		i->width - (prec_len + digit_len) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	if (i->type == 'X')
		ft_putunbr_base_fd(num, 16, 1, BASE_UP);
	else
		ft_putunbr_base_fd(num, 16, 1, BASE_DOWN);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	prec_len = (i->prec > digit_len) ? i->prec - digit_len : 0;
	return ((i->width > prec_len + digit_len) ? i->width : prec_len + digit_len);
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
	ft_putnbr_base_fd(num, 16, 1, BASE_UP);
	if (info->flag & F_ZERO)
		*len += (hex_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		*len += (hex_preczero(info));
	else
		*len += (hex_normal(num, info));
}
