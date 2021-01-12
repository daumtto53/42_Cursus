/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:31:19 by mchun             #+#    #+#             */
/*   Updated: 2021/01/12 01:26:02 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

t_tb			*find_tb(t_tb **tb_head, int fd)
{
	t_tb		*curr_node;
	t_tb		*new_node;

	if ((new_node = (t_tb *)malloc(sizeof(t_tb))) == NULL)
		return (NULL);
	if (tb_head == NULL)
	{
		curr_node = new_node;
		tb_head = &curr_node;
	}
	else
	{
		curr_node = *tb_head;
		while (curr_node->next != NULL)
		{
			if (curr_node->fd == fd)
				return (curr_node);
			curr_node = curr_node->next;
		}
		if (curr_node->fd == fd)
			return (curr_node);
		curr_node->next = new_node;
		curr_node = new_node;
	}
	init_new_tb_node(curr_node, fd);
	return (curr_node);
}

void			init_new_tb_node(t_tb *newnode, int fd)
{
	newnode->tb_arr = NULL;
	newnode->fd = fd;
	newnode->next = NULL;
	newnode->tb_end = -1;	//왜 tb_end를 -1로 주었는가?
	newnode->tb_size = BUFFER_SIZE;
}

long			find_tb_newline(t_tb *tb_node, long index)
{
	while (index <= tb_node->tb_end)
	{
		if ((tb_node->tb_arr)[index] == '\n')
			return (index - 1);
		index++;
	}
	return (-2);
}

int				tb_dynamic_add(t_tb *tb_node, char *buffer, ssize_t readlen)
{
	char		*temp;
	int			i;

	if (tb_node->tb_arr == NULL)
		if ((tb_node->tb_arr = (char *)malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
			return (-1);
	if (tb_node->tb_size >= (tb_node->tb_end + readlen))
	{
		i = -1;
		while (++i <= readlen)
			(tb_node->tb_arr)[i + tb_node->tb_end + 1] = buffer[i];
	}
	else
	{
		i = -1;
		if ((temp = (char *)malloc(tb_node->tb_size * 2)) == NULL)
			return (-1);
		while (++i <= tb_node->tb_end)
			temp[i] = tb_node->tb_arr[i];
		while (i++ <= readlen + tb_node->tb_end)
			temp[i - 1] = buffer[i - tb_node->tb_end - 2];
		free(tb_node->tb_arr);
		tb_node->tb_arr = temp;
		tb_node->tb_size *= 2;
	}
	tb_node->tb_end += readlen;
	return (1);
}

//line에 동적할당한 temp가 안박히는게 원인.
int				strcpy_n_alloc(char **line, t_tb *tb_node, int from, int to)
{
	int			i;
	char		*temp;

	if ((temp = (char *)malloc(sizeof(char) * (to - from + 1 + 1))) == NULL)
		return (-1);
	i = -1;
	while (++i <= to)
		temp[i] = (tb_node->tb_arr)[i];
	temp[i] = '\0';
	line = &temp;
	return (to - from + 1);
}

void			move_tb_arr_n_cpy(t_tb *tb_node, long index)
{
	int			i;
	int			n;

	n = tb_node->tb_end - (index + 2) + 1;
	i = 0;
	while (i < n)
		(tb_node->tb_arr)[i] = (tb_node->tb_arr)[i + index + 2];
	tb_node->tb_end = tb_node->tb_end - (index + 2);
}
