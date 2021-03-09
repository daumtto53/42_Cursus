#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
// epsilon
# include <float.h>

//perror(), stderror()
# include <stdio.h>
# include <errno.h>

# include <stdlib.h>
# include "../../../mlx/mlx.h"

#include <string.h>

# define SCREEN_W	800
# define SCREEN_H	600
# define MAP_W		24
# define MAP_H		24

# define WPRESSED	1
# define APRESSED	2
# define SPRESSED	4
# define DPRESSED	8
# define LEFTPRESSED 16
# define RIGHTPRESSED 32

/*(360 == 6.3) / 5s : x : 0.2s , x == 0.25*/
# define DELTATHETA 0.063

/* 1/60 * 5.0 */
# define MOVESPEED 0.02

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
	char	map[MAP_H][MAP_W];
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
}				t_rayinfo;

typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
	t_rayinfo	ray;
}				t_cub;

int		comp_double(double dest, double src);
void	matrix_rotation_2d(double *x, double *y, double delta_tht);

void	init_cub(t_cub *cub);

/*keypress functions*/
int		event_keypress(int keycode ,void *param);
int		event_keyrelease(int keycode, void *param);
int		event_destroy(void *param);
int		event_xicon(void *param);

void	buff_drawer(t_cub *cub, int x, int y, unsigned int color);

void	take_action(t_cub *cub, int map[MAP_H][MAP_W]);

void	draw_simple_floor_ceiling(t_cub *cub);

#endif
