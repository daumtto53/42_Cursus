cc = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR_BMP = ./srcs/cub_bmp/
SRCSDIR_PARSE = ./srcs/cub_parse/
SRCSDIR_RAY = ./srcs/cub_ray/
INCLUDES = -I./includes -I./debug -I./x11_key -I./parse

FILE_BMP =		bmp_maker

FILE_RAY =		raycasting_1 \
				raycasting_2 \
				init \
				cub3d_utils \
				custom_event_handler_1 \
				custom_event_handler_2 \
				engine \
				draw_texture \
				draw_untexture \
				error \
				texture \
				debug \
				main \

FILE_PARSE =	valid \
				parse_main \
				parse_type \
				valid_map \
				valid_map_dfs \
				parse_map \
				parse_utils

### LINUX && MAC COMPILATION DIFFERENT ###
LINUXOBJFLAG = -I/usr/include -I../../mlx_linux -O3
LINUXLINKFLAG = -L../../mlx_linux -lmlx_Linux -L/usr/lib -I../../mlx_linux -lXext -lX11 -lm -lz

MACOBJFLAG = -I../../mlx
MACLINKFLAG = -L../../mlx -lmlx -framework OpenGL -framework AppKit
###										###

GNL_LIBFLAG = -L./gnl -lgnl
LIBFT_LIBFLAG = -L./libft -lft

SRCS_BMP = $(addsuffix .c, $(addprefix $(SRCSDIR_BMP), $(FILE_BMP)))
OBJS_BMP = $(SRCS_BMP:.c=.o)
SRCS_RAY = $(addsuffix .c, $(addprefix $(SRCSDIR_RAY), $(FILE_RAY)))
OBJS_RAY = $(SRCS_RAY:.c=.o)
SRCS_PARSE = $(addsuffix .c, $(addprefix $(SRCSDIR_PARSE), $(FILE_PARSE)))
OBJS_PARSE = $(SRCS_PARSE:.c=.o)

NAME = cub3d

$(NAME): $(OBJS_BMP) $(OBJS_RAY) $(OBJS_PARSE)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(CC) $(SRCS_BMP) $(SRCS_PARSE) $(SRCS_RAY) -o $(NAME) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(INCLUDES) $(LINUXOBJFLAG) -c $< -o $@

all :
	$(NAME)

clean :
	rm -rf $(OBJS_BMP) $(OBJS_PARSE) $(OBJS_RAY)

fclean :
	rm -rf $(NAME)

all_clean: clean fclean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	$(MAKE) fclean -C ./gnl
	$(MAKE) clean -C ./gnl

re :
	clean
	all
