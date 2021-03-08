#include "../includes/raycasting.h"
#include "../includes/debug.h"

static void	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
	{
		perror("mlx_init");
		exit(1);
	}
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_H, SCREEN_W, "TITLE");
	if (cub->win == NULL)
	{
		perror("mlx_new_window");
		exit(1);
	}
}

static void	init_img(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, SCREEN_W, SCREEN_H);
	if (cub->img.img_ptr == NULL)
	{
		perror("mlx_new_image");
		exit(1);
	}
	cub->img.img_buff = \
		(int *)mlx_get_data_addr(cub->img.img_ptr, \
			&cub->img.bpp, &cub->img.linelen, &cub->img.endian);
	if (cub->img.img_ptr == NULL)
	{
		perror("mlx_get_data_addr");
		exit(1);
	}
	cub->img.img_h = SCREEN_H;
	cub->img.img_w = SCREEN_W;
}

static void	init_player(t_cub *cub)
{
	// When parsed, needs pos, dir, plane modified.
	cub->player.dirx = 1.0;
	cub->player.diry = -1.0;
	cub->player.posx = 22.0;
	cub->player.posy = 11.5;
	cub->player.planex = 0;
	cub->player.planey = 0.66;
	cub->player.moveflag = 0;
}

static void	init_map(t_cub *cub)
{
	memset(cub->map.map, 0, sizeof(char) * MAP_W * MAP_H);
}

void	init_cub(t_cub *cub)
{
	init_mlx(cub);
	init_img(cub);
	init_player(cub);
	init_map(cub);
}
