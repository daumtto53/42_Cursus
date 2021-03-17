#include "../../includes/raycasting.h"

void			buff_drawer(t_cub *cub, int x, int y, unsigned int color)
{
	int		*img_buff;

	img_buff = cub->img.img_buff;
	img_buff[cub->screen_x * y + x] = color;
}

static unsigned int	get_untxtcolor(t_cub *cub)
{
	unsigned int		color;

	if (cub->ray.side == north)
		color = 0xFF0000;
	else if (cub->ray.side == south)
		color = 0x00FF00;
	else if (cub->ray.side == west)
		color = 0x0000FF;
	else
		color = 0xF0F0F0;
	return (color);
}

static void			draw_buff_line(t_cub *cub, int screenx, int start, int end)
{
	int		i;
	unsigned int	color;

	i = start - 1;
	while (++i <= end)
	{
		color = get_untxtcolor(cub);
		if (cub->ray.side == north || cub->ray.side == south)
			color = color / 2;
		buff_drawer(cub, screenx, i, color);
	}
}

void		draw_img_line_untxt(t_cub *cub, int screenx)
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	unsigned int		color;

	lineheight = (int)(cub->screen_y / cub->ray.perpwalldist);
	drawstart = (cub->screen_y / 2) - (lineheight / 2);
	drawend = (cub->screen_y / 2) + (lineheight / 2);
	if (drawstart < 0)
		drawstart = 0;
	if (drawend > cub->screen_y - 1)
		drawend = cub->screen_y - 1;
	draw_buff_line(cub, screenx, drawstart, drawend);
}
