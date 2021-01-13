/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:31:16 by mchun             #+#    #+#             */
/*   Updated: 2021/01/13 18:01:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	static t_tb		*tb_head;
	t_tb			*tb_node;
	ssize_t			readlen;
	long			index;
	char			read_buff[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	tb_node =  find_tb(&tb_head, fd);
	index = -2;
	while ((index = find_tb_newline(tb_node, index + 2)) + 1 < 0)
	{
		if ((readlen = read(tb_node->fd, read_buff, BUFFER_SIZE)) == 0)
			break;
		else if (readlen < 0)
			return (-1);
		else
			if (tb_dynamic_add(tb_node, read_buff, readlen) < 0)
				return (-1);
	}
	if (strcpy_n_alloc(line, tb_node, 0, index) < 0)
		return (-1);
	move_tb_arr_n_cpy(tb_node, index);
	if (tb_node->tb_end == 0 && index == -2)
		free_tb_node(&tb_head, tb_node);
	return ((index <= -2) ? (0) : (1));
}
