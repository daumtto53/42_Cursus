#include "parse.h"

static void	init_conf(t_conf *conf)
{
	conf->complete_input = 0;
}

static int		parse_identifier(t_conf *conf, int fd, char **splitstr)
{
	char	*identifier;
	char	**colorstr;
	int		valid;

	identifier = splitstr[0];
	identifier_r(conf, fd, splitstr, identifier);
	valid = identifier_fc(conf, fd, splitstr, identifier);
	if (valid == -1)
		return (-1);
	valid = identifier_nwses(conf, fd, splitstr, identifier);
	if (valid == -1)
		return (-1);
	return (1);
}

static int		parse_type(t_conf *conf, int fd)
{
	// 8개 파싱하고 맞는 정보가 들어오면 플래그 띄우기.
	char	*str;
	int		line_num;
	char	**splitstr;
	int		valid;

	line_num = -1;
	while (++line_num < 8 && !get_next_line(fd, &str))
	{
		splitstr = ft_split(str, ' ');
		if (!splitstr)
		{
			printf("parse type : split error\n");
			exit(0);
		}
		valid = parse_identifier(conf, fd, splitstr);
		ft_split_free(splitstr);
		if (valid == -1)
		{
			printf("parse error\n");
			exit(0);
		}
	}
	return (1);
}

// int		parse_map(t_conf *conf, int fd)
// {

// }

static void	parse_conf(t_conf *conf, int fd)
{
	if (parse_type(conf, fd) == -1)
	{
		printf("parsing_error\n");
		exit(0);
	}
	if (conf->complete_input != COMPLETE_INPUT)
	{
		printf("wrong identifier num\n");
		exit(0);
	}
	// if (parse_map(conf, fd) == -1)
	// {
	// 	printf("map parsing error\n");
	// 	delete_map(conf, fd);
	// 	exit(0);
	// }
}

int		parse_conf_cub(int argc, char **argv, t_conf *conf)
{
	int		conf_fd;

	if (!is_argc_argv_vaild(argc, argv))
		exit(0);
	conf_fd = open_conf_cub(argv);
	if (conf_fd < 0)
		exit(0);
	init_conf(conf);
	parse_conf(conf, conf_fd);
	//handle_bmp
	// if (argv == 3)
	// {
	// 	printf("add bmp logic\n");
	// }

}
