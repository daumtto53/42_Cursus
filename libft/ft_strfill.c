/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:47:50 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 21:59:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfill(char *a, int start, int end, char c)
{
	int		i;
	int		len;

	i = 0;
	len = end - start;
	while (i <= len)
	{
		a[start + i] = c;
		i++;
	}
	return (i);
}
