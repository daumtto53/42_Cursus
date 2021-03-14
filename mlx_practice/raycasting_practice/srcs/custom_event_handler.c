#include "../includes/raycasting.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"

/* LINUX KEYBINDING */

static void	keypress_left_right(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_LEFT)
		cub->player.keypress_flag |= LEFTPRESSED;
	if (keycode == L_KEYSYM_RIGHT)
		cub->player.keypress_flag |= RIGHTPRESSED;
}

static void	keypress_wasd(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_W)
		cub->player.keypress_flag |= WPRESSED;
	if (keycode == L_KEYSYM_A)
		cub->player.keypress_flag |= APRESSED;
	if (keycode == L_KEYSYM_S)
		cub->player.keypress_flag |= SPRESSED;
	if (keycode == L_KEYSYM_D)
		cub->player.keypress_flag |= DPRESSED;
}

int		event_keypress(int keycode ,void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;

	keypress_left_right(keycode, cub);
	keypress_wasd(keycode, cub);
	if (keycode == L_KEYSYM_ESC)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win);
		exit(0);
	}
	return (0);
}

static void	keyrelease_wasd(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_W)
		cub->player.keypress_flag &= ~WPRESSED;
	if (keycode == L_KEYSYM_A)
		cub->player.keypress_flag &= ~APRESSED;
	if (keycode == L_KEYSYM_S)
		cub->player.keypress_flag &= ~SPRESSED;
	if (keycode == L_KEYSYM_D)
		cub->player.keypress_flag &= ~DPRESSED;
}

static void	keyrelease_left_right(int keycode, t_cub *cub)
{
	if (keycode == L_KEYSYM_LEFT)
		cub->player.keypress_flag &= ~LEFTPRESSED;
	if (keycode == L_KEYSYM_RIGHT)
		cub->player.keypress_flag &= ~RIGHTPRESSED;
}
/* LINUX KEYBINDING END */

/* MAC KEYBINDING START */
// static void	keypress_left_right(int keycode, t_cub *cub)
// {
// 	if (keycode == M_KEYSYM_LEFT)
// 		cub->player.keypress_flag |= LEFTPRESSED;
// 	if (keycode == M_KEYSYM_RIGHT)
// 		cub->player.keypress_flag |= RIGHTPRESSED;
// }

// static void	keypress_wasd(int keycode, t_cub *cub)
// {
// 	if (keycode == M_KEYSYM_W)
// 		cub->player.keypress_flag |= WPRESSED;
// 	if (keycode == M_KEYSYM_A)
// 		cub->player.keypress_flag |= APRESSED;
// 	if (keycode == M_KEYSYM_S)
// 		cub->player.keypress_flag |= SPRESSED;
// 	if (keycode == M_KEYSYM_D)
// 		cub->player.keypress_flag |= DPRESSED;
// }

// int		event_keypress(int keycode ,void *param)
// {
// 	t_cub	*cub;

// 	cub = (t_cub *)param;

// 	keypress_left_right(keycode, cub);
// 	keypress_wasd(keycode, cub);
// 	if (keycode == M_KEYSYM_ESC)
// 	{
// 		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
// 		mlx_destroy_window(cub->mlx_ptr, cub->win);
// 		exit(0);
// 	}
// 	return (0);
// }

// static void	keyrelease_wasd(int keycode, t_cub *cub)
// {
// 	if (keycode == M_KEYSYM_W)
// 		cub->player.keypress_flag &= ~WPRESSED;
// 	if (keycode == M_KEYSYM_A)
// 		cub->player.keypress_flag &= ~APRESSED;
// 	if (keycode == M_KEYSYM_S)
// 		cub->player.keypress_flag &= ~SPRESSED;
// 	if (keycode == M_KEYSYM_D)
// 		cub->player.keypress_flag &= ~DPRESSED;
// }

// static void	keyrelease_left_right(int keycode, t_cub *cub)
// {
// 	if (keycode == M_KEYSYM_LEFT)
// 		cub->player.keypress_flag &= ~LEFTPRESSED;
// 	if (keycode == M_KEYSYM_RIGHT)
// 		cub->player.keypress_flag &= ~RIGHTPRESSED;
// }
/* MAC KEYBINDING END */


int		event_keyrelease(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	keyrelease_left_right(keycode, cub);
	keyrelease_wasd(keycode, cub);
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
    exit (0);
}

