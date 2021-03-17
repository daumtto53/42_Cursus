/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:48:59 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:58:12 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_partition(char *ptr, char delim)
{
	size_t	partition_num;

	partition_num = 0;
	while (ptr && *ptr)
	{
		while (*ptr == delim && *ptr)
		{
			ptr++;
		}
		if (!(*ptr))
			break ;
		ptr = ft_strchr(ptr, delim);
		partition_num++;
	}
	return (partition_num);
}

static void		make_dup_zero(char *ptr, char delim)
{
	while (*ptr)
	{
		if (*ptr == delim)
			*ptr = '\0';
		ptr++;
	}
}

static char		**free_p_arr(char **const p_arr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		free(p_arr[i++]);
	free(p_arr);
	return (NULL);
}

static char		**split_by_zero(char **p_arr, char *ptr, char *endptr)
{
	size_t	partition_num;

	partition_num = 0;
	while (ptr != endptr)
	{
		while (*ptr == '\0' && ptr != endptr)
			ptr++;
		if (ptr == endptr)
			break ;
		if (!(*p_arr++ = ft_strdup(ptr)))
			return (free_p_arr(p_arr, partition_num));
		ptr += ft_strlen(ptr);
		partition_num++;
	}
	return (p_arr);
}

char			**ft_split(char const *str, char c)
{
	char	*ptr;
	char	*endptr;
	char	**p_arr;
	size_t	partition_num;
	char	*temp;

	ptr = (char *)str;
	partition_num = count_partition(ptr, c);
	if (0 == (p_arr = (char **)ft_calloc(partition_num + 1, sizeof(char *))))
		return (NULL);
	ptr = (char *)ft_strdup(str);
	temp = ptr;
	endptr = ft_strchr(ptr, '\0');
	make_dup_zero(ptr, c);
	split_by_zero(p_arr, ptr, endptr);
	free(temp);
	return (p_arr);
}
