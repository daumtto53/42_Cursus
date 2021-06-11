/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:52:42 by mchun             #+#    #+#             */
/*   Updated: 2020/12/30 14:24:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long	i;
	long	blen;
	long	llen;

	i = 0;
	blen = ft_strlen(big);
	llen = ft_strlen(little);
	blen = blen - 0;
	if (llen == 0)
		return ((char *)big);
	while (i <= (long)len - llen)
	{
		if (ft_strncmp(big + i, little, llen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
