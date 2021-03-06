#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../mlx/mlx.h"

# define SCREENWIDTH	800
# define SCREENHEIGHT	600
# define MAPWIDTH		20
# define MAPHEIGHT		20

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
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		moveflag;
}				t_player;

typedef struct	s_map
{
	int		**map;
	int		map_w;
	int		map_h;
}				t_map;

typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_player	player;
}				t_cub;

#endif
