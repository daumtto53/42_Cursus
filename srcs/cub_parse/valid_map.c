/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:11:38 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 01:49:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	conf_map_max_h_w(t_conf *conf)
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
	conf->map_w += 2;
	conf->map_h += 2;
}

static char	**resize_map(t_conf *conf)
{
	char	**temp;
	int		i;

	temp = (char **)ft_calloc(conf->map_h + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	temp[conf->map_h] = NULL;
	i = -1;
	while (++i < conf->map_h)
	{
		temp[i] = (char *)ft_calloc(conf->map_w + 1, sizeof(char));
		if (!temp[i])
		{
			ft_split_free(temp);
			return (NULL);
		}
	}
	return (temp);
}

static void	init_map_data(t_conf *conf, char **dest_map, char **src_map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < conf->map_h)
	{
		j = -1;
		while (++j < conf->map_w)
			dest_map[i][j] = '+';
	}
	i = -1;
	while (src_map[++i])
	{
		j = -1;
		while (src_map[i][++j])
		{
			if (src_map[i][j] == ' ')
				dest_map[i + 1][j + 1] = '+';
			else
				dest_map[i + 1][j + 1] = src_map[i][j];
		}
	}
}

int			is_valid_map(t_conf *conf)
{
	char	**resized;

	conf_map_max_h_w(conf);
	resized = resize_map(conf);
	if (!resized)
		return (-1);
	init_map_data(conf, resized, conf->dyn.map);
	ft_split_free(conf->dyn.map);
	conf->dyn.map = resized;
	if (validation_check_dfs(conf) == -1)
		return (0);
	return (1);
}
