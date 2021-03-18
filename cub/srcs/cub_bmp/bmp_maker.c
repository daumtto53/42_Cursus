#include "../../includes/raycasting.h"
#include "../../includes/bmp.h"

static void	write_bitmap_2_bmp(t_cub *cub, int fd)
{
	int		*bit_map;
	int		image_h;
	int		i;

	image_h = cub->screen_y;
	bit_map = cub->img.img_buff;
	while (--image_h >= 0)
	{
		i = -1;
		while (++i < cub->screen_x)
			ft_putnbr_fd(bit_map[image_h * cub->screen_x + i], fd);
	}
}

static void	write_data_2_bmp(t_cub *cub, t_bmpfhdr *f, t_bmpihdr *i, int fd)
{
	// ft_putnbr_fd(f->file_type, fd);
	ft_putstr_fd(ft_itoa(f->file_type), fd);
	// ft_putnbr_fd(f->file_size, fd);
	// ft_putnbr_fd(f->reserved_1, fd);
	// ft_putnbr_fd(f->reserved_2, fd);
	// ft_putnbr_fd(f->pixel_data_offset, fd);

	// ft_putnbr_fd(i->header_size, fd);
	// ft_putnbr_fd(i->image_width, fd);
	// ft_putnbr_fd(i->image_height, fd);
	// ft_putnbr_fd(i->planes, fd);
	// ft_putnbr_fd(i->bpp, fd);

	// ft_putnbr_fd(i->compression, fd);
	// ft_putnbr_fd(i->image_size, fd);
	// ft_putnbr_fd(i->xpixels_per_meter, fd);
	// ft_putnbr_fd(i->ypixels_per_meter, fd);
	// ft_putnbr_fd(i->total_colors, fd);
	// ft_putnbr_fd(i->important_colors, fd);
}


static void	init_bmp_header(t_cub *cub, t_bmpfhdr *f, t_bmpihdr *i)
{
	ft_memset(f, 0, sizeof(t_bmpfhdr));
	ft_memset(i, 0, sizeof(t_bmpihdr));
	f->file_type = 0x4d42;
	f->pixel_data_offset = 0x36;
	i->header_size = 0x28;
	i->image_width = cub->screen_x;
	i->image_height = cub->screen_y;
	i->planes = 0x01;
	i->bpp = 0x20;
}

int	bmp_maker(t_cub *cub)
{
	t_bmpfhdr	f;
	t_bmpihdr	i;
	int			fd;

	//bmp file descriptor, open(), create
	fd = open("./cub.txt", O_RDWR | O_CREAT, 777);
	if (fd == -1)
	{
		//cub에 있는 데이터의 free
		return (-1);
	}
	//init bmp header;
	init_bmp_header(cub, &f, &i);
	//put data to bmp file;
	write_data_2_bmp(cub, &f, &i, fd);
	// write_bitmap_2_bmp(cub, fd);
	close(fd);
	return (1);
}
