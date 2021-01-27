/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/27 21:01:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer_type_x(t_parse_info *p_info, va_list *ap);
int		printer_type_d(t_parse_info *p_info, va_list *ap)
{
	char	*sub;
	int		zero_num;
	int		num;
	char	*signstr;
	char	*temp;

	num = va_arg(*ap, int);
	signstr = (num < 0) ? "-" : "";
	if (p_info->prec <= ft_digitlen(num) && p_info->flag & F_PRECISION)
		zero_num = 0;
	else
		zero_num = p_info->prec - ft_digitlen(num);
	temp = (num < 0) ? itoa(num * -1) : itoa(num);
	if ((sub = (char *)ft_calloc(zero_num + 1, 1)) == NULL)
		return (-1);
	sub[zero_num] = '\0';
	if ((signstr = ft_strjoin(sub, temp)) == NULL)
		return (-1);
	free_all(sub, temp, NULL, NULL);
	temp = (num < 0) ? ft_strjoin("-", signstr) : ft_strjoin("", signstr);
	if (temp == NULL)
		return (-1);
	if (p_info->width < ft_digitlen(num) + ft_strlen(temp) + zero_num)
	{
		if ((sub = (char *)ft_calloc(p_info->width - ft_digitlen(num) - ft_strlen(signstr) - zero_num + 1, 1)) == NULL)
			return (-1);
		ft_strfill(sub, 0, ft_strlen(sub) - 1, ' ');
		sub[p_info->width - ft_digitlen(num) - ft_strlen(signstr) - zero_num] = '\0';
		if (p_info->flag & F_LEFT_JUSTIFY)
			signstr = ft_strjoin(temp, sub);
		else
			signstr = ft_strjoin(sub, temp);
	}
	write(temp);

}
int		printer_type_u(t_parse_info *p_info, va_list *ap);
