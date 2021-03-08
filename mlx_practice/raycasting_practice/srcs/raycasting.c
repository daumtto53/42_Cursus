#include "../includes/raycasting.h"
#include "../includes/debug.h"
#include "../includes/x11_key.h"
// TEMPORARY WOLRDMAP DEFINEMENT
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static double func_deltadist(double raydir)
{
	return (fabs(1 / raydir));
}

static void config_rayinfo(t_cub *cub, int screen_x)
{
#if DEBUG_LEVEL >= 1
	printf("config_rayinfo_start\n");
#endif
#if DEBUG_LEVEL >= 2
	debug_rayinfo(cub);
#endif
	t_rayinfo *ray;

	ray = &(cub->ray);
	// needs normalization on camera plane.
	ray->camerax = (2 * screen_x) / (double)SCREEN_W - 1;
	// ray's direction vector == dir vector + plane vector * ratio
	ray->raydirx = cub->player.dirx + cub->player.planex * ray->camerax;
	ray->raydiry = cub->player.diry + cub->player.planey * ray->camerax;

	ray->mapx = (int)cub->player.posx;
	ray->mapy = (int)cub->player.posy;
	ray->deltadistx = func_deltadist(ray->raydirx);
	ray->deltadisty = func_deltadist(ray->raydiry);
#if DEBUG_LEVEL >= 2
	debug_rayinfo(cub);
#endif
#if DEBUG_LEVEL >= 1
	printf("config_rayinfo_end\n\n");
#endif
}

static void	set_sidedist(t_cub *cub, double *sidedx, double *sidedy)
{
#if DEBUG_LEVEL >= 1
	printf("set_sidedist START\n");
#endif
#if DEBUG_LEVEL >= 2
	debug_rayinfo(cub);
#endif
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		*sidedx = (cub->player.posx - cub->ray.mapx) * (cub->ray.deltadistx);
	}
	else
	{
		cub->ray.stepx = 1;
		*sidedx = (cub->ray.mapx + 1.0 - cub->player.posx) * (cub->ray.deltadistx);
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		*sidedy = (cub->player.posy - cub->ray.mapy) * (cub->ray.deltadisty);
	}
	else
	{
		cub->ray.stepy = -1;
		*sidedy = (cub->ray.mapy + 1.0 - cub->player.posy) * (cub->ray.deltadisty);
	}
#if DEBUG_LEVEL >= 2
	debug_rayinfo(cub);
#endif
#if DEBUG_LEVEL >= 1
	printf("set_sidedist END\n\n");
#endif
}

static void	config_hit_wall(t_cub *cub, double sidex, double sidey)
{
#if DEBUG_LEVEL >= 1
	printf("config_hit_wall START\n");
#endif
	int		is_hit;

	is_hit = !HIT;
	while (is_hit != HIT)
	{
		if (comp_double(sidey, sidex) > 0)
		{
			sidex += cub->ray.deltadistx;
			cub->ray.mapx += (cub->ray.stepx);
			cub->ray.side = west;
			if (cub->ray.raydirx > 0)
				cub->ray.side = east;
			#if DEBUG_LEVEL >= 2
				printf("comp_double : sidey > sidex\n");
			#endif
		}
		else
		{
			sidey += cub->ray.deltadisty;
			cub->ray.mapy += (cub->ray.stepy);
			cub->ray.side = south;
			if (cub->ray.raydiry > 0)
				cub->ray.side = north;
			#if DEBUG_LEVEL >= 2
				printf("comp_double : sidex > sidey\n");
			#endif
		}
		if (worldMap[cub->ray.mapy][cub->ray.mapx] > 0)
		{
			is_hit = HIT;
			#if DEBUG_LEVEL >= 2
				printf("is_hit : %d\n", is_hit);
			#endif
		}
	#if DEBUG_LEVEL >= 2
		debug_config_hit_wall(cub, sidex, sidey);
	#endif
	}
#if DEBUG_LEVEL >= 1
	printf("config_hit_wall END\n\n");
#endif
}

static void	set_perpwalldist(t_cub *cub)
{
#if DEBUG_LEVEL >= 1
	printf("set_perpwalldist START\n\n");
#endif
	t_rayinfo	*ray;
	int			xweight;
	int			yweight;

	ray = &(cub->ray);
	xweight = (1 - ray->stepx) / 2;
	yweight = (1 - ray->stepy) / 2;
	if (ray->side == east || ray->side == west)
	{
		ray->perpwalldist = \
			(ray->mapx - (cub->player.posx) + xweight) / ray->raydirx;
	}
	else if (ray->side == south || ray->side == north)
	{
		ray->perpwalldist = \
			(ray->mapy - (cub->player.posy) + yweight) / ray->raydiry;
	}
#if DEBUG_LEVEL >= 1
	printf("set_perpwalldist END\n\n");
#endif
}

