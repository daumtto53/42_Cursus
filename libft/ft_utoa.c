/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:26:40 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 01:39:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char	*ret_str;
	int		num_len;
	unsigned int ln;

	num_len = (n <= 0) ? 1 : 0;
	ln = n;
	while (ln)
	{
		num_len++;
		ln /= 10;
	}
	if (0 == (ret_str = (char *)ft_calloc(num_len + 1, 1)))
		return (NULL);
	ret_str[num_len] = '\0';
	while (--num_len >= 0)
	{
		ret_str[num_len] = n % 10 + '0';
		n /= 10;
	}
	return (ret_str);
}
