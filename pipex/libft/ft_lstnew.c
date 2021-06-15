/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:11:02 by mchun             #+#    #+#             */
/*   Updated: 2020/12/31 13:51:18 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	if (NULL == (newlist = (t_list *)ft_calloc(1, sizeof(t_list))))
		return (NULL);
	newlist->content = (void *)content;
	return (newlist);
}
