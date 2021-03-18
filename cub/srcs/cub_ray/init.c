#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

static void	init_mlx(t_cub *cub, t_conf *conf)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
	mlx_get_screen_size(cub->mlx_ptr, &cub->screen_x, &cub->screen_y);
	if (conf->resolution_w < cub->screen_x)
		cub->screen_x = conf->resolution_w;
	if (conf->resolution_h < cub->screen_y)
		cub->screen_y = conf->resolution_h;
	cub->win = mlx_new_window(cub->mlx_ptr, cub->screen_x, cub->screen_y, "TITLE");
	if (cub->win == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(1);
	}
}

static void	init_img(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, cub->screen_x, cub->screen_y);
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
	cub->img.img_h = cub->screen_y;
	cub->img.img_w = cub->screen_x;
}

static void	init_player(t_cub *cub, t_conf *conf)
{
	// When parsed, needs pos, dir, plane modified.
	cub->player.dirx = 0.0;
	cub->player.diry = 0.0;
	cub->player.planex = 0.0;
	cub->player.planey = 0.0;
	cub->player.posx = conf->posx;
	cub->player.posy = conf->posy;
	if (conf->dir == 'N')
		cub->player.diry = 1.0;
	else if (conf->dir == 'S')
		cub->player.diry = -1.0;
	else if (conf->dir == 'W')
		cub->player.dirx = -1.0;
	else
		cub->player.dirx = 1.0;
	if (conf->dir == 'N' || conf->dir == 'S')
		cub->player.planex = 0.66;
	else
		cub->player.planey = 0.66;
	cub->player.keypress_flag = 0;
}

static void	init_map(t_cub *cub, t_conf *conf)
{
	cub->map.map = conf->dyn.map;
	cub->map.map_h = conf->map_h;
	cub->map.map_w = conf->map_w;
}

void	init_cub(t_cub *cub, t_conf *conf)
{

	init_mlx(cub, conf);
	init_img(cub);
	init_player(cub, conf);
	init_map(cub, conf);
	load_texture(cub, conf);
}
