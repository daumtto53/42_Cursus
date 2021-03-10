#include "../includes/raycasting.h"
#include "../includes/debug.h"
#include "../../../imgsrcs/barrel.xpm"
/*
 * needed functions :
 *  1. mallocing
*/

static int		allocate_tex_arr(t_cub *cub)
{
	int		**tex_arr;

	tex_arr = (int **)calloc(TEXTURE_NUM, sizeof(int *));
	if (!tex_arr)
	{
		//앞에서 만들었던 동적할당된 변수들 할당 해제 필요.
		return (0);
	}
	cub->tex_arr = tex_arr;
	return (1);
}

static int		allocate_textures(t_cub *cub)
{
	int		*arr;
	int		i;

	i = -1;
	while (++i < TEXTURE_NUM)
	{
		arr = (int *)calloc(TEXTURE_H * TEXTURE_W, sizeof(int));
		if (!arr)
		{
			while (--i >= 0)
				free(cub->tex_arr[i]);
			free(cub->tex_arr);
			return (0);
		}
		cub->tex_arr[i] = arr;
	}
	return (1);
}

static void	load_img_2_texture(t_cub *cub, int tex_num, char *tex_path)
{
	t_img	img;
	int		i;
	int		j;

	img.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, tex_path, &img.img_w, &img.img_h);
	if (img.img_ptr == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(0);
	}
	img.img_buff = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.linelen, &img.endian);
	if (img.img_buff == NULL)
	{
		mlx_destroy_image(cub->mlx_ptr, img.img_ptr);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(0);
	}
	i = -1;
	j = -1;
	while(++i < img.img_h)
	{
		while (++j < img.img_w)
			cub->tex_arr[tex_num][TEXTURE_W * i + j] = img.img_buff[img.img_w * i + j];
		j = 0;
	}
	mlx_destroy_image(cub->mlx_ptr, img.img_ptr);
}

void	load_texture(t_cub *cub)
{
	allocate_tex_arr(cub);
	allocate_textures(cub);
	load_img_2_texture(cub, 0, "../../imgsrcs/wall_1.xpm");
	load_img_2_texture(cub, 1, "../../imgsrcs/wall_2.xpm");
	load_img_2_texture(cub, 2, "../../imgsrcs/wall_3.xpm");
	load_img_2_texture(cub, 3, "../../imgsrcs/wall_4.xpm");
	load_img_2_texture(cub, 4, "../../imgsrcs/ceiling.xpm");
	load_img_2_texture(cub, 5, "../../imgsrcs/floor.xpm");
}
