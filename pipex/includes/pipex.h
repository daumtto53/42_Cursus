/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:42:59 by mchun             #+#    #+#             */
/*   Updated: 2021/06/11 13:31:33 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define PARENT_INDEX	0
# define CHILD_INDEX	1

typedef struct	s_parsed
{
	const char	*file;
	const char	*cmd;
	char const	**argv;
	char const	**envp;
	char		*cmd_path;
}				t_parsed;

int				init_parsed(t_parsed **parsed);
int				parse_argument_vector(char **argv, t_parsed **parsed);
int				is_valid_path(t_parsed **parsed);
int				is_valid_cmd(t_parsed **parsed, char **envp);

int				redirect_in(t_parsed **parsed);
int				redirect_out(t_parsed **parsed);
int				connect_pipe(int *pipe, int redirect_io);
int				run_cmd(t_parsed **parsed, int index);

#endif
