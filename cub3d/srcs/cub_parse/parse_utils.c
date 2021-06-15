/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:14:56 by mchun             #+#    #+#             */
/*   Updated: 2021/03/30 14:51:16 by mchun            ###   ########.fr       */
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

void	free_tex_path(t_conf *conf)
{
	free(conf->tex_path_ea);
	free(conf->tex_path_no);
	free(conf->tex_path_we);
	free(conf->tex_path_so);
	free(conf->tex_path_s);
}

void	conf_pos_mediator(t_conf *conf)
{
	conf->posx += 0.5;
	conf->posy += 0.5;
}
