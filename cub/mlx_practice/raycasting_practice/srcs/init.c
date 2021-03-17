#include "../includes/raycasting.h"
#include "../includes/debug.h"

static void	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_W, SCREEN_H, "TITLE");
	if (cub->win == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
}

static void	init_img(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, SCREEN_W, SCREEN_H);
	if (cub->img.img_ptr == NULL)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	cub->img.img_buff = \
		(int *)mlx_get_data_addr(cub->img.img_ptr, \
			&cub->img.bpp, &cub->img.linelen, &cub->img.endian);
	if (cub->img.img_buff == NULL)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	cub->img.img_h = SCREEN_H;
	cub->img.img_w = SCREEN_W;
}

static void	init_player(t_cub *cub)
{
	// When parsed, needs pos, dir, plane modified.
	cub->player.dirx = -1.0;
	cub->player.diry = 0.0;
	cub->player.posx = 22.0;
	cub->player.posy = 12.0;
	cub->player.planex = 0;
	cub->player.planey = 0.66;
	cub->player.keypress_flag = 0;
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
	load_texture(cub);
}

void	init_ceilfloor(t_cub *cub, t_ceilfloor *cf, int y)
{
	cf->raydirx0 = cub->player.dirx - cub->player.planex;
	cf->raydirx1 = cub->player.dirx + cub->player.planex;
	cf->raydiry0 = cub->player.diry - cub->player.planey;
	cf->raydiry1 = cub->player.diry + cub->player.planey;
	cf->standardy = y - SCREEN_H / 2;
	cf->rowdistance = (SCREEN_H * 0.5) / cf->standardy;
	cf->stepx = cf->rowdistance * (cf->raydirx1 - cf->raydirx0) / SCREEN_W;
	cf->stepy = cf->rowdistance * (cf->raydiry1 - cf->raydiry0) / SCREEN_W;
	cf->ceilfloorx = cub->player.posx + cf->rowdistance * cf->raydirx0;
	cf->ceilfloory = cub->player.posy + cf->rowdistance * cf->raydiry0;
}
