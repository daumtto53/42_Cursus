#include "parse.h"

void	identifier_r(t_conf *conf, int fd, char **splitstr, char *id)
{
	if (ft_strncmp(id, "R", 1) == 0)
	{
		conf->resolution_w = ft_atoi(splitstr[1]);
		conf->resolution_h = ft_atoi(splitstr[2]);
		conf->complete_input |=  (RESOLUTION_H | RESOLUTION_W);
	}
}

int		identifier_fc(t_conf *conf, int fd, char **splitstr, char *id)
{
	char	**colorstr;

	if (ft_strncmp(id, "F", 1) == 0)
	{
		colorstr = ft_split(splitstr[1], ',');
		if (!colorstr)
			return (-1);
		conf->color_floor = (ft_atoi(colorstr[0]) << RGB_R_OP);
		conf->color_floor = (ft_atoi(colorstr[1]) << RGB_G_OP);
		conf->color_floor = (ft_atoi(colorstr[2]) << RGB_B_OP);
		conf->complete_input |= (COLOR_FLOOR);
		ft_split_free(colorstr);
	}
	if (ft_strncmp(id, "C", 1) == 0)
	{
		colorstr = ft_split(splitstr[1], ',');
		if (!colorstr)
			return (-1);
		conf->color_floor = (ft_atoi(colorstr[0]) << RGB_R_OP);
		conf->color_floor = (ft_atoi(colorstr[1]) << RGB_G_OP);
		conf->color_floor = (ft_atoi(colorstr[2]) << RGB_B_OP);
		conf->complete_input |= (COLOR_FLOOR);
		ft_split_free(colorstr);
	}
	return (1);
}

int		identifier_nwe(t_conf *conf, int fd, char **splitstr, char *id)
{
	char	*dup;

	dup = ft_strdup(splitstr[1]);
	if (!dup)
		return (-1);
	if (ft_strncmp(id, "NO", 2) == 0)
	{
		conf->tex_path_no = dup;
		conf->complete_input |= (TEX_PATH_NO);
	}
	if (ft_strncmp(id, "WE", 2) == 0)
	{
		conf->tex_path_s = dup;
		conf->complete_input |= (TEX_PATH_WE);
	}
	if (ft_strncmp(id, "EA", 2) == 0)
	{
		conf->tex_path_s = dup;
		conf->complete_input |= (TEX_PATH_EA);
	}
	return (1);
}

int		identifier_es(t_conf *conf, int fd, char **splitstr, char *id)
{
	char	*dup;

	dup = ft_strdup(splitstr[1]);
	if (!dup)
		return (-1);
	if (ft_strncmp(id, "SO", 2) == 0)
	{
		conf->tex_path_s = dup;
		conf->complete_input |= (TEX_PATH_SO);
	}
	else if (ft_strncmp(id, "S", 1) == 0)
	{
		conf->tex_path_so = dup;
		conf->complete_input |= (TEX_PATH_S);
	}
	return (1);
}
