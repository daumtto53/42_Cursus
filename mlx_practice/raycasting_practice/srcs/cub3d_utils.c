#include "../includes/raycasting.h"
#include "../includes/debug.h"
int		comp_double(double dest, double src)
{
	int		ret_val;

	if (fabs(dest - src) > DBL_EPSILON)
		ret_val = 1;
	else if (fabs(dest - src) < DBL_EPSILON)
		ret_val = 0;
	else
		ret_val = -1;
	#ifdef DEBUG
		printf("ret_val: %d\n", ret_val);
	#endif
}
