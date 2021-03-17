#include "./parse.h"

static int		is_file_extension_cub(char *file_path)
{
	char	*cub;

	cub = ft_strnstr(file_path, ".cub", ft_strlen(file_path));
	if (cub == NULL)
	{
		printf("file extension error\n");
		return (0);
	}
	return (1);
}

static int		is_argv_2_save(char **argv)
{
	int		is_valid;
	char	*argv_2;

	is_valid = 1;
	argv_2 = ft_strnstr(argv[2], "--save", ft_strlen("--save"));
	if (argv_2 == NULL)
		is_valid = 0;
	return (is_valid);
}

int		is_argc_argv_vaild(int argc, char **argv)
{
	int		is_error;

	is_error = 0;
	if (!(1 <= argc && argc <= 3))
	{
		printf("argument number error\n");
		return (0);
	}
	if (argv[1] == NULL)
	{
		printf("file path argument error\n");
		is_error = 1;
	}
	if (!is_file_extension_cub(argv[1]))
	{
		printf("1st argument file_extension not .cub\n");
		is_error = 1;
	}
	if (argc == 3 && !is_argv_2_save(argv))
	{
		printf("2nd argument not '--save'\n");
		is_error = 1;
	}
	return (!is_error);
}

int		open_conf_cub(char **argv)
{
	int		conf_fd;

	conf_fd = open(argv[1], O_RDONLY);
	if (conf_fd < 0)
	{
		perror("open error\n");
		return (-1);
	}
	return (conf_fd);
}
