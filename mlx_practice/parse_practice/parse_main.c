#include "parse.h"

static void	init_conf(t_conf *conf)
{
	conf->complete_input = 0;
	conf->color_ceil = 0;
	conf->color_floor = 0;
}

static int		parse_type(t_conf *conf, int fd)
{
	// 8개 파싱하고 맞는 정보가 들어오면 플래그 띄우기.
	char	*str;
	int		line_num;
	char	**splitstr;
	int		valid;

	line_num = -1;
	while (++line_num < 8)
	{
		valid = get_next_line(fd, &str);
		if (valid == -1)
		{
			//추후에 break걸어서 에러 처리 한번에 해줄 수 있을 듯?
			printf("parse_type() : get_next_line error\n");
			free(str);
			exit(0);
		}
		splitstr = ft_split(str, ' ');
		if (splitstr[0] == '\0')
		{
			line_num--;
			continue;
		}
		if (!splitstr)
		{
			printf("parse_type() : split error\n");
			exit(0);
		}
		valid = parse_identifier(conf, fd, splitstr);
		ft_split_free(splitstr);
		if (valid == -1)
		{
			printf("parse_type() : parse error\n");
			exit(0);
		}
	}
	return (1);
}

int		parse_map(t_conf *conf, int fd)
{
	// map parser; + map W H assigner
	init_map(conf, fd);

	// map valid check;
	if (!is_valid_map(&conf->map, fd))
	{
		//free map;
		// print invalid map error;
	}

}

static void	parse_conf(t_conf *conf, int fd)
{
	if (parse_type(conf, fd) == -1)
	{
		printf("parsing_error\n");
		exit(0);
	}
	if (conf->complete_input != COMPLETE_INPUT)
	{
		printf("complete_input : %#x\twrong identifier num\n", conf->complete_input);
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
	return (1);
}
