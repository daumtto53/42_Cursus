/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:31:16 by mchun             #+#    #+#             */
/*   Updated: 2021/01/12 01:26:14 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	static t_tb		**tb_head;
	t_tb			*tb_node;
	ssize_t			readlen;
	long			index;
	char			read_buff[BUFFER_SIZE];

	line = NULL;
	tb_head = NULL;
	tb_node =  find_tb(tb_head, fd);
	index = -2;
	//while ((index = find_tb_newline(tb_node, index + 2)) + 1 < 0)으로, <=을 줄 때는 segerror남.
	//왜 부등호에 등호를 안붙였는가?
	while ((index = find_tb_newline(tb_node, index + 2)) + 1 <= 0)
	{
		if ((readlen = read(tb_node->fd, read_buff, BUFFER_SIZE)) == 0)
			break;
		else if (readlen < 0)
			return (-1);
		else
			if (tb_dynamic_add(tb_node, read_buff, readlen) < 0)
				return (-1);
	}
	if (readlen == 0 && tb_node->tb_end == 0)
		return (0);
	if (strcpy_n_alloc(line, tb_node, 0, index) < 0)
		return (-1);
	// printf("%s\n", *line);
	exit(0);
	move_tb_arr_n_cpy(tb_node, index);
	return (1);
}
