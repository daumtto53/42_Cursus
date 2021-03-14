# include "parse.h"


static void		conf_map_max_h_w(t_conf *conf)
{
	int		i;
	int		arr_len;

	conf->map_h = conf->dyn.len;
	conf->map_w = 0;
	i = -1;
	arr_len = 0;
	while (++i < conf->map_h)
	{
		arr_len = ft_strlen(conf->dyn.map[i]);
		if (conf->map_w < arr_len)
			conf->map_w = arr_len;
	}
}

static char		**resize_map(t_conf *conf)
{
	char	**temp;
	int		i;

	temp = (char **)calloc(conf->map_h + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < conf->map_h)
	{
		temp[i] = (char *)calloc(conf->map_w + 1, sizeof(char));
		if (!temp[i])
		{
			ft_split_free(temp);
			return (NULL);
		}
	}
	return (temp);
}

static void	copy_map_data(char **dest_map, char **src_map)
{
	int		i;
	int		j;

	i = -1;
	while (dest_map[++i])
	{
		j = -1;
		while (src_map[i][++j])
			dest_map[i][j] = src_map[i][j];
	}
}

static void		print_map(char **map)
{
	int		i;

	i = 0;
	printf("print resized : map()\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int		is_valid_map(t_conf *conf)
{
	char	**resized;

	conf_map_max_h_w(conf);
	resized = resize_map(conf);
	if (!resized)
		return (-1);
	copy_map_data(resized, conf->dyn.map);
	print_map(resized);
	validation_check_dfs(resized);
	return (1);
}
