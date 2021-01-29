/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:50:01 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 13:43:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_info_renew(t_parse_info *p_info)
{
	p_info->flag = 0;
	p_info->prec = 0;
	p_info->type = 0;
	p_info->width = 0;
}

int		print_handler(t_parse_info *p_info, va_list *ap, int *len)
{
	char	t;
	int		err;

	t = p_info->type;
	if (t == 'c')
		err = printer_type_c(p_info, ap, len);
	else if (t == 's')
		err = printer_type_s(p_info, ap, len);
	else if (t == 'p')
		err = printer_type_p(p_info, ap, len);
	else if (t == 'x' || t == 'X')
		err = printer_type_xud(p_info, ap, len);
	else if (t == 'd' || t == 'i')
		err = printer_type_xud(p_info, ap, len);
	else if (t == 'u')
		err = printer_type_xud(p_info, ap, len);
	else if (t == '%')
		err = printer_type_perc(p_info, len);
	else
		return (-1);
	return (err);
}

int		handle_p_info(t_parse_info *p_info)
{
	char	t = p_info->type;

	if (p_info->type == 'i')
		p_info->type = 'd';
	if (!(t == 'p' || t == 's' || t == 'c' || t == 'd' || t == 'u' || \
			t == 'i' || t == 'x' || t == 'X'))
		return (-1);
	if (p_info->flag & F_ZERO && (t == 'p' || t == 's' || t == 'c'))
		return (-1);
	if (p_info->flag & F_ZERO && p_info->flag & F_LEFT_JUSTIFY && t != '%')
		return (-1);
	if (p_info->flag & F_PRECISION && (t == 'c' || t == 'p') && \
			!(p_info->flag & F_ONLY_DOT))
		return (-1);
	if ((t == 'u' || t == 'd' || t == 'u' || t == 'x' || t == 'X' || \
			t == 'i') && F_ZERO && F_PRECISION)
		p_info->flag &= (~F_ZERO);
	if (p_info->prec < 0 && p_info->flag & F_ZERO)
		p_info->flag &= (~F_PRECISION);
	if (p_info->prec >= 0 && p_info->flag & F_ZERO)
		p_info->flag &= (~F_ZERO);
	return (1);
	//2147483647, 46은 안뽑아주는걸 처리해야한다.
}

int		reach_delim(const char *str, int i)
{
	while (str[i] != '%' && str[i] != '\0')
		i++;
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list 		ap;
	int				i;
	int				j;
	t_parse_info	p_info;
	int				len;

	len  = 0;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	i = 0;
	while (str[i] != '\0')
	{
		parse_info_renew(&p_info);
		j = reach_delim(str, i);
		write(1, str + i, j - i);
		len += (j - i);
		if (str[j] == '\0')
			return (len);
		j += pf_parse(str + j + 1, &p_info, &ap);
		if (handle_p_info(&p_info) < 0 || print_handler(&p_info, &ap, &len) < 0)
			return (-1);
		i = j;
	}
	return (len);
}
