/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:37 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 01:01:12 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printer_type_xud(t_info *p_info, va_list *ap, int *len)
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
	*len += ft_strlen(product);
	free(product);
	return (1);
}
