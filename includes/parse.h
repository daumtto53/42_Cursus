/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:51:35 by mchun             #+#    #+#             */
/*   Updated: 2021/03/25 12:23:07 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "../gnl/includes/get_next_line.h"

# define MAP			1
# define RESOLUTION_H	2
# define RESOLUTION_W	4
# define RGB_FLOOR		8
# define RGB_CEIL		16
# define TEX_PATH_NO	32
# define TEX_PATH_WE	64
# define TEX_PATH_SO	128
# define TEX_PATH_EA	256
# define TEX_PATH_S		512
# define COMPLETE_INPUT	0x3FE

typedef struct			s_dynamic_map
{
	char				**map;
	int					size;
	int					len;
}						t_dynamic_map;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_conf
{
	int					complete_input;
	int					resolution_h;
	int					resolution_w;
	int					color_floor;
	int					color_ceil;
	char				*tex_path_no;
	char				*tex_path_we;
	char				*tex_path_so;
	char				*tex_path_ea;
	char				*tex_path_s;
	t_dynamic_map		dyn;
	int					map_h;
	int					map_w;
	double				posx;
	double				posy;
	char				dir;
}						t_conf;

int						open_conf_cub(char **argv);
int						is_argc_argv_vaild(int argc, char **argv);

int						parse_identifier(t_conf *conf, char **splitstr);

int						parse_conf_cub(int argc, char **argv, t_conf *conf);

void					print_conf(t_conf *conf);

int						parse_map(t_conf *conf, int fd);

int						is_valid_map(t_conf *conf);

int						validation_check_dfs(t_conf *conf);

void					parse_error_cleaner(t_conf *conf);

int						is_valid_map_element(t_conf *conf);

void					free_all_ptr(char **splitstr, char *str);
void					conf_pos_mediator(t_conf *conf);

#endif
