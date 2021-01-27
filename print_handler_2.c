/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/28 01:27:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		printer_type_x(t_parse_info *p_info, va_list *ap);
int		printer_type_d(t_parse_info *p_info, va_list *ap)
{
	char	*sub;
	char	digitlen;
	int		num;
	char	*temp;
	int		sign;
	int		zero_num;

	num = va_arg(*ap, int);
	if ((sub = udx_substr_maker(p_info, num, &digitlen)) == NULL)
		return (-1);
	//(-0000123)까지 만들어졌음. 남은건  (       ) + (-00000123) 처럼 width와 tmp/sub와 합성. + 0flag처리 + precision == 0 && num == 0일때의 처리.
	zero_num = p_info->prec - digitlen;
	if (p_info->width > digitlen + ft_strlen(sub) + zero_num)
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

char	*make_subxdu(t_parse_info *p, unsigned int num, int *digitlen)
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
		add = (char *)ft_calloc(p->prec - *digitlen + 1, 1);
		add[p->prec - *digitlen] = '\0';
		ft_strfill(add, 0, ft_strlen(add) - 1, 0);
		if ((tmp = ft_strjoin(add, original)) == NULL)
			return (NULL);
		return (tmp);
	}
	return (original);
}

// 여기서 해야 할 일은 precision만 해결한 substr을 handler함수에 보내는 것.
char	*udx_substr_maker(t_parse_info *p, unsigned int num, int *digit)
{
	int		digitlen;
	char	*tmp;
	char	*sub;
	char	*add;
	int		len;

	if ((sub = make_subxdu(p,num, &digitlen)) == NULL)
		return (NULL);
	tmp = sub;
	if (p->type == 'd' && (int)num < 0)
		tmp = ft_strjoin("-", sub);
	if (tmp == NULL)
		return (NULL);
	*digit = digitlen;
	return (tmp);
}

int		printer_type_u(t_parse_info *p_info, va_list *ap);
