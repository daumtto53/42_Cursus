/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:37:33 by mchun             #+#    #+#             */
/*   Updated: 2021/01/06 23:55:04 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res_str;
	size_t	i;

	if (NULL == (res_str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	i = -1;
	while (s[++i])
		res_str[i] = f(i, s[i]);
	return (res_str);
}
