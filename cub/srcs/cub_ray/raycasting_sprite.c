#include "../../includes/raycasting.h"

static void		conf_sprite(t_cub *cub, double x, double y, int sp_index)
{
	cub->sprite_arr[sp_index].sprite_num = sp_index;
	cub->sprite_arr[sp_index].x = x;
	cub->sprite_arr[sp_index].y = y;
}

static void		init_sprite(t_cub *cub)
{
	int		i;

	conf_sprite(cub, 20.5, 18.5, 0);
	conf_sprite(cub, 18.5, 9.5, 1);
	conf_sprite(cub, 12.5, 12.5, 2);
	conf_sprite(cub, 20.5, 3.5, 3);
	conf_sprite(cub, 3.5, 3.5, 4);
	conf_sprite(cub, 15.5, 25.5, 5);
	conf_sprite(cub, 0.0, 0.0, 6);
	conf_sprite(cub, 8.5, 2.5, 7);
	conf_sprite(cub, 3.0, 9.0, 8);
	conf_sprite(cub, 0.0, 0.0, 9);
	i = -1;
	while (++i < SPRITE_NUM)
	{
		cub->sprite_order[i] = i;
		cub->sprite_dist[i] = \
			pow((cub->player.posx - cub->sprite_arr[i].x), 2.0) + \
			pow((cub->player.posy - cub->sprite_arr[i].y), 2.0);
	}
}

static void		sort_sprites(double *dist, int *order)
{
	int		i = -1;
	int		j = -1;
	int		aux_o;
	double	aux_d;

	while (++i < SPRITE_NUM - 1)
		while (++j < SPRITE_NUM - i - 1)
		{
			if (dist[j] < dist[j + 1])
			{
				aux_d = dist[j];
				dist[j] = dist[j + 1];
				dist[j + 1] = aux_d;
				aux_o = order[j];
				order[j] = order[j + 1];
				order[j + 1] = aux_o;
			}
		}
}

static void		init_sprite_op_data(t_cub *cub, t_sprite_op *op, int i)
{
	op->spritex = cub->sprite_arr[cub->sprite_order[i]].x - cub->player.posx;
	op->spritey = cub->sprite_arr[cub->sprite_order[i]].y - cub->player.posy;
	op->inv_det = 1.0 / (cub->player.planex * cub->player.diry - \
						cub->player.dirx * cub->player.planey);
	op->trans_x = op->inv_det * (cub->player.diry * op->spritex - \
							cub->player.dirx * op->spritey);
	op->trans_y = op->inv_det * (cub->player.planey * op->spritex - \
							cub->player.planex * op->spritey);
	op->sprite_scx = (int)((cub->screen_x / 2) * (1 + op->trans_x / op->trans_y));
	op->sprite_h = abs((int)(cub->screen_y / op->trans_y));
	op->drawstart_y = (-1) * op->sprite_h  /  2 + cub->screen_y / 2;
	if (op->drawstart_y < 0)
		op->drawstart_y = 0;
	op->drawend_y = (1) * op->sprite_h  /  2 + cub->screen_y / 2;
	if (op->drawend_y >= cub->screen_y)
		op->drawend_y = cub->screen_y - 1;
	op->sprite_w = abs((int)(cub->screen_y / op->trans_y));
	op->drawstart_x = (-1) * op->sprite_w / 2 + op->sprite_scx;
	if (op->drawstart_x < 0)
		op->drawstart_x = 0;
	op->drawend_x = (1) * op->sprite_w / 2 + op->sprite_scx;
	if (op->drawend_x >= cub->screen_x)
		op->drawend_x = cub->screen_x - 1;
}

void	sprite_rayc(t_cub *cub)
{
	t_sprite_op		op;
	int				i;
	int				line;
	int				y;
	unsigned int	color;

	init_sprite(cub);
	sort_sprites(cub->sprite_dist, cub->sprite_order);
	i = -1;
	while (++i < SPRITE_NUM)
	{
		init_sprite_op_data(cub, &op, i);
		line = op.drawstart_x;
		while (line++ < op.drawend_x)
		{
			if (op.trans_y > 0 && line > 0 && line < cub->screen_x && \
					op.trans_y < cub->perp_buff[line])
			{
				op.texx = \
					(int)(line - (-1 * op.sprite_w / 2 + op.sprite_scx) * \
						TEXTURE_W / op.sprite_w);
				y = op.drawstart_y;
				while (++y < op.drawend_y)
				{
					op.texy = y - cub->screen_y / 2 + op.sprite_h;
					op.texy = (op.texy * TEXTURE_H) / op.sprite_h;
					color = cub->tex_arr[cub->sprite_arr[cub->sprite_order[i]].sprite_num][TEXTURE_W * op.texy + op.texx];
					if ((color & 0x00FFFFFF) != 0)
						buff_drawer(cub, line, y, color);
				}
			}
		}
	}
}
