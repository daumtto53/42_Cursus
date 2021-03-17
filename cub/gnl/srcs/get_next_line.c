/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:31:16 by mchun             #+#    #+#             */
/*   Updated: 2021/01/14 03:20:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					tb_dynamic_add(t_tb *tb_node, char *buffer, ssize_t readlen)
{
	char		*temp;
	int			i;

	i = -1;
	if (tb_node->tb_arr == NULL)
		if ((tb_node->tb_arr = \
				(char *)malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
			return (-1);
	if (tb_node->tb_size > (tb_node->tb_end + readlen))
	{
		while (++i < readlen)
			(tb_node->tb_arr)[i + tb_node->tb_end + 1] = buffer[i];
	}
	else
	{
		if ((temp = (char *)malloc(tb_node->tb_size * 2)) == NULL)
			return (-1);
		while (++i <= tb_node->tb_end)
			temp[i] = tb_node->tb_arr[i];
		while (i++ <= readlen + tb_node->tb_end)
			temp[i - 1] = buffer[i - tb_node->tb_end - 2];
		tb_dynamic_add_helper(tb_node, temp);
	}
	tb_node->tb_end += readlen;
	return (1);
}

void				tb_dynamic_add_helper(t_tb *tb_node, char *temp)
{
	free(tb_node->tb_arr);
	tb_node->tb_arr = NULL;
	tb_node->tb_arr = temp;
	tb_node->tb_size *= 2;
	return ;
}

int					strcpy_n_alloc(char **line, t_tb *tb_node, int from, int to)
{
	int			i;
	char		*temp;

	if (to <= -2)
		to = tb_node->tb_end;
	if ((temp = (char *)malloc(sizeof(char) * (to - from + 1 + 1))) == NULL)
		return (-1);
	*line = temp;
	i = -1;
	while (++i <= to)
		(*line)[i] = (tb_node->tb_arr)[i];
	(*line)[i] = '\0';
	return (to - from + 1);
}

void				move_tb_arr_n_cpy(t_tb *tb_node, long index)
{
	int			i;
	int			n;

	n = tb_node->tb_end - (index + 2) + 1;
	i = 0;
	while (i < n)
	{
		(tb_node->tb_arr)[i] = (tb_node->tb_arr)[i + index + 2];
		i++;
	}
	if (index <= -2)
		tb_node->tb_end = 0;
	else
		tb_node->tb_end = tb_node->tb_end - (index + 2);
}

int					get_next_line(int fd, char **line)
{
	static t_tb		*tb_head;
	t_tb			*tb_node;
	ssize_t			readlen;
	long			index;
	char			read_buff[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	if ((tb_node = find_tb(&tb_head, fd)) == NULL)
		return (-1);
	index = -2;
	while ((index = find_tb_newline(tb_node, index + 2)) + 1 < 0)
		if ((readlen = read(tb_node->fd, read_buff, BUFFER_SIZE)) == 0)
			break ;
		else if (readlen < 0)
			return (-1);
		else if (tb_dynamic_add(tb_node, read_buff, readlen) < 0)
			return (-1);
	if (strcpy_n_alloc(line, tb_node, 0, index) < 0)
		return (-1);
	move_tb_arr_n_cpy(tb_node, index);
	if (tb_node->tb_end == 0 && index == -2)
		free_tb_node(&tb_head, tb_node);
	return ((index <= -2) ? (0) : (1));
}
