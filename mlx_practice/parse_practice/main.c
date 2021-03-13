#include "parse.h"

void		print_conf(t_conf *conf)
{
	printf("path_no : %s\npath_so : %s\npath_we : %s\npath_ea : %s\n", \
			conf->tex_path_no, conf->tex_path_so, conf->tex_path_we, conf->tex_path_ea);
	printf("resolution w, h : %d, %d\n", conf->resolution_w, conf->resolution_h);
	printf("color_floor : %#x, color_ceil ; %#x\n", conf->color_floor, conf->color_ceil);
	printf("complete_input : %#x\n", conf->complete_input);
}

int		main(int argc, char **argv)
{
	t_conf	conf;

	parse_conf_cub(argc, argv, &conf);
	print_conf(&conf);
	return (0);
}
