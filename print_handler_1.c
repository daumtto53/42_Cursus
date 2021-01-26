/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 22:37:32 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer_type_c(t_parse_info *p_info, va_list *ap)
{
	int				a;
	unsigned char	c;
	char			*s;

	a = va_arg(*ap, int);
	c = (unsigned char)a;
	if (p_info->width <= 1)
		p_info->width = 1;
	if ((s = (char *)malloc(sizeof(char) * (p_info->width  + 1))))
		return (-1);
	ft_strfill(s, 0, ft_strlen(s) - 1, ' ');
	if (p_info->flag & F_LEFT_JUSTIFY)
		s[0] = c;
	else
		s[p_info->width - 1] = c;
	ft_putstr_fd(s, 1);
	free(s);
	s = NULL;
}

int		printer_type_s(t_parse_info *p_info, va_list *ap);
int		printer_type_p(t_parse_info *p_info, va_list *ap);
int		printer_type_perc(t_parse_info *p_info, va_list *ap);

