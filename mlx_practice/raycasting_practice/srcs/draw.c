#include "../includes/raycasting.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"

static void			buff_drawer(t_cub *cub, int x, int y, unsigned int color)
{
#if DEBUG_LEVEL == -3
	printf("buff_drawer START\n\n");
#endif
	int		*img_buff;

	img_buff = cub->img.img_buff;
	img_buff[SCREEN_W * y + x] = color;
#if DEBUG_LEVEL >= 5
	printf("imgbuff[y][x] = %#x\n", color);
#endif
#if DEBUG_LEVEL == -3
	printf("buff_drawer END\n\n");
#endif
}

void	draw_simple_floor_ceiling(t_cub *cub)
{
#if DEBUG_LEVEL >= -3
	printf("draw_simple_floor_ceiling START\n");
#endif
	int		screen_x;
	int		floor_h;
	int		ceiling_h;
	int		half_height;

	half_height = SCREEN_H / 2;
	screen_x = 0;
	floor_h = 0;
	ceiling_h = half_height;
	while (screen_x < SCREEN_W)
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
#if DEBUG_LEVEL >= -3
	printf("get_tex_num START\n\n");
#endif
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
#if DEBUG_LEVEL >= -3
	printf("get_tex_num END\n\n");
#endif
}

static void			draw_buff_wall_texture(t_cub *cub, int screenx, int start, int end)
{
#if DEBUG_LEVEL >= -3
	printf("draw_buff_wall_texture START\n\n");
#endif
	int		y;
	int	tex_num;
	int	tex_x;
	double step;
	double texpos;
	int	tex_y;


	tex_num = get_tex_num(cub);
	tex_x = get_wall_hit_ratio(cub) * (double)TEXTURE_W;
	step = (double)TEXTURE_H / ((int)(SCREEN_H / cub->ray.perpwalldist));
	texpos = ((start - SCREEN_H / 2 +  ((int)(SCREEN_H / cub->ray.perpwalldist)) / 2)) * step;
	y = start - 1;
	while (++y < end)
	{
		tex_y = (int)texpos & (TEXTURE_H - 1);
		texpos += step;
		buff_drawer(cub, screenx, y, \
			cub->tex_arr[tex_num][TEXTURE_H * tex_y + tex_x]);
	}
#if DEBUG_LEVEL >= 5
	printf("draw_buff_line : i = %d, end = %d, start = %d\n", i, end, start);
	printf("screenx: %d, ycoord : %d, color : %#x\n", screenx, i, get_untxtcolor(cub));
#endif
#if DEBUG_LEVEL >= -3
	printf("draw_buff_wall_texture END\n\n");
#endif
}

void		draw_img_line_textured(t_cub *cub, int screenx)
{
#if DEBUG_LEVEL >= -3
	printf("draw_img_line_textured START\n\n");
#endif
	int		lineheight;
	int		drawstart;
	int		drawend;
	unsigned int		color;

	lineheight = (int)(SCREEN_H / cub->ray.perpwalldist);
	drawstart = (SCREEN_H / 2) - (lineheight / 2);
	drawend = (SCREEN_H / 2) + (lineheight / 2);
	if (drawstart < 0)
		drawstart = 0;
	if (drawend > SCREEN_H - 1)
		drawend = SCREEN_H - 1;
	draw_buff_wall_texture(cub, screenx, drawstart, drawend);
#if DEBUG_LEVEL >= -3
	printf("draw_img_line_textured END\n\n");
#endif
}
