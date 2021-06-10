/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:46:27 by mchun             #+#    #+#             */
/*   Updated: 2021/06/10 15:11:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		redirect_in(t_parsed **parsed)
{
	int		fd;
	int		tempfd;

	fd = open(parsed[CHILD_INDEX]->file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(parsed[CHILD_INDEX]->file);
		return (0);
	}
	tempfd = dup2(fd, STDIN_FILENO);
	if (tempfd < 0)
		return (0);
	close(fd);
	return (1);
}

int		redirect_out(t_parsed **parsed)
{
	int		fd;
	int		tempfd;

	fd = open(parsed[PARENT_INDEX]->file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(parsed[PARENT_INDEX]->file);
		return (0);
	}
	tempfd = dup2(fd, STDOUT_FILENO);
	if (tempfd < 0)
		return (0);
	close(fd);
	return (1);
}

int		connect_pipe(int *pipe, int redirect_io)
{
	int		fd;

	fd = dup2(pipe[redirect_io], redirect_io);
	if (fd < 0)
		return (-1);
	close(pipe[0]);
	close(pipe[1]);
	return (1);
}

int		run_cmd(t_parsed **parsed, int index)
{
	int		execv_error;

	execv_error = execve(parsed[index]->cmd_path, \
							(char *const *)parsed[index]->argv, \
							(char *const *)parsed[index]->envp);
	if (execv_error == -1)
	{
		perror(parsed[index]->argv[0]);
		return (-1);
	}
	return (1);
}
