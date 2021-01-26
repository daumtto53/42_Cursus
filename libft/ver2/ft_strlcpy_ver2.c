/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:21:57 by mchun             #+#    #+#             */
/*   Updated: 2020/12/26 20:03:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** No Null guard.
*/
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	srcsize;
	int		len;
	int		i;

	if (!dst || !src)
		return (0);
	i = 0;
	srcsize = ft_strlen(src);
	if (!!dstsize)
	{
		len = (dstsize > srcsize) ? srcsize : dstsize - 1;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
