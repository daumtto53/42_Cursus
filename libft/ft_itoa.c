/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:37:29 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:50:44 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret_str;
	int		num_len;
	long	ln;

	num_len = (n <= 0) ? 1 : 0;
	ln = (n < 0) ? (long)n * -1 : (long)n;
	while (ln)
	{
		num_len++;
		ln /= 10;
	}
	ln = (n < 0) ? (long)n * -1 : (long)n;
	if (0 == (ret_str = (char *)ft_calloc(num_len + 1, sizeof(char))))
		return (NULL);
	ret_str[num_len] = '\0';
	while (--num_len >= 0)
	{
		ret_str[num_len] = ln % 10 + '0';
		ln /= 10;
	}
	if (n < 0)
		ret_str[0] = '-';
	return (ret_str);
}
