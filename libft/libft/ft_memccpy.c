/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:18:09 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 17:33:07 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char *destcpy;
	unsigned char *srccpy;
	unsigned char cc;

	if (!dest && !src)
		return (NULL);
	cc = c;
	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	while (len--)
	{
		*destcpy = *srccpy;
		if (cc == *destcpy)
			return (destcpy + 1);
		destcpy++;
		srccpy++;
	}
	return (NULL);
}
