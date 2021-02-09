/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_n_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:28:59 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 14:04:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			printer_type_nhh(va_list *ap, long long *len)
{
	char	*p;

	p = va_arg(*ap, char *);
	if (p == NULL)
		return ;
	*p = *len & (char)-1;
}

void			printer_type_nh(va_list *ap, long long *len)
{
	short	*p;

	p = va_arg(*ap, short *);
	if (p == NULL)
		return ;
	*p = *len & (short)-1;
}

void			printer_type_ni(va_list *ap, long long *len)
{
	int		*p;

	p = va_arg(*ap, int *);
	if (p == NULL)
		return ;
	*p = *len & (int)-1;
}

void			printer_type_nl(va_list *ap, long long *len)
{
	long	*p;

	p = va_arg(*ap, long *);
	if (p == NULL)
		return ;
	*p = *len & (long)-1;
}

void			printer_type_nll(va_list *ap, long long *len)
{
	long long	*p;

	p = va_arg(*ap, long long *);
	if (p == NULL)
		return ;
	*p = *len;
}
