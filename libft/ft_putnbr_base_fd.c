/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:38:13 by mchun             #+#    #+#             */
/*   Updated: 2021/02/07 11:59:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long long n, int base, int fd, int mode)
{
	long long	ln;
	char		*str;

	str = (mode == BASE_DOWN) ? "0123456789abcdef" : "0123456789ABCDEF";
	ln = n;
	if (n < 0 && n != LLONG_MIN)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln / base == 0)
	{
		ft_putchar_fd(str[ln], fd);
		return ;
	}
	ft_putnbr_base_fd(ln / base, base, fd, mode);
	if (n == LLONG_MIN)
		ft_putchar_fd(str[(LLONG_MAX - base + 1) % base], fd);
	else
		ft_putchar_fd(str[ln % base], fd);
}

