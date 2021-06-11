/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:48:58 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:53:27 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t len)
{
	int				i;
	unsigned char	*destcpy;

	if (!src && !dest)
		return (dest);
	i = 0;
	destcpy = (unsigned char *)dest;
	while (len--)
	{
		*destcpy = *((unsigned char *)src + i);
		destcpy++;
		i++;
	}
	return (dest);
}
