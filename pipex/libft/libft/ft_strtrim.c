/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:52:17 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 22:58:35 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trimstr;
	size_t	trim_len;

	trimstr = (char *)s;
	while (*trimstr && ft_strchr(set, *trimstr))
		trimstr++;
	trim_len = ft_strlen(trimstr);
	while (trim_len && ft_strchr(set, trimstr[trim_len]))
		trim_len--;
	trimstr = ft_substr(trimstr, 0, trim_len + 1);
	return (trimstr);
}
