/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:03:36 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 00:03:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_split_free(char **splitptr)
{
	int		i;

	i = -1;
	while (splitptr[++i])
		free(splitptr[i]);
	free(splitptr);
}
