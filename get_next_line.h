/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:41:42 by mchun             #+#    #+#             */
/*   Updated: 2021/01/11 17:34:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tb{
	char	*tb_arr;
	long	tb_size;
	long	tb_end;
	int		fd;
	t_tb	*next;
}				t_tb;

t_tb			*find_tb(t_tb **tb_head, int fd);
int				get_next_line(int fd, char **line);
long			find_tb_newline(t_tb *tb_node, long index);
char			*tb_dynamic_add(t_tb *tb_node, ssize_t readlen);
int				strcpy_n_alloc(char **line, t_tb tb_node, int from, int to);
void			move_back_n_cpy(t_tb tb_node, long index);

#endif
