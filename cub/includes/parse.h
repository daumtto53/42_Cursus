#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "../gnl/includes/get_next_line.h"

# define MAP			1
# define RESOLUTION_H	1 << 1
# define RESOLUTION_W	1 << 2
# define RGB_FLOOR		1 << 3
# define RGB_CEIL		1 << 4
# define TEX_PATH_NO	1 << 5
# define TEX_PATH_WE	1 << 6
# define TEX_PATH_SO	1 << 7
# define TEX_PATH_EA	1 << 8
# define TEX_PATH_S		1 << 9
# define RGB_R_OP		1 << 15
# define RGB_G_OP		1 << 7
# define RGB_B_OP		0
# define COMPLETE_INPUT	0x3FE

typedef struct	s_dynamic_map
{
	char	**map;
	int		size;
	int		len;
}				t_dynamic_map;

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

//provided
typedef struct s_conf
{
	int				complete_input;
	unsigned int	resolution_h;
 	unsigned int	resolution_w;
	unsigned int	color_floor;
	unsigned int	color_ceil;
	char			*tex_path_no;
	char			*tex_path_we;
	char			*tex_path_so;
	char			*tex_path_ea;
	char			*tex_path_s;
	t_dynamic_map	dyn;
	unsigned int	map_h;
	unsigned int	map_w;
	unsigned int	posx;
	unsigned int	posy;
	char			dir;
}				t_conf;

int		open_conf_cub(char **argv);
int		is_argc_argv_vaild(int argc, char **argv);

int		parse_identifier(t_conf *conf, int fd, char **splitstr);

int		parse_conf_cub(int argc, char **argv, t_conf *conf);

void		print_conf(t_conf *conf);

int			parse_map(t_conf *conf, int fd);

int			is_valid_map(t_conf *conf);

int		validation_check_dfs(t_conf *conf);

void	parse_error_cleaner(t_conf *conf);

void	free_all_ptr(char **splitstr, char *str);

#endif
