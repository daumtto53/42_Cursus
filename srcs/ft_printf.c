/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:50:01 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 14:15:46 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static void		parse_info_renew(t_info *info)
{
	info->flag = 0;
	info->prec = 0;
	info->type = 0;
	info->width = 0;
}

static int		print_handler(t_info *info, va_list *ap, int *len)
{
	char	t;
	int		err;

	t = info->type;
	if (t == 'c')
		err = printer_type_c(info, ap, len);
	else if (t == 's')
		err = printer_type_s(info, ap, len);
	else if (t == 'p')
		err = printer_type_p(info, ap, len);
	else if (t == 'x' || t == 'X')
		err = printer_type_xud(info, ap, len);
	else if (t == 'd' || t == 'i')
		err = printer_type_xud(info, ap, len);
	else if (t == 'u')
		err = printer_type_xud(info, ap, len);
	else if (t == '%')
		err = printer_type_perc(info, len);
	else
		return (-1);
	return (err);
}

static int		handle_p_info(t_info *info)
{
	char	t;

	t = info->type;
	if (!ft_strchr("cspdiuxX%", t))
		return (-1);
	if (info->flag & F_ZERO && ft_strchr("csp", t))
		return (-1);
	if (info->flag & F_ZERO && info->flag & F_LJUST)
		info->flag &= (~F_ZERO);
	if (ft_strchr("diuxX", t) && (info->flag & (F_ZERO | F_PREC)))
		info->flag &= (~F_ZERO);
	if (info->prec < 0 && info->flag & F_ZERO)
		info->flag &= (~F_PREC);
	if (info->width >= 2147483646 || info->prec >= 2147483646)
		return (-1);
	return (1);
}

static int		print_until_delim(const char *str, int i, int *len)
{
	int		j;

	j = i;
	while (str[j] != '%' && str[j] != '\0')
		j++;
	if (write(1, str + i, j - i) < 0)
		return (-1);
	*len += (j - i);
	return (j);
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	t_info			info;
	int				i;
	int				j;
	int				len;

	if (str == NULL)
		return (-1);
	va_start(ap, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		parse_info_renew(&info);
		if ((j = print_until_delim(str, i, &len)) < 0)
			return (-1);
		if (str[j] == '\0')
			return (len);
		j += (pf_parse_2(str + j + 1, &info, &ap) + 1);
		if (handle_p_info(&info) < 0 || print_handler(&info, &ap, &len) < 0)
			return (-1);
		i = j;
	}
	va_end(ap);
	return (len);
}
