/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:05:07 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 22:58:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	srcsize = ft_strlen(src);
	if (dstsize)
	{
		len = (dstsize > srcsize) ? srcsize : dstsize - 1;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srcsize);
}