void			buff_drawer(t_cub *cub, int x, int y, unsigned int color)
{
#if DEBUG_LEVEL >= 1
	printf("buff_drawer START\n\n");
#endif
	int		*img_buff;

	img_buff = cub->img.img_buff;
	img_buff[SCREEN_W * y + x] = color;
#if DEBUG_LEVEL >= 2
	printf("imgbuff[y][x] = %#x\n", color);
#endif
#if DEBUG_LEVEL >= 1
	printf("buff_drawer END\n\n");
#endif
}

unsigned int	get_untxtcolor(t_cub *cub)
{
#if DEBUG_LEVEL >= 1
	printf("get_untxtcolor START\n\n");
#endif
	unsigned int		color;

	if (cub->ray.side == north)
		color = 0xFF0000;
	else if (cub->ray.side == south)
		color = 0x00FF00;
	else if (cub->ray.side == west)
		color = 0x0000FF;
	else
		color = 0xF0F0F0;
#if DEBUG_LEVEL >= 1
	printf("get_untxtcolor END\n\n");
#endif
	return (color);
}

void			draw_buff_line(t_cub *cub, int screenx, int start, int end)
{
#if DEBUG_LEVEL >= 1
	printf("draw_buff_line START\n\n");
#endif
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
#if DEBUG_LEVEL >= 2
	printf("draw_buff_line : i = %d, end = %d, start = %d\n", i, end, start);
	printf("screenx: %d, ycoord : %d, color : %#x\n", screenx, i, get_untxtcolor(cub));
#endif
#if DEBUG_LEVEL >= 1
	printf("draw_buff_line END\n\n");
#endif
}

void		draw_img_line_untxt(t_cub *cub, int screenx)
{
#if DEBUG_LEVEL >= 1
	printf("draw_img_line_untxt START\n\n");
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
	draw_buff_line(cub, screenx, drawstart, drawend);
#if DEBUG_LEVEL >= 1
	printf("draw_img_line_untxt END\n\n");
#endif
}

void untextured_rayc(t_cub *cub)
{
#if DEBUG_LEVEL >= 1
	printf("untextured_rayc START\n\n");
#endif
	int			screen_x;
	int			color;
	t_rayinfo	*ray;
	double sidedistx;
	double sidedisty;

	ray = &(cub->ray);
	for (screen_x = 0; screen_x < SCREEN_W; screen_x++)
	{
		config_rayinfo(cub, screen_x);
		set_sidedist(cub, &sidedistx, &sidedisty);
		config_hit_wall(cub, sidedistx, sidedisty);
		set_perpwalldist(cub);
		draw_img_line_untxt(cub, screen_x);
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img.img_ptr, 0, 0);
#if DEBUG_LEVEL >= 2
	debug_print_buffer(cub);
#endif
#if DEBUG_LEVEL >= 1
	printf("untextured_rayc END\n\n");
#endif
}

int		main()
{
#if DEBUG_LEVEL >= 1
	printf("main START\n\n");
#endif

	t_cub cub;

	init_cub(&cub);
	untextured_rayc(&cub);

	// mlx_hook(cub.win, KEYPRESS, KEYPRESSMASK, event_keypress, &cub);
	// mlx_hook(cub.win, KEYRELEASE, KEYRELEASEMASK, event_keyrelease, &cub);
	// mlx_hook(cub.win, DESTORY_NOTIFY, 0, event_destroy, &cub);
	// mlx_hook(cub.win, CLIENTMESSAGE, BUTTONRELEASEMASK, event_xicon, &cub);

	mlx_loop_hook(cub.mlx_ptr, untextured_rayc, &cub);
	// 내 이미지를 쓰레드로 돌리는건가?
	mlx_loop(cub.mlx_ptr);
#if DEBUG_LEVEL >= 1
	printf("main END\n\n");
#endif
}

/*	############## FOR DEBUGGING : mlx_init() was not working ###########
	// insert code below

	cub.mlx_ptr = mlx_init();
	cub.win = mlx_new_window(cub.mlx_ptr, SCREEN_W, SCREEN_H, "ex");
	cub.img.img_ptr = mlx_new_image(cub.mlx_ptr, SCREEN_W, SCREEN_H);
	cub.img.img_buff = (int *)mlx_get_data_addr(cub.img.img_ptr, &cub.img.bpp, &cub.img.linelen, &cub.img.endian);
	int count_w = -1;
	int count_h = -1;
	while (++count_h < SCREEN_H)
	{
		count_w = -1;
		while (++count_w < SCREEN_W)
		{
			if (count_w % 2)
				cub.img.img_buff[count_h * SCREEN_W + count_w] = 0xFFFFFF;
			else
				cub.img.img_buff[count_h * SCREEN_W + count_w] = 0;
		}
	}
	mlx_put_image_to_window(cub.mlx_ptr, cub.win, cub.img.img_ptr, 0, 0);
*/
