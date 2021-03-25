#include "../../includes/parse.h"

int			is_valid_map_element(t_conf *conf)
{
	int		i;
	int		j;
	char	**map;

	map = conf->dyn.map;
	i = -1;
	while (++i < conf->map_h)
	{
		j = -1;
		while (++j < conf->map_w)
			if (!((map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E') || \
				(map[i][j] >= '0' && map[i][j] <= '2') || map[i][j] == '+'))
				return (0);
	}
	return (1);
}
