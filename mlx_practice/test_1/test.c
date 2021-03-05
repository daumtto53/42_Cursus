#include "./test.h"

int		close(int keycode, t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
}

int		main(void)
{
	t_mlx mlx;
	int		count_w;
	int		count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "ex");

	mlx_hook(mlx.win, 2, 1L << 0, close, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
