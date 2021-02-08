/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_n_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:28:59 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 00:31:28 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			printer_type_nhh(va_list *ap, int *len)
{
	char	*p;

	p = va_arg(*ap, char *);
	*p = *len;
}

void			printer_type_nh(va_list *ap, int *len)
{
	short	*p;

	p = va_arg(*ap, short *);
	*p = *len;
}

void			printer_type_ni(va_list *ap, int *len)
{
	int		*p;

	p = va_arg(*ap, int *);
	*p = *len;

}

void			printer_type_nl(va_list *ap, int *len)
{
	long	*p;

	p = va_arg(*ap, long *);
	*p = *len;
}

void			printer_type_nll(va_list *ap, int *len)
{
	long long	*p;

	p = va_arg(*ap, long long *);
	*p = *len;
}
