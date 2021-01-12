/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:41:42 by mchun             #+#    #+#             */
/*   Updated: 2021/01/12 00:00:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_tb{
	char			*tb_arr;
	long			tb_size;
	long			tb_end;
	int				fd;
	struct s_tb		*next;
}					t_tb;

int				get_next_line(int fd, char **line);
t_tb			*find_tb(t_tb **tb_head, int fd);
void			init_new_tb_node(t_tb *newnode, int fd);
long			find_tb_newline(t_tb *tb_node, long index);
int				tb_dynamic_add(t_tb *tb_node, char *buffer, ssize_t readlen);
int				strcpy_n_alloc(char **line, t_tb *tb_node, int from, int to);
void			move_tb_arr_n_cpy(t_tb *tb_node, long index);

#endif
