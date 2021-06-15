/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:59:24 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:55:25 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	not_ov;
	size_t	ov;
	size_t	i;

	if (!dst && !src)
		return (0);
	if (src <= dst && dst <= src + len - 1)
	{
		not_ov = dst - src;
		ov = len - not_ov;
		i = 0;
		while (i < ov)
		{
			ft_memcpy(dst + len - 1 - i, src + len - 1 - i, 1);
			i++;
		}
		ft_memcpy(dst, src, not_ov);
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
