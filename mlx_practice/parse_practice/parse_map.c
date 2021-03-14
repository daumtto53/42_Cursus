#include "./parse.h"

static int		init_dyn_map(t_dynamic_map *dyn)
{
	dyn->len = 0;
	dyn->size = 2;
	dyn->map = (char **)calloc(dyn->size + 1, sizeof(char **));
	if (!dyn->map)
	{
		printf("dynamic map allocation error\n");
		return (-1);
	}
	dyn->map[dyn->size] = NULL;
	return (1);
}

static int		map_push_back(t_dynamic_map *dyn, char *line)
{
	char	**temp;
	int		i;

	if (dyn->len > dyn->size - 1)
	{
		temp = (char **)calloc(dyn->size * 2 + 1, sizeof(char **));
		if (!temp)
		{
			printf("dynamic map push_back allocation error\n");
			ft_split_free(dyn->map);
			return (-1);
		}
		i = -1;
		while (dyn->map[++i])
			temp[i] = dyn->map[i];
		dyn->size = dyn->size * 2;
		temp[dyn->size] = '\0';
		free(dyn->map);
		dyn->map = temp;
	}
	dyn->map[dyn->len++] = line;
	return (1);
}

int		parse_map(t_conf *conf, int fd)
{
	int		gnl;
	char	*str;

	str = NULL;
	if (init_dyn_map(&(conf->dyn)) == -1)
		return (-1);
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '\0')
		{
			free(str);
			continue;
		}
		if (map_push_back(&(conf->dyn), str) == -1)
		{
			free(str);
			return (-1);
		}
	}
	return (1);
}
