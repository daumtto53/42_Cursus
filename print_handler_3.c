/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:43:04 by mchun             #+#    #+#             */
/*   Updated: 2021/01/27 19:12:41 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer_type_perc(t_parse_info *p_info, va_list *ap)
{
	char	*temp;
	char	*front;
	char	*back;

	front = "%";
	back = front;
	if (p_info->width > 1)
	{
		if ((temp = ft_calloc(p_info->width - 1 + 1, 1)) == NULL)
			return (-1);
		if (p_info->flag & F_ZERO)
			ft_strfill(temp, 0, ft_strlen(temp) - 1, '0');
		else
			ft_strfill(temp, 0, ft_strlen(temp) - 1, ' ');
		if (p_info->flag & F_LEFT_JUSTIFY)
			back = temp;
		else
			front = temp;
		if ((temp = ft_strjoin(front, back)) == NULL)
			return (-1);
	}
	ft_putstr_fd(temp, 1);
	free_all(temp, front, back, NULL);
	return (-1);
}
