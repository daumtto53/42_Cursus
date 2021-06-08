/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:48:16 by mchun             #+#    #+#             */
/*   Updated: 2021/06/08 14:45:36 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		main(int argc, char **argv)
{
	pid_t		pid;
	t_parsed	*parsed[2];
	int			execv_error[2];
	int			status;

	if (!(argc == 5 && init_parsed(parsed) && \
			parse_argument_vector(argv, parsed) && is_valid_path(parsed)) && \
				is_valid_cmd(parsed))
		exit(0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		if (!(redirect_in() && connect_pipe()))
			exit(1);
		if (run_cmd(parsed, CHILD_INDEX) == -1)
			exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit(0);
	if (!(connect_pipe() && redirect_out()))
		exit(1);
	if (run_cmd(parsed, PARENT_INDEX) == -1)
		exit(1);
}
