/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:14:02 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 12:11:01 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	identifier_r(t_conf *conf, char **splitstr, char *id)
{
	if (ft_strncmp(id, "R", 1) == 0)
	{
		conf->resolution_w = ft_atoi(splitstr[1]);
		conf->resolution_h = ft_atoi(splitstr[2]);
		conf->complete_input |= (RESOLUTION_H | RESOLUTION_W);
	}
}

static int	identifier_fc(t_conf *conf, char **splitstr, char *id)
{
	char	**str;

	if (ft_strncmp(id, "F", 1) == 0)
	{
		str = ft_split(splitstr[1], ',');
		if (!str)
			return (-1);
		conf->color_floor |= ((ft_atoi(str[0]) << 16) | \
			(ft_atoi(str[1]) << 8) | (ft_atoi(str[2])));
		conf->complete_input |= (RGB_FLOOR);
		ft_split_free(str);
	}
	if (ft_strncmp(id, "C", 1) == 0)
	{
		str = ft_split(splitstr[1], ',');
		if (!str)
			return (-1);
		conf->color_ceil |= ((ft_atoi(str[0]) << 16) | \
			(ft_atoi(str[1]) << 8) | (ft_atoi(str[2])));
		conf->complete_input |= (RGB_CEIL);
		ft_split_free(str);
	}
	return (1);
}

static int	identifier_nwe(t_conf *conf, char **splitstr, char *id)
{
	char	*dup;

	dup = NULL;
	if (ft_strncmp(id, "NO", 2) == 0 || ft_strncmp(id, "WE", 2) == 0 || \
		ft_strncmp(id, "EA", 2) == 0)
		dup = ft_strdup(splitstr[1]);
	if (ft_strncmp(id, "NO", 2) == 0)
	{
		conf->tex_path_no = dup;
		conf->complete_input |= (TEX_PATH_NO);
	}
	if (ft_strncmp(id, "WE", 2) == 0)
	{
		conf->tex_path_we = dup;
		conf->complete_input |= (TEX_PATH_WE);
	}
	if (ft_strncmp(id, "EA", 2) == 0)
	{
		conf->tex_path_ea = dup;
		conf->complete_input |= (TEX_PATH_EA);
	}
	return (1);
}

static int	identifier_ss(t_conf *conf, char **splitstr, char *id)
{
	char	*dup;

	dup = NULL;
	if (ft_strncmp(id, "SO", 2) == 0 || ft_strncmp(id, "S", 1) == 0)
	{
		dup = ft_strdup(splitstr[1]);
		if (!dup)
			return (-1);
	}
	if (ft_strncmp(id, "SO", 2) == 0)
	{
		conf->tex_path_so = dup;
		conf->complete_input |= (TEX_PATH_SO);
	}
	else if (ft_strncmp(id, "S", 1) == 0)
	{
		conf->tex_path_s = dup;
		conf->complete_input |= (TEX_PATH_S);
	}
	return (1);
}

int			parse_identifier(t_conf *conf, char **splitstr)
{
	char	*identifier;
	int		valid;

	identifier = splitstr[0];
	identifier_r(conf, splitstr, identifier);
	valid = identifier_fc(conf, splitstr, identifier);
	if (valid == -1)
		return (-1);
	valid = identifier_nwe(conf, splitstr, identifier);
	if (valid == -1)
		return (-1);
	valid = identifier_ss(conf, splitstr, identifier);
	if (valid == -1)
		return (-1);
	return (1);
}
