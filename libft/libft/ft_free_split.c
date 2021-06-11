/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:03:49 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 00:03:50 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **splitstr)
{
	int		i;

	i = 0;
	while (splitstr[i])
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
}
