/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:50:01 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 22:04:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>
#define DEBUG

void	parse_info_renew(t_parse_info *p_info)
{
	p_info->flag = 0;
	p_info->prec = 0;
	p_info->type = 0;
	p_info->width = 0;
}

int		print_handler(t_parse_info *p_info, va_list *ap)
{
	char	t;

	t = p_info->type;
	if (t == 'c')
		printer_type_c(ap, p_info);
	else if (t == 's')
		printer_type_s(ap, p_info);
	else if (t == 'p')
		printer_type_p(ap, p_info);
	else if (t == 'x' || t == 'X')
		printer_type_x(ap, p_info);
	else if (t == 'd' || t == 'i')
		printer_type_d(ap, p_info);
	else if (t == 'u')
		printer_type_u(ap, p_info);
	else if (t == '%')
		printer_type_percent(ap, p_info);
	else
		return (-1);
}

int		handle_parse_info(t_parse_info *p_info)
{
	char	t = p_info->type;

	if (!(t == 'p' || t == 's' || t == 'c' || t == 'd' || t == 'u' || \
			t == 'i' || t == 'x' || t == 'X'))
		return (-1);
	if (p_info->flag & F_ZERO && (t == 'p' || t == 's' || t == 'c'))
		return (-1);
	if (p_info->flag & F_ZERO && p_info->flag & F_LEFT_JUSTIFY && t != '%')
		return (-1);
	if (p_info->flag & F_PRECISION && (t == 'c' || t == 'p'))
		return (-1);
	if ((t == 'u' || t == 'd' || t == 'u' || t == 'x' || t == 'X' || \
			t == 'i') && F_ZERO && F_PRECISION)
		p_info->flag &= (~F_ZERO);
	if (p_info->prec < 0 && p_info->flag & F_ZERO)
		p_info->flag &= (~F_PRECISION);
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

	if (str == NULL)
		return (-1);
	va_start(ap, str);
	i = 0;
	while (str[i] != '\0')
	{
		parse_info_renew(&p_info);
		j = reach_delim(str, i);
		write(1, str + i, j - i);
		if (str[j] == '\0')
			return (ft_strlen(str));
		// j가 가리키는 곳은 parsing이 끝난 지점의 뒤, 즉 , '%'일것.
		// '%'의 뒤에는 Warning이 오지 않을 type의 값들만 들어온다고 가정한다.
		j += pf_parse(str + j + 1, &p_info, &ap);
		if (handle_parse_info(&p_info) < 0)
			return (-1);
		if (print_handler(&p_info, &ap) < 0)
			return (-1);
		i = j;
	}
	return (ft_strlen(str));
}
