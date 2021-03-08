#ifndef DEBUG_H
#define DEBUG_H
#include "raycasting.h"

//DEBUGGER ON/OFF
#define DEBUG

void	debug_rayinfo(t_cub *cub);
void	debug_config_hit_wall(t_cub *cub, double sx, double sy);
#endif
