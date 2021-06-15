/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:48:16 by mchun             #+#    #+#             */
/*   Updated: 2021/06/11 13:32:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	begin_main(int argc, t_parsed **parsed, char **argv, int *pipefd, char **envp)
{
	if (argc != 5)
		exit(0);
	if (init_parsed(parsed) != 1)
		exit(0);
	if (parse_argument_vector(argv, parsed) != 1)
		exit(0);
	if (is_valid_path(parsed) != 1)
		exit(0);
	if (is_valid_cmd(parsed, envp) != 1)
		exit(0);
	if (pipe(pipefd) == -1)
		exit(0);
}

int			main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	t_parsed	*parsed[2];
	int			status;
	int			pipefd[2];

	begin_main(argc, parsed, argv, pipefd, envp);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		if (!(redirect_in(parsed) && connect_pipe(pipefd, CHILD_INDEX) != -1))
			exit(1);
		if (run_cmd(parsed, CHILD_INDEX) == -1)
			exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 0)
		exit(1);
	if (!(redirect_out(parsed) && connect_pipe(pipefd, PARENT_INDEX) != -1))
		exit(1);
	if (run_cmd(parsed, PARENT_INDEX) == -1)
		exit(1);
	return (0);
}
