/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:00:22 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:56:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*b1cpy;
	unsigned char	*b2cpy;

	b1cpy = (unsigned char *)b1;
	b2cpy = (unsigned char *)b2;
	while (len--)
	{
		if (*b1cpy != *b2cpy)
			return (*b1cpy - *b2cpy);
		b1cpy++;
		b2cpy++;
	}
	return (0);
}
