/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:53:11 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 21:08:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_uint(unsigned int num, t_info *info, int *ft_errno)
{
	int		len;

	if (info->flag & F_ZERO)
		len = (uint_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		len = (uint_preczero(info));
	else
		len = (uint_normal(num, info));
	if (len == FT_ERR)
		*ft_errno = FT_ERR;
	return (len);
}

int		uint_zero(unsigned int num, t_info *i)
{
	int		padd_len;
	char	*str;
	int		len;

	if ((str = ft_utoa(num)) == NULL)
		return (FT_ERR);
	padd_len = (i->width > (int)ft_strlen(str))? \
			i->width - ft_strlen(str) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	len = (i->width > (int)ft_strlen(str)) ? \
				i->width : (int)ft_strlen(str);
	free(str);
	return (len);
}


int		uint_normal(unsigned int num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	char 	*str;
	int		ret_len;

	if ((str = ft_utoa(num)) == NULL)
		return (FT_ERR);
	prec_len = ((int)ft_strlen(str) < i->prec) ? \
		 i->prec - ft_strlen(str) : 0;
	padd_len = (i->width > (int)ft_strlen(str) + prec_len) ? \
			i->width - ft_strlen(str) - prec_len : 0;
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
		ret_len = ((int)ft_strlen(str) + prec_len);
	free(str);
	return (ret_len);
}

int		uint_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

