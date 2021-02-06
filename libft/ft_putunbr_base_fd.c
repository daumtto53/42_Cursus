/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:38:13 by mchun             #+#    #+#             */
/*   Updated: 2021/02/06 17:31:57 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd, int mode)
{
	unsigned long long	ln;
	char				*str;

	str = (mode == BASE_DOWN) ? "0123456789abcedf" : "0123456789ABCDEF";
	ln = n;
	if (ln / base == 0)
	{
		ft_putchar_fd(str[ln], fd);
		return ;
	}
	ft_putunbr_base_fd(ln / base, base, fd, mode);
	ft_putchar_fd(str[ln % base], fd);
}
