#ifndef BMP_H
# define BMP_H

# include "../libft/libft.h"

typedef struct	s_bmpfhdr
{
	short	file_type;
	int		file_size;
	short	reserved_1;
	short	reserved_2;
	int		pixel_data_offset;
}				t_bmpfhdr;

typedef struct	s_bmpihdr
{
	int		header_size;
	int		image_width;
	int		image_height;
	short	planes;
	short	bpp;
	int		compression;
	int		image_size;
	int		xpixels_per_meter;
	int		ypixels_per_meter;
	int		total_colors;
	int		important_colors;
}				t_bmpihdr;

int	bmp_maker(t_cub *cub);

#endif
