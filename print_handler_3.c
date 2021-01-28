/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:43:04 by mchun             #+#    #+#             */
/*   Updated: 2021/01/28 15:35:59 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// int		printer_type_perc(t_parse_info *p_info, va_list *ap)
// {
// 	char	*typearg;
// 	char	*product;

// 	typearg = "%";
// 	if (p_info->width > 1)
// 	{
// 		if ((product = printer_width_helper(p_info, p_info->width - 1, product)) == NULL)
// 			return (-1);
// 		if (p_info->flag & F_ZERO)
// 		{
// 			if (p_info->flag & F_LEFT_JUSTIFY)
// 				ft_strfill(product, 1, ft_strlen(product) - 1, '0');
// 			else
// 				ft_strfill(product, 0, ft_strlen(product) - 2, '0');
// 		}
// 	}
// 	ft_putstr_fd(product, 1);
// 	free(product);
// 	return (-1);
// }
