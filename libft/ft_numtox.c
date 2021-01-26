/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:16:52 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 22:00:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	numtox_initializer(int *sn, int *xd, long long *temp, long long *num)
{
	*xd = 0;
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

	if (num == 0)
		return ("0");
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
	while (num)
	{
		xchar[--xdigit] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (xchar);
}
