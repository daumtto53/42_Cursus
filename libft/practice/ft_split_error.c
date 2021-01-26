/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:48:59 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 23:43:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free(): invalid pointer
*/
#include "libft.h"

size_t	count_partition(char *ptr, char delim)
{
	size_t	partition_num = 0;

	while (!(*ptr))
	{
		while (*ptr == delim && *ptr)
			ptr++;
		if (!(*ptr))
			break;
		ptr = ft_strchr(ptr, delim);
		partition_num++;
	}
	return (partition_num);
}

void	make_dup_zero(char *ptr, char delim)
{
	while (!(*ptr))
	{
		if (*ptr == delim)
			*ptr = '\0';
		ptr++;
	}
}

void	free_p_arr(char **const p_arr)
{
	char	**temp;

	temp = (char **)p_arr;
	while (!(*temp))
		free(*temp);
}

char	**ft_split(char *const str, char c)
{
	char	*ptr;
	char	*ptr2;
	char	**p_arr;
	size_t	partition_num;

	ptr = (char *)str;
	partition_num = count_partition(ptr, c);
	if (0 == (p_arr = (char **)ft_calloc(partition_num + 1, sizeof(char *))))
		return (NULL);
	ptr = (char *)ft_strdup(str);
	ptr2 = ft_strchr(ptr, '\0');
	make_dup_zero(ptr, c);
	while (ptr != ptr2)
	{
		while (*ptr == '\0')
			ptr++;
		if (!(*p_arr++ = ft_strdup(ptr)))
		{
			free_p_arr(p_arr);
			return (NULL);
		}
		ptr += ft_strlen(ptr);
	}
	return (p_arr);
}
