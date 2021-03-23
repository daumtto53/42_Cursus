/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:14:56 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 13:02:44 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	free_all_ptr(char **splitstr, char *str)
{
	free(str);
	ft_split_free(splitstr);
}

void	parse_error_cleaner(t_conf *conf)
{
	int		i;

	if (conf->tex_path_ea != NULL)
		free(conf->tex_path_ea);
	if (conf->tex_path_we != NULL)
		free(conf->tex_path_we);
	if (conf->tex_path_so != NULL)
		free(conf->tex_path_so);
	if (conf->tex_path_no != NULL)
		free(conf->tex_path_no);
	if (conf->tex_path_s != NULL)
		free(conf->tex_path_s);
	if (conf->dyn.map != NULL)
	{
		i = -1;
		while (conf->dyn.map[++i] != NULL)
			free(conf->dyn.map[i]);
		free(conf->dyn.map);
	}
}

void	conf_pos_mediator(t_conf *conf)
{
	double	axis_x;
	double	axis_y;

	axis_x = conf->map_w / 2;
	axis_y = conf->map_h / 2;
	if (conf->posx < axis_x)
		conf->posx += 0.5;
	else
		conf->posx -= 0.5;
	if (conf->posy < axis_y)
		conf->posy += 0.5;
	else
		conf->posy -= 0.5;
}
