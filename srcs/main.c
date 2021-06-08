/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:48:16 by mchun             #+#    #+#             */
/*   Updated: 2021/06/08 21:53:52 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		main(int argc, char **argv)
{
	pid_t		pid;
	t_parsed	*parsed[2];
	int			execv_error[2];
	int			status;
	int			pipefd[2];

	if (!(argc == 5 && init_parsed(parsed) && \
			parse_argument_vector(argv, parsed) && is_valid_path(parsed) && \
				is_valid_cmd(parsed) && pipe(pipefd) != -1))
		exit(0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		if (!(redirect_in(parsed) != -1 && connect_pipe(pipefd, STDIN_FILENO) != -1))
			exit(1);
		if (run_cmd(parsed, CHILD_INDEX) == -1)
			exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit(0);
	if (!(redirect_out(parsed) && connect_pipe(pipefd, STDOUT_FILENO)))
		exit(1);
	if (run_cmd(parsed, PARENT_INDEX) == -1)
		exit(1);
}
