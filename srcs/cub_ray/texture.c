/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:51:11 by mchun             #+#    #+#             */
/*   Updated: 2021/03/30 14:53:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

static int	allocate_tex_arr(t_cub *cub)
{
	int		**tex_arr;

	tex_arr = (int **)ft_calloc(TEXTURE_NUM, sizeof(int *));
	if (!tex_arr)
	{
		print_err(CUSTOM_ERR_MALLOC_FAIL);
		exit(0);
	}
	cub->tex_arr = tex_arr;
	return (1);
}

static int	allocate_textures(t_cub *cub)
{
	int		*arr;
	int		i;

	i = -1;
	while (++i < TEXTURE_NUM)
	{
		arr = (int *)ft_calloc(TEXTURE_H * TEXTURE_W, sizeof(int));
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

static void	assign_tex_2_buff(t_cub *cub, t_img *img, int tex_num)
{
	int		i;
	int		j;

	i = -1;
	while (++i < img->img_h)
	{
		j = -1;
		while (++j < img->img_w)
			cub->tex_arr[tex_num][TEXTURE_W * i + j] = \
				img->img_buff[img->img_w * i + j];
	}
}

static void	load_img_2_texture(t_cub *cub, int tex_num, char *tex_path)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, tex_path, \
		&img.img_w, &img.img_h);
	if (img.img_ptr == NULL)
	{
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(0);
	}
	img.img_buff = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.linelen, &img.endian);
	if (img.img_buff == NULL)
	{
		mlx_destroy_image(cub->mlx_ptr, img.img_ptr);
		print_err(CUSTOM_ERR_MLX_FAIL);
		exit(0);
	}
	assign_tex_2_buff(cub, &img, tex_num);
	mlx_destroy_image(cub->mlx_ptr, img.img_ptr);
}

void		load_texture(t_cub *cub, t_conf *conf)
{
	cub->tex_num = TEXTURE_NUM;
	allocate_tex_arr(cub);
	allocate_textures(cub);
	load_img_2_texture(cub, TEXTURE_WALL_0, conf->tex_path_no);
	load_img_2_texture(cub, TEXTURE_WALL_1, conf->tex_path_so);
	load_img_2_texture(cub, TEXTURE_WALL_2, conf->tex_path_we);
	load_img_2_texture(cub, TEXTURE_WALL_3, conf->tex_path_ea);
	load_img_2_texture(cub, TEXTURE_FLOOR, "./imgsrcs/floor.xpm");
	load_img_2_texture(cub, TEXTURE_CEILING, "./imgsrcs/ceiling.xpm");
	load_img_2_texture(cub, TEXTURE_SP_1, conf->tex_path_s);
	load_img_2_texture(cub, TEXTURE_SP_2, "./imgsrcs/sprite_2.xpm");
	load_img_2_texture(cub, TEXTURE_SP_3, "./imgsrcs/sprite_3.xpm");
	free_tex_path(conf);
}
