/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:22:56 by mchun             #+#    #+#             */
/*   Updated: 2020/12/30 20:36:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size > dstlen)
	{
		i = 0;
		while (i < (size - dstlen - 1) && i <= srclen)
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
		return (dstlen + srclen);
	}
	else
		dst[dstlen] = '\0';
	return (size + srclen);
}
