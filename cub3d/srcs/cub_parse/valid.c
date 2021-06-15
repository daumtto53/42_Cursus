/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:15:27 by mchun             #+#    #+#             */
/*   Updated: 2021/03/26 21:01:19 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	is_file_extension_cub(char *file_path)
{
	int		l;
	char	*f;

	f = file_path;
	l = ft_strlen(f);
	if (f[l - 4] == '.' && f[l - 3] == 'c' && f[l - 2] == 'u' && \
			f[l - 1] == 'b')
		return (1);
	return (0);
}

static int	is_argv_2_save(char **argv)
{
	int		is_valid;

	is_valid = 0;
	if (ft_strlen(argv[2]) == 6 && ft_strncmp("--save", argv[2], 6) == 0)
		is_valid = 1;
	return (is_valid);
}

int			is_argc_argv_vaild(int argc, char **argv)
{
	if (!(1 <= argc && argc <= 3))
	{
		printf("Error\nargument number error\n");
		return (0);
	}
	if (argv[1] == NULL)
	{
		printf("Error\nfile path argument error\n");
		return (0);
	}
	if (!is_file_extension_cub(argv[1]))
	{
		printf("Error\n1st argument file_extension not .cub\n");
		return (0);
	}
	if (argc == 3 && !is_argv_2_save(argv))
	{
		printf("Error\n2nd argument not '--save'\n");
		return (0);
	}
	return (1);
}

int			open_conf_cub(char **argv)
{
	int		conf_fd;

	conf_fd = open(argv[1], O_RDONLY);
	if (conf_fd < 0)
	{
		perror("Error\nopen error\n");
		return (-1);
	}
	return (conf_fd);
}
