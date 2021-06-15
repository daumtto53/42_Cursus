/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:38:13 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 16:34:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln / 10 == 0)
	{
		ft_putchar_fd(ln + '0', fd);
		return ;
	}
	ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(ln % 10 + '0', fd);
}
