/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 13:43:19 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_flag_handler(t_parse_info *p, int sign, int dig, char *prod)
{
	if (p->flag & F_ZERO && p->width > dig + sign)
		ft_strfill(prod, 0, p->width - (dig + sign) - 1, '0');
	if (sign)
		prod[0] = '-';
}

int		prec_num_zero_handler(t_parse_info *p_info, int num, char *prod)
{
	if (p_info->flag & F_PRECISION && p_info->prec == 0 && num == 0)
	{
		if (p_info->width == 0)
			return (0);
		ft_strfill(prod, 0, ft_strlen(prod) - 1, ' ');
	}
	return (1);
}

int		printer_type_xud(t_parse_info *p_info, va_list *ap, int *len)
{
	int		digitlen;
	int		num;
	char	*product;
	int		sign;

	num = va_arg(*ap, int);
	sign = (num < 0) ? 1 : 0;
	if ((product = xud_substr_maker(p_info, num, &digitlen)) == NULL)
		return (-1);
	if (p_info->width > (int)ft_strlen(product))
	{
		if ((product = printer_width_helper(p_info, p_info->width - ft_strlen(product), product)) == NULL)
			return (-1);
	}
	zero_flag_handler(p_info, sign, digitlen, product);
	if (prec_num_zero_handler(p_info, num, product) == 0)
		return (0);
	ft_putstr_fd(product, 1);
	*len = ft_strlen(product);
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
	if (p->prec > *digitlen && p->flag & F_PRECISION)
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

