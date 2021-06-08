/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:46:27 by mchun             #+#    #+#             */
/*   Updated: 2021/06/08 14:45:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		redirect_in()
{

}

int		redirect_out()
{

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
