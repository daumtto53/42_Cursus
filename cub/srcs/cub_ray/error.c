#include "../../includes/raycasting.h"
#include "../../includes/debug.h"

void	print_err(int err_num)
{
	if (err_num == CUSTOM_ERR_MALLOC_FAIL)
		perror("malloc failed ");
	else if (err_num == CUSTOM_ERR_WRONG_INPUT)
		printf("wrong input ");
	else if (err_num == CUSTOM_ERR_MLX_FAIL)
		perror("mlx_*_failed ");
	else
		printf("etc error ");
	printf("Error\n");
}
