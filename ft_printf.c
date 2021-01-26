/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:50:01 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 17:56:15 by mchun            ###   ########.fr       */
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

int		pf_parse(const char *s, t_parse_info *p_info, va_list *ap)
{
	int		i;

	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			p_info->flag = (p_info->flag | F_ZERO);
		else
			p_info->flag = (p_info->flag | F_LEFT_JUSTIFY);
	}

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
	parse_info_renew(&p_info);

	i = 0;
	while (str[i] != '\0')
	{
		j = reach_delim(str, i);
		write(1, str + i, j - i);
		if (str[j] == '\0')
			return (ft_strlen(str));
		// j가 가리키는 곳은 parsing이 끝난 지점의 뒤.
		if ((j = parse(str, &p_info, &ap)) == -1)
			return (-1);
		handle_parse_info(&p_info);
		if (print_handler(&p_info, &ap) < 0)
			return (-1);
		i = j;
	}
	return (ft_strlen(str));
}
