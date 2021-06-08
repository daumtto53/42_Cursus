/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:46:27 by mchun             #+#    #+#             */
/*   Updated: 2021/06/08 21:33:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		redirect_in(t_parsed **parsed)
{
	int		fd;

	fd = open(parsed[CHILD_INDEX]->file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int		redirect_out(t_parsed **parsed)
{
	int		fd;

	fd = open(parsed[PARENT_INDEX]->file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

int		connect_pipe()
{

}

int		run_cmd(t_parsed **parsed, int index)
{
	int		execv_error;

	execv_error = execve(parsed[index]->cmd, parsed[index]->argv, parsed[index]->envp);
	if (execv_error == -1)
		return (-1);
}
