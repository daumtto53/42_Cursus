/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:54:30 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:55:07 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*destcpy;

	destcpy = (unsigned char *)dest;
	while (len--)
	{
		*destcpy = (unsigned char)c;
		destcpy++;
	}
	return (dest);
}
