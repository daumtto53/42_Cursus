/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:17:48 by mchun             #+#    #+#             */
/*   Updated: 2020/12/26 17:03:03 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n = overlapped number
** k = non-overlapped number
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	int		k;
	int		n;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	n = dstcpy - srccpy;
	k = len - n;

	i = 0;
	while (i < k)
	{
		*(dstcpy + n + i) = *(srccpy + n + i);
		i++;
	}
	i = 0;
	while (n--)
	{
		*(dstcpy + i) = *(srccpy + i);
		i++;
	}
	return (dst);
}
