#include "../../includes/parse.h"

static void	init_conf(t_conf *conf)
{
	conf->complete_input = 0;
	conf->color_ceil = 0;
	conf->color_floor = 0;
	conf->tex_path_ea = NULL;
	conf->tex_path_no = NULL;
	conf->tex_path_we = NULL;
	conf->tex_path_so = NULL;
	conf->dyn.map = NULL;
	conf->tex_path_s = NULL;
}

static int		parse_type(t_conf *conf, int fd)
{
	char	*str;
	int		line_num;
	char	**splitstr;

	line_num = -1;
	while (++line_num < 8)
	{
		if (get_next_line(fd, &str) == -1)
			return (-1);
		splitstr = ft_split(str, ' ');
		if (!splitstr)
		{
			free(str);
			return (-1);
		}
		if (splitstr[0] == NULL)
		{
			line_num--;
			continue;
		}
		if (parse_identifier(conf, fd, splitstr) == -1)
			return (-1);
		ft_split_free(splitstr);
	}
	return (1);
}

// parse type && parse map
static void	parse_conf(t_conf *conf, int fd)
{
	if (parse_type(conf, fd) == -1)
	{
		parse_error_cleaner(conf);
		printf("parsing_error\n");
		exit(0);
	}
	if (conf->complete_input != COMPLETE_INPUT)
	{
		parse_error_cleaner(conf);
		printf("complete_input : %#x\twrong identifier num\n", conf->complete_input);
		exit(0);
	}
	if (parse_map(conf, fd) == -1)
	{
		parse_error_cleaner(conf);
		printf("map parsing error\n");
		exit(0);
	}
}

void	parse_error_cleaner(t_conf *conf)
{
	int		i;

	if (conf->tex_path_ea != NULL)
		free(conf->tex_path_ea);
	if (conf->tex_path_we != NULL)
		free(conf->tex_path_we);
	if (conf->tex_path_so != NULL)
		free(conf->tex_path_so);
	if (conf->tex_path_no != NULL)
		free(conf->tex_path_no);
	if (conf->tex_path_s != NULL)
		free(conf->tex_path_s);
	if (conf->dyn.map != NULL)
	{
		i = -1;
		while (conf->dyn.map[++i] != NULL)
			free(conf->dyn.map[i]);
		free(conf->dyn.map);
	}
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
	if (!is_valid_map(conf))
	{
		printf("invalid map error\n");
		parse_error_cleaner(conf);
		exit(0);
	}
	//bmp_logic(); when argc == 3
	return (1);
}
