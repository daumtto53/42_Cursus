#include <stdio.h>
#include "get_next_line.h"



int					get_next_line(int fd, char **line)
{
	static t_tb		**tb_head;
	t_tb			*tb_node;
	ssize_t			readlen;
	long			index;
	char			read_buff[BUFF_SIZE];

	line = NULL;
	tb_head = NULL;
	tb_node =  find_tb(tb_head, fd);
	index = 0;
	while ((index = find_tb_newline(tb_node, index)) < 0)
	{
		if ((readlen = read(tb_node->fd, read_buff, BUFF_SIZE)) == 0)
		{
			//tb_arr에서 newline을 찾는 와중에 tb_arr에는 newline이 없었고,
			break;
		}
	}

}
