#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

int		comp_double(double dest, double src)
{
	int		ret_val;

	if (fabs(dest - src) > DBL_EPSILON)
		ret_val = 1;
	else
		ret_val = 0;
	return (ret_val);
}

void	matrix_rotation_2d(double *x, double *y, double delta_tht)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;

	*x = old_x * cos(delta_tht) - old_y * sin(delta_tht);
	*y = old_x * sin(delta_tht) + old_y * cos(delta_tht);
}

double	get_wall_hit_ratio(t_cub *cub)
{
	double		wall_x;

	if (cub->ray.side == north || cub->ray.side == south)
		wall_x = cub->player.posx + cub->ray.perpwalldist * cub->ray.raydirx;
	else
		wall_x = cub->player.posy + cub->ray.perpwalldist * cub->ray.raydiry;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int		get_texture_mapping(int tex_x, double texpos)
{
	int		tex_y;

	tex_y = (int)texpos & (TEXTURE_H - 1);
	return (TEXTURE_H * tex_y + tex_x);
}

double func_deltadist(double raydir)
{
	return (fabs(1 / raydir));
}
