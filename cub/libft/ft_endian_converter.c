/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:19:42 by mchun             #+#    #+#             */
/*   Updated: 2021/03/18 22:18:16 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_endian_converter(long long src, int size)
{
	int			return_value;
	long long	mask;
	int			s;

	if (size == 1 || (size != 8 && size != 4 && size != 2))
		return (0);
	if (size == 8)
		mask = 0xFF00000000000000;
	else if (size == 4)
		mask = 0xFF000000;
	else if (size == 2)
		mask = 0xFF00;

	return_value = 0;
	s = size * 2;
	while (size)
	{
		return_value |= ((mask & src) >> ((size - 1) * 2) << (s - size * 2));
		size--;
		mask = mask >> 2;
	}
	return (return_value);
}
