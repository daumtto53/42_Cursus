#include "../../includes/raycasting.h"

void	sprite_rayc_calculator(t_cub *cub, t_sprite_op *op, int i, int line)
{
	int		y;
	int		color;
	int		tex_num;

	while (line++ < op->drawend_x)
	{
		if (op->trans_y > 0 && line > 0 && line < cub->screen_x && \
				op->trans_y < cub->perp_buff[line])
		{
			op->texx = \
				(int)((line - (-1 * op->sprite_w / 2 + op->sprite_scx)) * \
					TEXTURE_W / op->sprite_w);
			// printf("texx: %d\n", op->texx);
			fflush(stdout);
			y = op->drawstart_y;
			while (++y < op->drawend_y)
			{
				op->texy = y - cub->screen_y / 2 + op->sprite_h / 2;
				op->texy = (op->texy * TEXTURE_H) / op->sprite_h;
				tex_num = cub->sprite_arr[cub->sprite_order[i]].tex_num;
				// printf("tex num : %d, ", tex_num);
				color = cub->tex_arr[tex_num][TEXTURE_W * op->texy + op->texx];
				// printf("line : %d texx : %d, texy : %d\n",line,  op->texx, op->texy);
				fflush(stdout);
				if ((color & 0x00FFFFFF) != 0)
					buff_drawer(cub, line, y, color);
			}
		}
	}
}
