/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:09:00 by mchun             #+#    #+#             */
/*   Updated: 2021/01/27 18:32:20 by mchun            ###   ########.fr       */
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
	if ((s = (char *)malloc(sizeof(char) * (p_info->width + 1))) == NULL)
		return (-1);
	s[p_info->width] = '\0';
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
		*len = ft_strlen(front);
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
		if ((temp = (char *)calloc(p_info->width - strlength + 1, 1)) == NULL)
			return (-1);
		temp[p_info->width - strlength] = '\0';
		ft_strfill(temp, 0, ft_strlen(temp) - 1, ' ');
		if (p_info->flag & F_LEFT_JUSTIFY)
			back = temp;
		else
			front = temp;
		if ((temp = ft_strjoin(front, back)) == NULL)
			return (-1);
	}
	write(1, temp, ft_strlen(temp));
	free_all(temp, front, back, NULL);
	return (1);
}

int		printer_type_p_helper(t_parse_info *p, va_list *a, char **f, char **b)
{
	char	*ptr;
	char	*front;

	ptr = va_arg(*a, char *);
	if (ptr == NULL)
		ptr = 0;
	if ((ptr = ft_numtox((long long)ptr)) == NULL)
		return (-1);
	if ((front = ft_strjoin("0x", ptr)) == NULL)
		return (-1);
	*f = front;
	*b = front;
	free(ptr);
}

int		printer_type_p(t_parse_info *p_info, va_list *ap)
{
	char	*ptr;
	char	*front;
	char	*back;

	if (printer_type_p_helper(p_info, ap, &front, &back) == -1)
		return (-1);
	if (p_info->width > ft_strlen(front))
	{
		if ((ptr = \
			(char *)calloc(p_info->width - ft_strlen(front) + 1, 1)) == NULL)
			return (-1);
		ptr[p_info->width - ft_strlen(front)] = '\0';
		ft_strfill(ptr, 0, ft_strlen(ptr), ' ');
		if (p_info->flag & F_LEFT_JUSTIFY)
			back = ptr;
		else
			front = ptr;
		if ((ptr = ft_strjoin(front, back)) == NULL)
			return (-1);
	}
	write(1, ptr, ft_strlen(ptr));
	free_all(ptr, front, back, NULL);
	return (1);
}
