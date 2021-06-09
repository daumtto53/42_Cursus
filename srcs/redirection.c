/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:46:27 by mchun             #+#    #+#             */
/*   Updated: 2021/06/09 16:01:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		redirect_in(t_parsed **parsed)
{
	int		fd;
	int		tempfd;

	printf("REDIRECT_IN\n");
	fd = open(parsed[CHILD_INDEX]->file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	tempfd = dup2(fd, STDIN_FILENO);
	if (tempfd < 0)
		return (-1);
	close(fd);
	return (1);
}

int		redirect_out(t_parsed **parsed)
{
	int		fd;
	int		tempfd;

	printf("REDIRECT_OUT\n");
	fd = open(parsed[PARENT_INDEX]->file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	tempfd = dup2(fd, STDOUT_FILENO);
	if (tempfd < 0)
		return (-1);
	close(fd);
	return (1);
}

int		connect_pipe(int *pipe, int redirect_io)
{
	int		fd;

	printf("CONNECT_PIPE\n");
	fd = dup2(pipe[redirect_io], redirect_io);
	printf("fd : %d\n", fd);
	if (fd < 0)
		return (-1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	return (1);
}

int		run_cmd(t_parsed **parsed, int index)
{
	int		execv_error;

	printf("RUN_CMD\n");
	execv_error = execve(parsed[index]->cmd_path, (char *const *)parsed[index]->argv, (char *const *)parsed[index]->envp);
	if (execv_error == -1)
		return (-1);
	return (1);
}
