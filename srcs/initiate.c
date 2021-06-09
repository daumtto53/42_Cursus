/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:44:47 by mchun             #+#    #+#             */
/*   Updated: 2021/06/09 15:50:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		init_parsed(t_parsed **parsed)
{
	#ifdef DBG
		printf("INIT_PARSED\n");
	#endif
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
	splitted_out = ft_split(argv[3], ' ');
	if (!splitted_out || !splitted_out[0])
		exit(0);
	parsed[PARENT_INDEX]->file = argv[4];
	parsed[PARENT_INDEX]->cmd = splitted_out[0];
	parsed[PARENT_INDEX]->argv = (const char **)splitted_in + 1;
	parsed[PARENT_INDEX]->envp = NULL;
	parsed[PARENT_INDEX]->cmd_path = NULL;
	parsed[CHILD_INDEX]->file = argv[1];
	parsed[CHILD_INDEX]->cmd = splitted_in[0];
	parsed[CHILD_INDEX]->argv = (const char **)splitted_in + 1;
	parsed[CHILD_INDEX]->envp = NULL;
	parsed[CHILD_INDEX]->cmd_path = NULL;
	#ifdef DBG
		printf("PARSE_ARGUEMNT_VECTOR\n");
		printf("input _ file : %s\n cmd : %s\n", parsed[CHILD_INDEX]->file, parsed[CHILD_INDEX]->cmd);
		printf("output _ file : %s\n cmd : %s\n", parsed[PARENT_INDEX]->file, parsed[PARENT_INDEX]->cmd);
	#endif
	return (1);
}

int		is_valid_path(t_parsed **parsed)
{
	int		child_fd;

	#ifdef DBG
		printf("IS_VALID_PATH\n");
	#endif
	child_fd = open(parsed[CHILD_INDEX]->file, O_RDONLY);
	//Output 디렉토리가 없는 디렉토리일 경우..?
	printf("input_f : %s, output_f : %s\n", parsed[CHILD_INDEX]->file, parsed[PARENT_INDEX]->file);
	if (child_fd == -1)
	{
		close(child_fd);
		return (0);
	}
	#ifdef DBG
		printf("child_fd : %d\n", child_fd);
	#endif
	close(child_fd);
	return (1);
}

int		is_valid_cmd(t_parsed **parsed)
{
	char	*joined;
	int		rep;
	char	*path[5];
	int		fd;
	int		i;
	#ifdef DBG
		printf("IS_VALID_CMD\n");
	#endif
	path[0] = "/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/usr/local/bin/";
	path[3] = "/usr/sbin/";
	path[4] = "/sbin/";
	i = 2;
	while (--i >= 0)
	{
		rep = 5;
		while (--rep >= 0)
		{
			joined = ft_strjoin(path[rep], parsed[i]->cmd);
			printf("i : %d, joined : %s\n", i, joined);
			fd = open(joined, O_RDONLY);
			if (fd >= 0)
			{
				close(fd);
				parsed[i]->cmd_path = joined;
				#ifdef DBG
					printf("joined : %s\n", joined);
				#endif
				joined = NULL;
				break;
			}
			close(fd);
			free(joined);
		}
	}
	printf("input_file cmd_path1 : %s\toutput_file cmd_path2 : %s\n", parsed[CHILD_INDEX]->cmd_path, parsed[PARENT_INDEX]->cmd_path);
	if (!parsed[PARENT_INDEX]->cmd_path || !parsed[CHILD_INDEX]->cmd_path)
		return (0);
	else
		return (1);

}
