/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/28 16:16:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer_type_xud(t_parse_info *p_info, va_list *ap)
{
	char	*sub;
	int		digitlen;
	int		num;
	char	*product;
	int		sign;
	int		zero_num;
	char	*str;

	num = va_arg(*ap, int);
	sign = (num < 0) ? 1 : 0;
	if ((product = xud_substr_maker(p_info, num, &digitlen)) == NULL)
		return (-1);
	zero_num = p_info->prec - digitlen;
	if (p_info->width > digitlen + ft_strlen(sub) + zero_num)
	{
		if ((product = printer_width_helper(p_info, p_info->width - (digitlen + sign + zero_num), product)) == NULL)
			return (-1);
	}
	ft_putstr_fd(product, 1);
	free(product);
	return (1);
}

char	*make_subxud(t_parse_info *p, unsigned int num, int *digitlen)
{
	char	*add;
	char	*original;
	char	*tmp;

	if (p->type == 'x' || p->type == 'X')
		original = ft_numtox(num);
	else if (p->type == 'd' && (int)num < 0)
		original = ft_itoa((int)num * -1);
	else
		original = ft_itoa((int)num);
	if (original == NULL)
		return (NULL);
	*digitlen = ft_strlen(original);
	if (p->prec > digitlen && p->flag & F_PRECISION)
	{
		if ((add = (char *)ft_calloc(p->prec - *digitlen + 1, 1)) == NULL)
			return (NULL);
		add[p->prec - *digitlen] = '\0';
		ft_strfill(add, 0, ft_strlen(add) - 1, 0);
		if ((tmp = ft_strjoin(add, original)) == NULL)
			return (NULL);
		free_all(add, original, NULL, NULL);
		return (tmp);
	}
	return (original);
}

// 여기서 해야 할 일은 precision만 해결한 substr을 handler함수에 보내는 것.
char	*xud_substr_maker(t_parse_info *p, unsigned int num, int *digit)
{
	int		digitlen;
	char	*tmp;
	char	*sub;

	if ((sub = make_subxud(p, num, &digitlen)) == NULL)
		return (NULL);
	*digit = digitlen;
	if (p->type == 'd' && (int)num < 0)
	{
		if ((tmp = ft_strjoin("-", sub)) == NULL)
			return (NULL);
		free(sub);
		sub = tmp;
	}
	return (sub);
}

