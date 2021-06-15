/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:36:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/06 23:54:44 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!(substring = (char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start < ft_strlen(str))
			substring[i] = str[start + i];
		else
			substring[i] = '\0';
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
