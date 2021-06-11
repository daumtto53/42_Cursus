/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:00:42 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:57:56 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*bcpy;
	unsigned char	ch;

	bcpy = (unsigned char *)b;
	ch = c;
	while (len--)
	{
		if (*bcpy == ch)
			return (bcpy);
		bcpy++;
	}
	return (NULL);
}
