#include "./test.h"

int		main(void)
{
	t_mlx mlx;
	int		img_w;
	int		img_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "ex");
	mlx.img.img = mlx_xpm_file_to_image(mlx.mlx_ptr, "../../imgsrcs/tux.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
