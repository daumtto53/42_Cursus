# include "./parse.h"

static int		is_valid(t_conf *conf, int **visited, int x, int y)
{
	int		valid;
	char	**map;

	valid = (0 <= x && x < conf->map_w && 0 <= y && y < conf->map_h);
	valid = valid && conf->dyn.map[y][x] != '1';
	return (valid);
}

static int		dfs(t_conf *conf, int **visited, int x, int y)
{
	const int	step_x[4] = {1, 0, -1, 0};
	const int	step_y[4] = {0, -1, 0, 1};
	int		i;
	int		newx;
	int		newy;

	if (conf->dyn.map[y][x] == '+')
		return (0);
	visited[y][x] = 1;
	i = -1;
	while (++i < 4)
	{
		newx = x + step_x[i];
		newy = y + step_y[i];
		if (is_valid(conf, visited, newx, newy) && !visited[newy][newx])
		{
			if (dfs(conf, visited, newx, newy) == 0)
				return (0);
		}
	}
	return (1);
}

static int		find_pos(t_conf *conf)
{
	int		i;
	int		j;
	char	**map = conf->dyn.map;

	i = -1;
	while (++i < conf->map_h)
	{
		j = -1;
		while (++j < conf->map_w)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				conf->posx = j;
				conf->posy = i;
				conf->dir = map[i][j];
				return (1);
			}
		}
	}
	return (0);
}

static int		**create_visited_arr(t_conf *conf)
{
	int		i;
	int		j;
	int		**visited;

	visited = (int **)calloc(conf->map_h, sizeof(int *));
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < conf->map_h)
	{
		visited[i] = (int *)calloc(conf->map_w, sizeof(int *));
		if (!visited[i])
		{
			j = -1;
			while (++j < i)
				free(visited[j]);
			free(visited);
			return (NULL);
		}
		j = -1;
		while (++j < conf->map_w)
			visited[i][j] = 0;
	}
	return (visited);
}


int		validation_check_dfs(t_conf *conf)
{
	int		i;
	int		**visited;

	visited =  create_visited_arr(conf);
	if (!visited)
		return (-1);
	if (find_pos(conf) == 0)
	{
		i = -1;
		while (++i < conf->map_h)
			free(visited[i]);
		free(visited);
		return (-1);
	}
	if (dfs(conf, visited, conf->posx, conf->posy) == 0)
	{
		i = -1;
		while (++i < conf->map_h)
			free(visited[i]);
		free(visited);
		return (-1);
	}
	return (1);
}
