# include "./parse.h"

static int		is_valid(t_conf *conf, int **vis, t_point new, t_point parent)
{
	int		valid;
	char	**map;

	map = conf->dyn.map;

	valid = (0 <= new.x && new.x < conf->map_w && \
		0 <= new.y && new.y < conf->map_h) && \
		(map[new.y][new.x] == '1' || map[new.y][new.x] == 'a') && \
		!(parent.x == new.x && parent.y == new.y) && \
		(!vis[new.y][new.x] || map[new.y][new.x] == 'a');

	return (valid);
}

static int		dfs(t_conf *conf, int **visited, t_point point, t_point parent)
{
	const int	step_x[4] = {1, 0, -1, 0};
	const int	step_y[4] = {0, -1, 0, 1};
	int		i;
	t_point		new;


	visited[point.y][point.x] = 1;
	i = -1;
	while (++i < 4)
	{
		new.x = point.x + step_x[i];
		new.y = point.y + step_y[i];
		if (is_valid(conf, visited, new, parent))
		{
			printf("new y x: %d  %d\n", new.y, new.x);
			if (visited[new.y][new.x] == 1 && conf->dyn.map[new.y][new.x] == 'a')
				return (1);
			else
				if (dfs(conf, visited, new, point) == 1)
					return (1);
		}
	}
	return (0);
}

static int		find_first_xy(t_conf *conf, t_point *point)
{
	int		i;
	int		j;

	i = -1;
	while (++i < conf->map_h)
	{
		j = -1;
		while (++j < conf->map_w)
		{
			if (conf->dyn.map[i][j] == '1')
			{
				point->x = j;
				point->y = i;
				conf->dyn.map[i][j] = 'a';
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
	t_point point;
	t_point parent;
	int		i;
	int		**visited;


	if (find_first_xy(conf, &point) == 0)
		return (-1);

	visited =  create_visited_arr(conf);
	printf("initiating dfs\n");
	for (int k = 0; k < conf->map_h; k++)
	{
		for (int j = 0; j < conf->map_w; j++)
			printf("%c ", conf->dyn.map[k][j]);
		printf("\n");
	}
	parent.x = -1;
	parent.y = -1;
	i = dfs(conf, visited, point, parent);
	printf("%d\n\n", i);

	// if (i = dfs(conf, visited, x, y) == 1)
	// {
	// 	// for (int k = 0; k < conf->map_h; k++)
	// 	// {
	// 	// 	for (int p = 0; p < conf->map_w; p++)
	// 	// 		printf("%d ", visited[k][p]);
	// 	// 	printf("\n");
	// 	// }
	// 	return (1);
	// }
	// else
	// {
	// 	i = -1;
	// 	while (++i < conf->map_w)
	// 		free(visited[i]);
	// 	free(visited);
	// 	return (-1);
	// }
	return (-1);
}
