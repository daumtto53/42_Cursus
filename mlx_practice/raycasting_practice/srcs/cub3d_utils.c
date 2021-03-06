#include "../includes/raycasting.h"

int		comp_double(double dest, double src)
{
	if (dest - src > DBL_EPSILON)
		return (1);
	else if (dest - src < DBL_EPSILON && dest - src > 0)
		return (0);
	else
		return (-1);
}
