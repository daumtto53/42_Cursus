/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/28 17:49:25 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer_type_c(t_parse_info *p_info, va_list *ap)
{
	int				a;
	unsigned char	c;
	char			*s;
	char			*product[1];

	a = va_arg(*ap, int);
	c = (unsigned char)a;
	if (p_info->width <= 1)
		ft_putchar_fd(c, 1);
	else
	{
		product[0] = c;
		if ((printer_width_helper(p_info, p_info->width - 1, product)) == NULL)
			return (-1);
		ft_putstr_fd(product, 1);
		free(product);
	}
	return (1);
}

int		printer_type_s(t_parse_info *p_info, va_list *ap)
{
	int		strlength;
	char	*strarg;
	char	*product;

	strarg = va_arg(*ap, char *);
	if (strarg = NULL)
		strarg = "(null)";
	if (p_info->flag & F_PRECISION && 0 <= p_info->prec && p_info->prec <= ft_strlen(strarg))
		strlength = p_info->prec;
	else
		strlength = ft_strlen(strarg);
	if ((product = ft_substr(strarg, 0, strlength)) == NULL)
		return (-1);
	free(strarg);		//doublefree의 위험이 있음. va_end()의 역할에 대해 자세히 알아볼 것.
	if (p_info->width > strlength)
		if ((product = printer_width_helper(p_info, \
				p_info->width - strlength, product)) == NULL)
			return (-1);
	ft_putstr_fd(product, 1);
	free(product);
	return (1);
}

int		printer_type_p(t_parse_info *p_info, va_list *ap)
{
	char	*product;
	char	*ptrarg;
	char	tmp;

	ptrarg = va_arg(*ap, char *);
	if (ptrarg == NULL)
		ptrarg = 0;
	if ((ptrarg = ft_numtox((long long)ptrarg)) == NULL)
		return (-1);
	if ((product = ft_strjoin("0x", ptrarg)) == NULL)
		return (-1);
	free(ptrarg);
	if (p_info->width > ft_strlen(product))
	{
		if ((product = printer_width_helper(p_info, p_info->width - ft_strlen(product), product)) == NULL)
			return (-1);
	}
	ft_putstr_fd(product, 1);
	free(product);
	return (1);
}

int		printer_type_perc(t_parse_info *p_info, va_list *ap)
{
	char	*typearg;
	char	*product;

	typearg = "%";
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
	free(product);
	return (1);
}
