/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:48:59 by mchun             #+#    #+#             */
/*   Updated: 2020/12/30 01:56:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"


size_t	count_partition(char *ptr, char delim)
{
	size_t	partition_num = 0;

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

void	make_dup_zero(char *ptr, char delim)
{
	while (*ptr)
	{
		if (*ptr == delim)
			*ptr = '\0';
		ptr++;
	}
}

void	free_p_arr(char **const p_arr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		free(p_arr[i++]);
}

char	**ft_split(char *const str, char c)
{
	char	*ptr;
	char	*ptr2;
	char	**p_arr;
	size_t	partition_num;
	char	*temp;
	char	**p_arr_temp;

	ptr = (char *)str;
	partition_num = count_partition(ptr, c);
	printf("partition num : %ld\n", partition_num);
	return (p_arr_temp);
	if (0 == (p_arr = (char **)ft_calloc(partition_num + 1, sizeof(char *))))
		return (NULL);
	p_arr_temp = p_arr;
	ptr = (char *)ft_strdup(str);
	temp = ptr;
	ptr2 = ft_strchr(ptr, '\0');
	printf("%p %p\n", ptr, ptr2);
	make_dup_zero(ptr, c);
	partition_num = 0;
	while (ptr != ptr2)
	{
		while (*ptr == '\0' && ptr != ptr2)
		{
			ptr++;
		}
		if (ptr == ptr2)
			break ;
		if (!(*p_arr++ = ft_strdup(ptr)))
		{
			free_p_arr(p_arr, partition_num);
			return (NULL);
		}
		printf("%s\n", ptr);
		ptr += ft_strlen(ptr);
		partition_num++;
	}
	free(temp);
	return (p_arr_temp);
}

int		main()
{
	char *s = "                  olol";
	char **result = ft_split(s, ' ');

	//printf("%s\n", result[0]);

}
