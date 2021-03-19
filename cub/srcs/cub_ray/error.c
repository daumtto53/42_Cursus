#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

void	print_err(int err_num)
{
	if (err_num == CUSTOM_ERR_MALLOC_FAIL)
		perror("malloc failed ");
	else if (err_num == CUSTOM_ERR_WRONG_INPUT)
		printf("wrong input ");
	else if (err_num == CUSTOM_ERR_MLX_FAIL)
		perror("mlx_*_failed ");
	else
		printf("etc error ");
	printf("Error\n");
}

void	free_cub_struct(t_cub *cub)
{
	int		i;

	i = -1;
	mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->win);
	free(cub->mlx_ptr);
	while (++i < TEXTURE_NUM)
		free(cub->tex_arr[i]);
	free(cub->tex_arr);
	free(cub->perp_buff);
}
