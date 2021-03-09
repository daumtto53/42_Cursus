#include "../includes/raycasting.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"

int		event_keypress(int keycode ,void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == L_KEYSYM_LEFT)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode : %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= LEFTPRESSED;
	}
	if (keycode == L_KEYSYM_RIGHT)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= RIGHTPRESSED;
	}
	if (keycode == L_KEYSYM_W)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= WPRESSED;
	}
	if (keycode == L_KEYSYM_A)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= APRESSED;
	}
	if (keycode == L_KEYSYM_S)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= SPRESSED;
	}
	if (keycode == L_KEYSYM_D)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress(): keycode %#x\n", keycode);
		#endif
		cub->player.keypress_flag |= DPRESSED;
	}
	if (keycode == L_KEYSYM_ESC)
	{
		#if DEBUG_LEVEL >= 0
			printf("event_keypress() : keycode %#x\n", keycode);
		#endif
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		exit(0);
	}
	return (0);
}

int		event_keyrelease(int keycode, void *param)
{
	#if DEBUG_LEVEL >= 0
		printf("event_keyrelease() : keycode %#x\n", keycode);
	#endif
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->player.keypress_flag = 0;
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
	//mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	//mlx_destroy_window(cub->mlx_ptr, cub->img.img_ptr);
    exit (0);
}


