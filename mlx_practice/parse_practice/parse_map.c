#include "./parse.h"

void	init_dyn_map(t_dynamic_map *dyn)
{
	dyn->len = 0;
	dyn->size = 1;
}

void	map_push_back(t_dynamic_map *dyn, char *line)
{
	char	**temp;
	int		i;

	if (dyn->len > dyn->size)
	{
		temp = (char **)calloc(dyn->size * 2, sizeof(char **));
		i = -1;
		while (++i < dyn->size)
			temp[i] = dyn->map[i];
		temp[dyn->size] = '\0';
		dyn->size = dyn->size * 2;
		free(dyn->map);
		dyn->len += 1;
		dyn->map = temp;
	}
	dyn->map[++dyn->len] = line;
}
