/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:44:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/10 15:08:59 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int			init_parsed(t_parsed **parsed)
{
	parsed[PARENT_INDEX] = (t_parsed *)malloc(sizeof(t_parsed));
	if (parsed[PARENT_INDEX] == NULL)
		exit(0);
	parsed[CHILD_INDEX] = (t_parsed *)malloc(sizeof(t_parsed));
	if (parsed[CHILD_INDEX] == NULL)
		exit(0);
	return (1);
}

int			parse_argument_vector(char **argv, t_parsed **parsed)
{
	char	**splitted_in;
	char	**splitted_out;

	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		exit(0);
	splitted_in = ft_split(argv[2], ' ');
	if (!splitted_in || !splitted_in[0])
		exit(0);
	splitted_out = ft_split(argv[3], ' ');
	if (!splitted_out || !splitted_out[0])
		exit(0);
	parsed[PARENT_INDEX]->file = argv[4];
	parsed[PARENT_INDEX]->cmd = splitted_out[0];
	parsed[PARENT_INDEX]->argv = (const char **)splitted_out;
	parsed[PARENT_INDEX]->envp = NULL;
	parsed[PARENT_INDEX]->cmd_path = NULL;
	parsed[CHILD_INDEX]->file = argv[1];
	parsed[CHILD_INDEX]->cmd = splitted_in[0];
	parsed[CHILD_INDEX]->argv = (const char **)splitted_in;
	parsed[CHILD_INDEX]->envp = NULL;
	parsed[CHILD_INDEX]->cmd_path = NULL;
	return (1);
}

int			is_valid_path(t_parsed **parsed)
{
	int		child_fd;

	child_fd = open(parsed[CHILD_INDEX]->file, O_RDONLY);
	if (child_fd == -1)
	{
		perror(parsed[CHILD_INDEX]->file);
		close(child_fd);
		return (0);
	}
	close(child_fd);
	return (1);
}

static void	init_path_arr(char **path)
{
	path[0] = "/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/usr/local/bin/";
	path[3] = "/usr/sbin/";
	path[4] = "/sbin/";
}

int			is_valid_cmd(t_parsed **parsed)
{
	int		rep;
	char	*path[5];
	int		fd;
	int		i;

	init_path_arr(path);
	i = 2;
	while (--i >= 0)
	{
		rep = 5;
		while (--rep >= 0)
		{
			parsed[i]->cmd_path = ft_strjoin(path[rep], parsed[i]->cmd);
			fd = open(parsed[i]->cmd_path, O_RDONLY);
			if (fd >= 0)
			{
				close(fd);
				break ;
			}
			close(fd);
			free(parsed[i]->cmd_path);
		}
	}
	return (parsed[PARENT_INDEX]->cmd_path && parsed[CHILD_INDEX]->cmd_path);
}
