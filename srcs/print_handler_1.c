/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 16:01:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_c(t_parse_info *p_info, va_list *ap, int *len)
{
	int				a;
	unsigned char	c;
	char	str[1];
	char	*product;

	a = va_arg(*ap, int);
	c = (unsigned char)a;
	if (p_info->width <= 1)
	{
		ft_putchar_fd(c, 1);
		*len += 1;
	}
	else
	{
		str[0] = c;
		if ((product = printer_width_helper(p_info, p_info->width - 1, str)) == NULL)
			return (-1);
		ft_putstr_fd(product, 1);
		*len += ft_strlen(product);
		free(product);
	}
	return (1);
}

int		printer_type_s(t_parse_info *p_info, va_list *ap, int *len)
{
	int		strlength;
	char	*strarg;
	char	*product;

	strarg = va_arg(*ap, char *);
	if (strarg == NULL)
		strarg = "(null)";
	if (p_info->flag & F_PRECISION && 0 <= p_info->prec && p_info->prec <= (int)ft_strlen(strarg))
		strlength = p_info->prec;
	else
		strlength = ft_strlen(strarg);
	if ((product = ft_substr(strarg, 0, strlength)) == NULL)
		return (-1);
	if (p_info->width > strlength)
		if ((product = printer_width_helper(p_info, \
				p_info->width - strlength, product)) == NULL)
			return (-1);
	ft_putstr_fd(product, 1);
	*len += ft_strlen(product);
	free(product);
	return (1);
}

int		printer_type_p(t_parse_info *p_info, va_list *ap, int *len)
{
	char	*product;
	char	*ptrarg;

	ptrarg = va_arg(*ap, char *);
	if (ptrarg == NULL)
		ptrarg = 0;
	if ((ptrarg = ft_numtox((long long)ptrarg)) == NULL)
		return (-1);
	if ((product = ft_strjoin("0x", ptrarg)) == NULL)
		return (-1);
	free(ptrarg);
	if (p_info->width > (int)ft_strlen(product))
	{
		if ((product = printer_width_helper(p_info, p_info->width - ft_strlen(product), product)) == NULL)
			return (-1);
	}
	ft_putstr_fd(product, 1);
	*len += ft_strlen(product);
	free(product);
	return (1);
}

int		printer_type_perc(t_parse_info *p_info, int *len)
{
	char	*product;

	if ((product = (char *)calloc(2, 1)) == NULL)
		return (-1);
	product[0] = '%';
	if (p_info->width > 1)
	{
		if ((product = printer_width_helper(p_info, p_info->width - 1, product)) == NULL)
			return (-1);
		if (p_info->flag & F_ZERO)
		{
			if (p_info->flag & F_LEFT_JUSTIFY)
				ft_strfill(product, 1, ft_strlen(product) - 1, '0');
			else
				ft_strfill(product, 0, ft_strlen(product) - 2, '0');
		}
	}
	ft_putstr_fd(product, 1);
	*len += ft_strlen(product);
	free(product);
	return (1);
}
