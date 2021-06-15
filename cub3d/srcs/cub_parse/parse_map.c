/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:13:11 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 12:26:17 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	init_dyn_map(t_dynamic_map *dyn)
{
	dyn->len = 0;
	dyn->size = 2;
	dyn->map = (char **)ft_calloc(dyn->size + 1, sizeof(char **));
	if (!dyn->map)
	{
		printf("Error\ndynamic map allocation error\n");
		return (-1);
	}
	dyn->map[dyn->size] = NULL;
	return (1);
}

static int	map_push_back(t_dynamic_map *dyn, char *line)
{
	char	**temp;
	int		i;

	if (dyn->len > dyn->size - 1)
	{
		temp = (char **)ft_calloc(dyn->size * 2 + 1, sizeof(char **));
		if (!temp)
		{
			printf("Error\ndynamic map push_back allocation error\n");
			return (-1);
		}
		i = -1;
		while (dyn->map[++i])
			temp[i] = dyn->map[i];
		dyn->size = dyn->size * 2;
		temp[dyn->size] = NULL;
		free(dyn->map);
		dyn->map = temp;
	}
	dyn->map[dyn->len++] = line;
	return (1);
}

int			parse_map(t_conf *conf, int fd)
{
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
			parse_error_cleaner(conf);
			free(str);
			return (-1);
		}
	}
	if (str[0] == '\0')
		free(str);
	return (1);
}
