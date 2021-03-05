#ifndef TEST_H
# define TEST_H

# include <mlx.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}				t_mlx;

#endif
