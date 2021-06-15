/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:16:52 by mchun             #+#    #+#             */
/*   Updated: 2021/02/02 10:26:51 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	numtox_initializer(int *sn, int *xd, long long *temp, long long *num)
{
	*xd = 0;
	if (*num == 0)
		*xd = 1;
	*sn = 0;
	if (*num < 0)
	{
		*sn = 1;
		*num *= -1;
	}
	*temp = *num;
}

char	*ft_numtox(long long int num)
{
	int				sign;
	int				xdigit;
	char			*xchar;
	long long int	temp;

	numtox_initializer(&sign, &xdigit, &temp, &num);
	while (temp)
	{
		xdigit++;
		temp /= 16;
	}
	if ((xchar = (char *)ft_calloc(xdigit + sign + 1, sizeof(char))) == NULL)
		return (NULL);
	xchar[xdigit + sign] = '\0';
	xdigit = xdigit + sign;
	if (sign == 1)
		xchar[0] = '-';
	while (--xdigit >= 0)
	{
		xchar[xdigit] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (xchar);
}
