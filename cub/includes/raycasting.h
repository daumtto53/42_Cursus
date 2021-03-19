#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
// epsilon
# include <float.h>

//perror(), stderror()
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "./parse.h"

#include <string.h>

# define TEXTURE_NUM 6
# define TEXTURE_W	64
# define TEXTURE_H	64

# define TEXTURE_WALL_0 0
# define TEXTURE_WALL_1 1
# define TEXTURE_WALL_2 2
# define TEXTURE_WALL_3 3
# define TEXTURE_FLOOR	4
# define TEXTURE_CEILING 5

# define WPRESSED	1
# define APRESSED	2
# define SPRESSED	4
# define DPRESSED	8
# define LEFTPRESSED 16
# define RIGHTPRESSED 32

/*(360 == 6.3) / 20s : x : 0.2s , x == 0.063*/
# define DELTATHETA 0.063

/* 1/60 * 5.0 */
# define MOVESPEED 0.03

// #define RIGHTDIR 1
// #define LEFTDIR -1

# define HIT 1

# define COLOR_FLOOR 0xb3ffc8
# define COLOR_CEILING 0xc4fff8

typedef enum e_cardinal
{
	north = 0,
	south,
	west,
	east
}			t_cardinal;

typedef struct	s_img
{
	void	*img_ptr;
	int		*img_buff;
	int		linelen;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct	s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	int		keypress_flag;
}				t_player;

typedef struct	s_map
{
	char	**map;
	int		map_w;
	int		map_h;
}				t_map;

/****** 모듈화 시키면 굳이 필요하지 않을지도? *****/
typedef struct	s_rayinfo
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		perpwalldist;
	double		deltadistx;
	double		deltadisty;
	t_cardinal	side;	//side can be 0, 1, 2, 3 in order of nswe
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			wall_x;
}				t_rayinfo;

typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*win;
	int			**tex_arr;
	int			tex_num;
	int			screen_x;
	int			screen_y;
	t_img		img;
	t_player	player;
	t_map		map;
	t_rayinfo	ray;
}				t_cub;

typedef struct	s_ceilfloor
{
	double	raydirx0;
	double	raydirx1;
	double	raydiry0;
	double	raydiry1;
	double	rowdistance;
	double	stepx;
	double	stepy;
	double	ceilfloorx;
	double	ceilfloory;
	int		cellx;
	int		celly;
	int		texx;
	int		texy;
	int		standardy;
}				t_ceilfloor;

int			comp_double(double dest, double src);
void		matrix_rotation_2d(double *x, double *y, double delta_tht);
double		get_wall_hit_ratio(t_cub *cub);
int			get_texture_mapping(int tex_x, double texpos);
double		func_deltadist(double raydir);

void	init_cub(t_cub *cub, t_conf *conf);

/*keypress functions*/
int		event_keypress(int keycode ,void *param);
int		event_keyrelease(int keycode, void *param);
int		event_destroy(void *param);
int		event_xicon(void *param);

// void	buff_drawer(t_cub *cub, int x, int y, unsigned int color);

void	take_action(t_cub *cub);

void	buff_drawer(t_cub *cub, int x, int y, unsigned int color);
void	draw_simple_floor_ceiling(t_cub *cub);
void	draw_img_line_textured(t_cub *cub, int screenx);

void	load_texture(t_cub *cub, t_conf *conf);

void	ceiling_floor_rayc(t_cub *cub);

int 	untextured_rayc(t_cub *cub, int argc);

void	free_cub_struct(t_cub *cub);

#endif
