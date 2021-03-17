#ifndef DEBUG_H
#define DEBUG_H
#include "./raycasting.h"

# define CUSTOM_ERR_MALLOC_FAIL	1 << 1
# define CUSTOM_ERR_WRONG_INPUT	1 << 2
# define CUSTOM_ERR_MLX_FAIL	1 << 3
# define CUSTOM_ERR_ETC			0

//DEBUGGER ON/OFF

void	debug_rayinfo(t_cub *cub);
void	debug_config_hit_wall(t_cub *cub, double sx, double sy);
void	debug_print_buffer(t_cub *cub);
void	print_err(int err_num);
void	debug_texture_rgb(t_cub *cub, int tex_num);

#endif
