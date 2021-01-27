/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/27 15:35:21 by mchun            ###   ########.fr       */
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
	if ((s = (char *)malloc(sizeof(char) * (p_info->width  + 1))) == NULL)
		return (-1);
	ft_strfill(s, 0, ft_strlen(s) - 1, ' ');
	if (p_info->flag & F_LEFT_JUSTIFY)
		s[0] = c;
	else
		s[p_info->width - 1] = c;
	ft_putstr_fd(s, 1);
	free(s);
	s = NULL;
	return (1);
}

int		printer_type_s_helper(t_parse_info *p, va_list *ap, char **f, int *len)
{
	char	*front;

	front = va_arg(*ap, char *);
	if (front = NULL)
		front = "(null)";
	if (p->flag & F_PRECISION && 0 <= p->prec && p->prec <= ft_strlen(front))
		*len = p->prec;
	else
		*len  = ft_strlen(front);
	if ((front = ft_substr(front, 0, *len)) == NULL)
		return (-1);
	*f = front;
	return (-1);
}

int		printer_type_s(t_parse_info *p_info, va_list *ap)
{
	char	*front;
	char	*back;
	char	*temp;
	int		strlength;

	if (printer_type_s_helper(p_info, ap, &front, &strlength) == -1)
		return (-1);
	back = front;
	if (p_info->width > strlength)
	{
		if ((temp= (char *)calloc(p_info->width - strlength + 1, 1)) == NULL)
			return (-1);
		ft_strfill(temp, 0, ft_strlen(temp) - 1, ' ');
		if (p_info->flag & F_LEFT_JUSTIFY)
			back = temp;
		else
			front = temp;
		if ((temp = ft_strjoin(front, back)) == NULL)
			return (-1);
	}
	write(1, temp, ft_strlen(temp));
	free(temp);
	free(back);
	free(front);
	return (1);
}

int		printer_type_p(t_parse_info *p_info, va_list *ap)
{

}

int		printer_type_perc(t_parse_info *p_info, va_list *ap)
{

}

