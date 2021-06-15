/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:27:38 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 14:02:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			printer_type_n(t_info *info, va_list *ap, long long *len)
{
	if (info->len == FT_PF_HH)
		printer_type_nhh(ap, len);
	else if (info->len == FT_PF_H)
		printer_type_nh(ap, len);
	else if (info->len == FT_PF_I)
		printer_type_ni(ap, len);
	else if (info->len == FT_PF_L)
		printer_type_nl(ap, len);
	else
		printer_type_nll(ap, len);
}
