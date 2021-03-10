#include "../includes/debug.h"
#include "../includes/x11_key.h"
#include "../includes/debug.h"


static int		is_collision(int map[MAP_H][MAP_W], int x, int y)
{
	return (map[y][x]);
}

/** 끼임 현상 발생. **/
static int	is_collision_2(int map[MAP_H][MAP_W], double posx, double posy)
{
	int		collision;

	collision = (map[(int)posy][(int)(posx - 0.4)] ||\
		map[(int)posy][(int)(posx + 0.3)] ||
		map[(int)(posy + 0.4)][(int)posx] ||\
		map[(int)(posy - 0.3)][(int)posx]);
	return (collision);
}

//needs argument deleted when revising.
void	take_action(t_cub *cub, int map[MAP_H][MAP_W])
{
	t_player *p = &(cub->player);
	#if DEBUG_LEVEL >= 0
			printf("take action() : keypress_flag: %d\n", p->keypress_flag);
	#endif

	if (p->keypress_flag & RIGHTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, -1 * DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, -1 * DELTATHETA);
	}
	if (p->keypress_flag & LEFTPRESSED)
	{
		matrix_rotation_2d(&p->dirx, &p->diry, DELTATHETA);
		matrix_rotation_2d(&p->planex, &p->planey, DELTATHETA);
	}
	if (p->keypress_flag & WPRESSED)
	{
		// if (!is_collision_2(map, (p->posx + p->dirx * MOVESPEED), p->posy))
		// 	p->posx += p->dirx * MOVESPEED;
		// if (!is_collision_2(map, p->posx, (p->posy + p->diry * MOVESPEED)))
		// 	p->posy += p->diry * MOVESPEED;

		if (!is_collision(map, (int)(p->posx + p->dirx * MOVESPEED), (int)p->posy))
			p->posx += p->dirx * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy + p->diry * MOVESPEED)))
			p->posy += p->diry * MOVESPEED;
	}
	if (p->keypress_flag & SPRESSED)
	{
		// if (!is_collision_2(map, (p->posx + p->dirx * MOVESPEED), p->posy))
		// 	p->posx -= p->dirx * MOVESPEED;
		// if (!is_collision_2(map, p->posx, (p->posy + p->diry * MOVESPEED)))
		// 	p->posy -= p->diry * MOVESPEED;

		if (!is_collision(map, (int)(p->posx - p->dirx * MOVESPEED), (int)p->posy))
			p->posx -= p->dirx * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy - p->diry * MOVESPEED)))
			p->posy -= p->diry * MOVESPEED;
	}
	if (p->keypress_flag & DPRESSED)
	{
		// if (!is_collision_2(map, (p->posx + p->dirx * MOVESPEED), p->posy))
		// 	p->posx += p->planex * MOVESPEED;
		// if (!is_collision_2(map, p->posx, (p->posy + p->diry * MOVESPEED)))
		// 	p->posy += p->planey * MOVESPEED;


		if (!is_collision(map, (int)(p->posx + p->planex * MOVESPEED), (int)p->posy))
			p->posx += p->planex * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy + p->planey * MOVESPEED)))
			p->posy += p->planey * MOVESPEED;
	}
	if (p->keypress_flag & APRESSED)
	{
		// if (!is_collision_2(map, (p->posx + p->dirx * MOVESPEED), p->posy))
		// 	p->posx -= p->planex * MOVESPEED;
		// if (!is_collision_2(map, p->posx, (p->posy + p->diry * MOVESPEED)))
		// 	p->posy -= p->planey * MOVESPEED;


		if (!is_collision(map, (int)(p->posx - p->planex * MOVESPEED), (int)p->posy))
			p->posx -= p->planex * MOVESPEED;
		if (!is_collision(map, (int)p->posx, (int)(p->posy - p->planey * MOVESPEED)))
			p->posy -= p->planey * MOVESPEED;
	}
}
