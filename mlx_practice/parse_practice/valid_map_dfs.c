# include "./parse.h"

int		dfs(char **map, char **visited, int x, int y)
{
	const int	step_x[4] = {1, -1, 0, 0};
	const int	step_y[4] = {0, 0, 1, -1};
	int		i;

	if (map[y][x] == 'a' && visited[y][x])
		return (1);
	if (visited[y][x])
		return (0);
	visited[y][x] = 1;
	i = -1;
	while (++i < 4)
	{
		// 배열의 크기를 넘어가는 x y 가 아닌지 확인 && coordinate가 1인지 확인하고 넘어가기.
		if (is_valid_coord(map, x + step_x[i], y + step_y[i]) &&\
			 is_coord_1(map, x + step_x[i], y + step_y[i]))
		{
			if (dfs(map, visited, x + step_x[i], y + step_y[i]) == 1)
				return (1);
		}
	}
	return (0);
}

int		validation_check_dfs(char **map)
{
	find_first_xy()
	map[y][x] = 'a';
	char **visited =  create_visted_arr(map);
	if (dfs(map, visited, x, y) == 1)
	return (1);
	else
	return (0);
}
