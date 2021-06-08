/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:44:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/08 10:12:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		init_parsed(t_parsed **parsed)
{
	parsed[PARENT_INDEX] = (t_parsed *)malloc(sizeof(t_parsed));
	if (parsed[PARENT_INDEX] == NULL)
		exit(0);
	parsed[CHILD_INDEX] = (t_parsed *)malloc(sizeof(t_parsed));
	if (parsed[CHILD_INDEX] == NULL)
		exit(0);
	return (1);
}

int		parse_argument_vector(char **argv, t_parsed **parsed)
{
	char	**splitted_in;
	char	**splitted_out;

	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		exit(0);
	splitted_in = ft_split(argv[2], ' ');
	if (!splitted_in || !splitted_in[0])
		exit(0);
	splitted_out = ft_split(argv[4], ' ');
	if (!splitted_out || !splitted_out[0])
		exit(0);
	parsed[PARENT_INDEX]->file = argv[1];
	parsed[PARENT_INDEX]->cmd = splitted_in[0];
	parsed[PARENT_INDEX]->argv = splitted_in + 1;
	parsed[PARENT_INDEX]->envp = NULL;
	parsed[PARENT_INDEX]->cmd_path = NULL;
	parsed[CHILD_INDEX]->file = argv[3];
	parsed[CHILD_INDEX]->cmd = splitted_in[0];
	parsed[CHILD_INDEX]->argv = splitted_in + 1;
	parsed[CHILD_INDEX]->envp = NULL;
	parsed[CHILD_INDEX]->cmd_path = NULL;
}

int		is_valid_path(t_parsed **parsed)
{
	int		child_fd;
	int		parent_fd;

	child_fd = open(parsed[CHILD_INDEX]->file, O_RDONLY);
	parent_fd = open(parsed[PARENT_INDEX]->file, O_RDONLY);
	if (child_fd == -1 || parent_fd == -1)
	{
		close(child_fd);
		close(parent_fd);
		return (0);
	}
	close(child_fd);
	close(parent_fd);
	return (1);
}

int		is_valid_cmd(t_parsed **parsed)
{
	char	*joined;
	int		rep;
	char	*path[5];
	int		fd;
	int		i;

	path[0] = "/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/usr/local/bin";
	path[3] = "/usr/sbin/";
	path[4] = "/sbin/";
	rep = 5;
	i = 2;
	while (--i >= 0)
	{
		while (--rep >= 0)
		{
			joined = ft_strjoin(path[rep], parsed[PARENT_INDEX]->cmd);
			fd = open(joined, O_RDONLY);
			if (fd >= 0)
			{
				close(fd);
				parsed[PARENT_INDEX]->cmd_path;
				free(joined);
				break;
			}
			close(fd);
			free(joined);
		}
	}
	if (!parsed[PARENT_INDEX]->cmd_path || !parsed[CHILD_INDEX]->cmd_path)
		return (0);
	else
		return (1);
}
