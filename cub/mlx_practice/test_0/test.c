/*
 * https://github.com/keuhdall/images_example
*/

#include "./test.h"

int		main(void)
{
	t_mlx mlx;
	int		count_w;
	int		count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "ex");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = (int *)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.line_length, &mlx.img.endian);

	count_w = -1;
	count_h = -1;
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 2)
				mlx.img.addr[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			else
				mlx.img.addr[count_h * WIN_HEIGHT + count_w] = 0;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
