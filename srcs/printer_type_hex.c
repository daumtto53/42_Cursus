/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:01:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 20:08:20 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*hex_interface(unsigned int num, t_info *info)
{
	char	*str;
	int		i;

	str = ft_utox(num);
	if (str == NULL)
		return (NULL);
	if (info->type == 'X')
	{
		i = ft_strlen(str);
		while (--i >= 0)
			str[i] = ft_toupper(str[i]);
	}
	return (str);
}

int		printer_type_hex(unsigned int num, t_info *info, int *ft_errno)
{
	int		len;

	if (info->flag & F_ZERO)
		len = (hex_zero(num, info));
	else if (info->flag & F_PREC && num == 0 && info->prec == 0)
		len = (hex_preczero(info));
	else
		len = (hex_normal(num, info));
	if (len == FT_ERR)
		*ft_errno = FT_ERR;
	return (len);
}

int		hex_zero(unsigned int num, t_info *i)
{
	int		padd_len;
	char	*str;
	int		len;

	if ((str = hex_interface(num, i)) == NULL)
		return (FT_ERR);
	padd_len = (i->width > (int)ft_strlen(str))? \
			i->width - ft_strlen(str) : 0;
	while (!(i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while ((i->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd('0', 1);
	len = (i->width > (int)ft_strlen(str) ) ? \
				i->width : (int)ft_strlen(str);
	free(str);
	return (len);
}


int		hex_normal(unsigned int num, t_info *i)
{
	int		padd_len;
	int		prec_len;
	char 	*str;
	int		ret_len;

	if ((str = ft_utox(num)) == NULL)
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

int		hex_preczero(t_info *i)
{
	int		padd_len;

	padd_len = i->width;
	while (padd_len--)
		ft_putchar_fd(' ', 1);
	return (i->width);
}

