/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:32:52 by mchun             #+#    #+#             */
/*   Updated: 2020/12/29 11:59:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(number * size)))
		return (NULL);
	ft_bzero(ptr, sizeof(char) * number * size);
	return (ptr);
}
