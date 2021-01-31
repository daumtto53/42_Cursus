/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:04:06 by mchun             #+#    #+#             */
/*   Updated: 2021/01/31 13:06:14 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdio.h>
int		parse_type(const char *s, t_info *info)
{
	int		i;

	i = 0;
	info->type = s[i];
	return (i + 1);
}

int		parse_precision(const char *s, t_info *info, va_list *ap)
{
	int		i;

	i = 0;
	if (s[i] == '.')
	{
		info->flag |= F_PREC;
		i++;
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'i' || s[i] == 'd' || \
				s[i] == 'u' || s[i] == 'X' || s[i] == 'x' || s[i] == 'p' || \
					s[i] == '%')
		{
			info->prec = 0;
			info->flag |= F_ONLY_DOT;
		}
		else if (s[i] == '*')
		{
			info->prec = va_arg(*ap, int);
			if (info->prec < 0)
				info->flag &= (~F_PREC);
			i++;
		}
		else if (ft_isdigit(s[i]))
			info->prec = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int		parse_width(const char *s, t_info *info, va_list *ap)
{
	int		i;

	i = 0;
	if (s[i] == '*')
	{
		info->width = va_arg(*ap, int);
		if (info->width < 0)
		{
			info->flag |= F_LJUST;
			info->flag &= (~F_ZERO);
			info->width *= -1;
		}
		info->flag |= F_WIDTH;
		i++;
	}
	else if (ft_isdigit(s[i]))
	{
		info->flag |= F_WIDTH;
		info->width = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int		parse_flag(const char *s, t_info *info)
{
	int		i;

	i = 0;
	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			info->flag |= F_ZERO;
		else
			info->flag |= F_LJUST;
		i++;
	}
	return (i);
}

int		pf_parse(const char *s, t_info *info, va_list *ap)
{
	int		i;

	i = 0;
	i += parse_flag(s + i, info);
	i += parse_width(s + i, info, ap);
	i += parse_precision(s + i, info, ap);
	i += parse_type(s + i, info);
	return (i);
}
