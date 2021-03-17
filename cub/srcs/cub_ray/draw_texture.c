#include "../../includes/raycasting.h"
#include "../../includes/x11_key.h"
#include "../../includes/debug.h"

void	draw_simple_floor_ceiling(t_cub *cub)
{
	int		screen_x;
	int		floor_h;
	int		ceiling_h;
	int		half_height;

	half_height = cub->screen_y / 2;
	screen_x = 0;
	floor_h = 0;
	ceiling_h = half_height;
	while (screen_x < cub->screen_y)
	{
		while (floor_h < half_height)
		{
			buff_drawer(cub, screen_x, floor_h, COLOR_FLOOR);
			buff_drawer(cub, screen_x, ceiling_h, COLOR_CEILING);
			floor_h++;
			ceiling_h++;
		}
		screen_x++;
		floor_h = 0;
		ceiling_h = half_height;
	}
}

static unsigned int	get_tex_num(t_cub *cub)
{
	int		tex_num;

	if (cub->ray.side == north)
		tex_num = TEXTURE_WALL_0;
	else if (cub->ray.side == south)
		tex_num = TEXTURE_WALL_1;
	else if (cub->ray.side == west)
		tex_num = TEXTURE_WALL_2;
	else
		tex_num = TEXTURE_WALL_3;
	return (tex_num);
}

static void			draw_buff_wall_texture(t_cub *cub, int screenx, int start, int end)
{
	int		y;
	int	tex_x;
	double step;
	double texpos;
	int	tex_y;

	cub->tex_num = get_tex_num(cub);
	tex_x = get_wall_hit_ratio(cub) * (double)TEXTURE_W;
	step = (double)TEXTURE_H / ((int)(cub->screen_y / cub->ray.perpwalldist));
	texpos = ((start - cub->screen_y / 2 +  ((int)(cub->screen_y / cub->ray.perpwalldist)) / 2)) * step;
	y = start - 1;
	while (++y < end)
	{
		tex_y = (int)texpos & (TEXTURE_H - 1);
		texpos += step;
		buff_drawer(cub, screenx, y, \
			cub->tex_arr[cub->tex_num][TEXTURE_H * tex_y + tex_x]);
	}
}

void		draw_img_line_textured(t_cub *cub, int screenx)
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
	draw_buff_wall_texture(cub, screenx, drawstart, drawend);
}
