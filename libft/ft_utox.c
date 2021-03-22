/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:10:40 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 01:25:16 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utox(unsigned int num)
{
	int				xdigit;
	unsigned int	temp;
	char			*xchar;

	xdigit = 0;
	if (num == 0)
		xdigit = 1;
	temp = num;
	while (temp)
	{
		xdigit++;
		temp /= 16;
	}
	if ((xchar = (char *)ft_calloc(xdigit + 1, 1)) == NULL)
		return (NULL);
	xchar[xdigit] = '\0';
	while (xdigit > 0)
	{
		xchar[--xdigit] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (xchar);
}
