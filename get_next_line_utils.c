#include <stdio.h>
#include "get_next_line.h"

t_tb		*find_tb(t_tb **tb_head, int fd)
{
	t_tb	*curr_node;
	t_tb	*new_node;

	if ((new_node = (t_tb *)malloc(sizeof(t_tb))) == NULL)
		return (NULL);
	if (*tb_head == NULL)
		curr_node = new_node;
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

void		init_new_tb_node(t_tb *newnode, int fd)
{
	newnode->tb_arr = NULL;
	newnode->fd = fd;
	newnode->next = NULL;
	newnode->tb_end = 0;
	newnode->tb_size = 0;
}
