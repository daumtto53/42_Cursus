/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:36:04 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 16:19:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	int		i;
	int		j;
	int		len;
	int		k;

	if (!s1)
		return (NULL);
	if (!(dup = ft_strdup(s1)))
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	len = ft_strlen(set);
	while (!s1[++i])
	{
		while (j < len)
		{
			if (s1[i] == set[j++])
				break;
		}
		if (j != len)
			dup[k++] = s1[i];
		j = 0;
	}
	dup[i] = '\0';
	return (dup);
}
