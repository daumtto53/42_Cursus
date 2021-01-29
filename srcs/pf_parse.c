/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:04:06 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 12:55:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_type(const char *s, t_parse_info *p_info)
{
	int		i;

	i = 0;
	p_info->type = s[i];
	return (i + 1);		//반환값이 (str로부터 i + 1만큼 떨어진 값을 반환)
}

int		parse_precision(const char *s, t_parse_info *p_info, va_list *ap)
{
	int		i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'i' || s[i] == 'd' || \
				s[i] == 'u' || s[i] == 'X' || s[i] == 'x' || s[i] == 'p' || \
					s[i] == '%')
		{
			p_info->prec = 0;
			p_info->flag |= F_ONLY_DOT;
		}
		else if (s[i] == '*')
		{
			p_info->prec = va_arg(*ap, int);
			i++;
		}
		else if (ft_isdigit(s[i]))
			p_info->prec = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
		p_info->flag |= F_PRECISION;
	}
	return (i);
}

int		parse_width(const char *s, t_parse_info *p_info, va_list *ap)
{
	int		i;

	i = 0;
	if (s[i] == '*')
	{
		p_info->width = va_arg(*ap, int);
		if (p_info->width < 0)
		{
			p_info->flag |= F_LEFT_JUSTIFY;
			p_info->width *= -1;
		}
		p_info->flag |= F_WIDTH;
		i++;
	}
	else if (ft_isdigit(s[i]))
	{
		p_info->flag |= F_WIDTH;
		p_info->width = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int		parse_flag(const char *s, t_parse_info *p_info)
{
	int		i;

	i = 0;
	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			p_info->flag |=  F_ZERO;
		else
			p_info->flag |= F_LEFT_JUSTIFY;
		i++;
	}
	return (i);
}

int		pf_parse(const char *s, t_parse_info *p_info, va_list *ap)
{
	int		i;

	i = 0;
	i += parse_flag(s + i, p_info);
	i += parse_width(s + i, p_info, ap);
	i += parse_precision(s + i, p_info, ap);
	i += parse_type(s + i, p_info);
	return (i);
}
