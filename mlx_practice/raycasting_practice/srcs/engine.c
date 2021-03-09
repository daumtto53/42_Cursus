#include "../includes/debug.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"


static int		is_collision(int map[MAP_H][MAP_W], int x, int y)
{
	return (map[y][x]);
}

//needs argument deleted when revising.
void	take_action(t_cub *cub, int map[MAP_H][MAP_W])
{
	t_player *p = &(cub->player);
	#if DEBUG_LEVEL >= 0
			printf("take action() : keypress_flag: %d\n", p->keypress_flag);
	#endif

	if (p->keypress_flag & LEFTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, -1 * DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, -1 * DELTATHETA);
	}
	else if (p->keypress_flag & RIGHTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, DELTATHETA);
	}
	if (p->keypress_flag & WPRESSED)
	{
		if (!is_collision(map, (int)(p->posx + p->dirx * MOVESPEED), (int)p->posy))
			p->posx += p->dirx * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy + p->diry * MOVESPEED)))
			p->posy += p->diry * MOVESPEED;
	}
	if (p->keypress_flag & SPRESSED)
	{
		if (!is_collision(map, (int)(p->posx - p->dirx * MOVESPEED), (int)p->posy))
			p->posx -= p->dirx * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy - p->diry * MOVESPEED)))
			p->posy -= p->diry * MOVESPEED;
	}
	if (p->keypress_flag & APRESSED)
	{
		if (!is_collision(map, (int)(p->posx + p->planex * MOVESPEED), (int)p->posy))
			p->posx += p->planex * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy + p->planey * MOVESPEED)))
			p->posy += p->planey * MOVESPEED;
	}
	if (p->keypress_flag & DPRESSED)
	{
		if (!is_collision(map, (int)(p->posx - p->planex * MOVESPEED), (int)p->posy))
			p->posx -= p->planex * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy - p->planey * MOVESPEED)))
			p->posy -= p->planey * MOVESPEED;
	}
}
