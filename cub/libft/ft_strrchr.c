/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:49:08 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 22:57:35 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s) + 1;
	while (--len >= 0)
	{
		if (s[len] == c)
			return ((char *)(s + len));
	}
	return (NULL);
}
