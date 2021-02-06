/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:04:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 13:45:26 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int		atoi_interface(const char *s, t_info *info, va_list *ap)
{
	int		i;

	i = 0;
	if (s[i] == '.')
		i++;
	if (s[i] == '*' && s[i - 1] == '.')
	{
		info->prec = va_arg(*ap, int);
		i += (1 + 1);
	}
	else if (s[i] == '*' && s[i - 1] != '.')
	{
		info->width = va_arg(*ap, int);
		i += (1 + 1);
	}
	else if (s[i - 1] == '.')
		info->prec = ft_atoi(s + i);
	else
		info->width = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	return (i - 1);
}

static void		change_parsed_negative(t_info *info)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->flag |= F_LJUST;
	}
	if (info->prec < 0)
	{
		info->prec = 0;
		info->flag &= F_PREC;
	}
}

int		pf_parse_2(const char *s, t_info *info, va_list *ap)
{
	int		i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", s[i]) && (ft_strchr("0-.*", s[i]) || ft_isdigit(s[i])))
	{
		if (s[i] == '0')
			info->flag |= F_ZERO;
		else if (s[i] == '-')
			info->flag |= F_LJUST;
		else if (s[i] == '.')
		{
			info->flag |= F_PREC;
			i += atoi_interface(s + i, info, ap);
		}
		else if (s[i] == '*' || ft_isdigit(s[i]))
		{
			info->flag |= F_WIDTH;
			i += atoi_interface(s + i, info, ap);
		}
		i++;
	}
	change_parsed_negative(info);
	info->type = s[i];
	return (i + 1);
}
