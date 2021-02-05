/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:04:06 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 20:05:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

 int		is_valid_type(char c)
{
	return (ft_strchr("cspdixXu%%", c) != NULL);
}
 int		is_valid_flag(char c)
{
	return (ft_strchr("0-*.", c) != NULL);
}

int				ft_abstract_atoi(char **s, va_list *ap)
{
	char	*p;
	int			num;

	p = *s;
	if (*p == '.')
		p++;
	if (*p == '*')
	{
		p++;
		return (va_arg(*ap, int));
	}
	else
		num = ft_atoi(p);
	while (ft_isdigit(*p))
		p++;
	p--;
	*s = p;
	return (num);
}

int		pf_parse(char **s, t_info *info, va_list *ap)
{
	char *p;

	p = *s;
	while((is_valid_type(*p) != 0) && (is_valid_flag(*p) || ft_isdigit(*p)))
	{
		if (*p == '0')
			info->flag |= F_ZERO;
		else if (*p == '-')
			info->flag |= F_LJUST;
		else if (*p == '*' || ft_isdigit(*p))
		{
			info->flag |= F_WIDTH;
			info->width = ft_abstract_atoi(&p, ap);
		}
		else if (*p == '.')
		{
			info->flag |= F_PREC;
			info->prec = ft_abstract_atoi(&p, ap);
		}
		p++;
	}
	if (is_valid_type(*p))
		info->type = *p++;
	*s = p;
	return (FT_NORMAL);
}
