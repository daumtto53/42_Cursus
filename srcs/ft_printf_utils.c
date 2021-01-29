/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:22:16 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 15:57:35 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdio.h>

void	free_all(void *a, void *b, void *c, void *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}

char	*printer_width_helper(t_parse_info *p_info, int len, char *sub)
{
	char	*front;
	char	*back;
	char	*temp;
	char	*join;

	front = sub;
	back = sub;
	if ((temp = (char *)calloc(len + 1, 1)) == NULL)
		return (NULL);
	temp[len] = '\0';
	ft_strfill(temp, 0, len, ' ');
	if (p_info->flag & F_LEFT_JUSTIFY)
		back = temp;
	else
		front = temp;
	if ((join = ft_strjoin(front, back)) == NULL)
		return (NULL);
	free_all(front, back, NULL, NULL);
	return (join);
}

void	debug_p_info(t_parse_info *p)
{

	printf("type : %c\n", p->type);
	printf("width : %d\n", p->width);
	printf("precision : %d\n", p->prec);
	printf("flag : %d\n", p->flag);
}
