#include "../includes/raycasting.h"
#include "../includes/debug.h"

int		comp_double(double dest, double src)
{
	int		ret_val;

	if (fabs(dest - src) > DBL_EPSILON)
		ret_val = 1;
	else
		ret_val = 0;
	#if DEBUG_LEVEL >= 2
		printf("ret_val: %d\n", ret_val);
	#endif
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
