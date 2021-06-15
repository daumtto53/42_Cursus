/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:06:24 by mchun             #+#    #+#             */
/*   Updated: 2021/03/23 12:04:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"
#include "../../includes/bmp.h"

static void		write_bitmap_2_bmp(t_cub *cub, int fd)
{
	char	*bit_map;
	int		image_h;
	int		i;

	image_h = cub->screen_y;
	bit_map = (char *)cub->img.img_buff;
	while (--image_h >= 0)
		i = write(fd, bit_map + image_h * cub->screen_x * 4, \
			cub->screen_x * 4);
	i += 1;
}

static void		write_data_2_bmp(t_bmpfhdr *f, t_bmpihdr *i, \
					int fd)
{
	int		del;

	del = write(fd, f, 14);
	del += write(fd, i, 40);
	del = 1;
}

static void		init_bmp_header(t_cub *cub, t_bmpfhdr *f, t_bmpihdr *i)
{
	ft_memset(f, 0, sizeof(t_bmpfhdr));
	ft_memset(i, 0, sizeof(t_bmpihdr));
	ft_memcpy(&(f->file_type), "BM", 2);
	f->pixel_data_offset = 0x36;
	i->header_size = 0x28;
	i->image_width = cub->screen_x;
	i->image_height = cub->screen_y;
	i->image_size = cub->screen_x * cub->screen_y * 4;
	i->planes = 0x01;
	i->bpp = 0x20;
}

int				bmp_maker(t_cub *cub)
{
	t_bmpfhdr	f;
	t_bmpihdr	i;
	int			fd;

	fd = open("./cub.bmp", O_RDWR | O_CREAT, 777);
	if (fd == -1)
		return (-1);
	init_bmp_header(cub, &f, &i);
	write_data_2_bmp(&f, &i, fd);
	write_bitmap_2_bmp(cub, fd);
	close(fd);
	return (1);
}
