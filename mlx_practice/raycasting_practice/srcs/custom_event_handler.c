#include "../includes/raycasting.h"
#include "../includes/x11_key.h"

int		event_keypress(int keycode ,void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == L_KEYSYM_W)
	{
		cub->player.wasdpressed = 0;
		cub->player.wasdpressed |= WPRESSED;
	}
	if (keycode == L_KEYSYM_A)
	{
		cub->player.wasdpressed = 0;
		cub->player.wasdpressed |= APRESSED;
	}
	if (keycode == L_KEYSYM_S)
	{
		cub->player.wasdpressed = 0;
		cub->player.wasdpressed |= SPRESSED;
	}
	if (keycode == L_KEYSYM_D)
	{
		cub->player.wasdpressed = 0;
		cub->player.wasdpressed |= DPRESSED;
	}
	if (keycode == L_KEYSYM_ESC)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		exit(0);
	}
}

int		event_keyrelease(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->player.wasdpressed = 0;
	return (0);
}

int event_destroy(void *param)
{
    t_cub	*cub;

	cub = (t_cub *)param;
	mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->img.img_ptr);
    exit (0);
}

int	event_xicon(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->img.img_ptr);
    exit (0);
}


