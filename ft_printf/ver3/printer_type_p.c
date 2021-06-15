/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_type_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:10:14 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 20:02:06 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*printer_type_p_hexmaker(t_info *i, char *p)
{
	if (p == NULL && !(i->flag & F_PREC))
		p = ft_numtox((long long)0);
	else if (p == NULL && i->flag & F_PREC)
		p = ft_strjoin("", "");
	else
		p = ft_numtox((long long)p);
	return (p);
}

int		printer_type_p(void *ptr, t_info *info, int *ft_errno)
{
	char	*p;
	int		padd_len;
	char	fill;
	int		len;

	fill = (info->flag & F_ZERO) ? '0' : ' ';
	if ((p = printer_type_p_hexmaker(info, ptr)) == NULL)
		*ft_errno = FT_ERR;
	padd_len = (info->width - (ft_strlen(p) + 2));
	while (!(info->flag & F_LJUST) && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(p, 1);
	while (info->flag & F_LJUST && padd_len-- > 0)
		ft_putchar_fd(fill, 1);
	len = (ft_strlen(p) + 2);
	free(p);
	return (len);
}
