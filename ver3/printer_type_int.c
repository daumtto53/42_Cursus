/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:53 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 20:08:50 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_int(int num, t_info *info, int *ft_errno)
{
	int		len;

	if (info->flag & F_ZERO)
		len = (int_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		len = (int_preczero(info));
	else
		len = (int_normal(num, info));
	if (len == FT_ERR)
		*ft_errno = FT_ERR;
	return (len);
}

int		int_zero(long num, t_info *i)
{
	int		padd_len;
	char	*str;
	int		sign;
	int		len;

	sign = (num < 0) ? -1 : 1;
	if ((str = ft_ltoa(num * sign)) == NULL)
		return (FT_ERR);
	padd_len = (i->width > (num < 0) + (int)ft_strlen(str))? \
			i->width - ft_strlen(str) - (num < 0) : 0;
	if (sign < 0 && i->flag & F_LJUST)
		ft_putchar_fd('-', 1);
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	if (sign < 0 && !(i->flag & F_LJUST))
		ft_putchar_fd('-', 1);
	ft_putstr_fd(str, 1);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	len = (i->width > (int)ft_strlen(str) + (num < 0)) ? \
				i->width : (int)ft_strlen(str) + (num < 0);
	free(str);
	return (len);
}


 int		int_normal(long num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	char 	*str;
	int		ret_len;

	if ((str = ft_ltoa(num)) == NULL)
		return (FT_ERR);
	prec_len = ((int)ft_strlen(str) - (num < 0) < i->prec) ? \
		 i->prec - ft_strlen(str) + (num < 0) : 0;
	padd_len = (i->width > (num < 0) + (int)ft_strlen(str) + prec_len) ? \
			i->width - ft_strlen(str) - (num < 0) - prec_len : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(' ', 1);
	if (i->width > (int)ft_strlen(str) + prec_len)
		ret_len = (i->width);
	else
		ret_len = (ft_strlen(str) + prec_len);
	free(str);
	return (ret_len);
}

int		int_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

