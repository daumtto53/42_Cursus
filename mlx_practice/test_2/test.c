#include "./test.h"
#include "./cub3d_event.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_param
{
	int		x;
	int		y;
	char	str[3];
}				t_param;

int		hook_press(unsigned int keycode, t_param *p)
{
	if (keycode == KEY_W)
		p->x++;
	else if (keycode == KEY_S)
		p->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("keycode : %d, x : %d\n", keycode, p->x);
	return (0);
}

int		main(void)
{
	t_mlx mlx;
	int		count_w;
	int		count_h;

	t_param p;
	p.x = 1;
	p.y = 2;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "ex");

	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 1L<<0, &hook_press, &p);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
