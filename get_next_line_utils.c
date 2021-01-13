/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:31:19 by mchun             #+#    #+#             */
/*   Updated: 2021/01/13 18:46:41 by mchun            ###   ########.fr       */
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
	if (*tb_head == NULL)
	{
		curr_node = new_node;
		*tb_head = curr_node;
	}
	else
	{
		curr_node = *tb_head;
		while (curr_node->next != NULL)
		{
			if (curr_node->fd == fd)
				return (return_n_free_tb_node(curr_node, new_node));
			curr_node = curr_node->next;
		}
		if (curr_node->fd == fd)
			return (return_n_free_tb_node(curr_node, new_node));
		curr_node->next = new_node;
		curr_node = new_node;
	}
	return (init_n_return_new_tb_node(curr_node, fd));
}

void			free_tb_node(t_tb **head, t_tb *tb_node)
{
	t_tb		*curr_node;
	t_tb		*prev_node;

	if (*head == tb_node)
	{
		curr_node = tb_node->next;
		free((*head)->tb_arr);
		free(*head);
		*head = curr_node;
		return ;
	}
	curr_node = (*head)->next;
	prev_node = (*head);
	while (curr_node != NULL)
	{
		if (curr_node == tb_node)
		{
			prev_node->next = curr_node->next;
			free(curr_node->tb_arr);
			free(curr_node);
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
	}
}

t_tb			*return_n_free_tb_node(t_tb *curr_node, t_tb *new_node)
{
	free(new_node);
	new_node = NULL;
	return (curr_node);
}

t_tb			*init_n_return_new_tb_node(t_tb *newnode, int fd)
{
	newnode->tb_arr = NULL;
	newnode->fd = fd;
	newnode->next = NULL;
	newnode->tb_end = -1;
	newnode->tb_size = BUFFER_SIZE;
	return (newnode);
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
