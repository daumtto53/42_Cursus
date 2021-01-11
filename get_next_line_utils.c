#include <stdio.h>
#include "get_next_line.h"

t_tb			*find_tb(t_tb **tb_head, int fd)
{
	t_tb		*curr_node;
	t_tb		*new_node;

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

void			init_new_tb_node(t_tb *newnode, int fd)
{
	newnode->tb_arr = NULL;
	newnode->fd = fd;
	newnode->next = NULL;
	newnode->tb_end = 0;
	newnode->tb_size = BUFF_SIZE;
}

long			find_tb_newline(t_tb *tb_node, long index)
{
	int			i;

	i = -1;
	while (++i <= tb_node->tb_end)
		if ((tb_node->tb_arr)[i] == '\n')
			return (i - 1);
	return (-1);
}

int				tb_dynamic_add(t_tb *tb_node, char *buffer, ssize_t readlen)
{
	char		*temp;
	int			i;

	if (tb_node->tb_arr == NULL)
		if ((tb_node->tb_arr = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
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
		tb_node->tb_end += readlen;
	}
}

int				strcpy_n_alloc(char **line, t_tb *tb_node, int from, int to)
{

}
