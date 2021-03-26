cc = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR_BMP = ./srcs/cub_bmp/
SRCSDIR_PARSE = ./srcs/cub_parse/
SRCSDIR_RAY = ./srcs/cub_ray/
SRCSDIR_ETC = ./srcs/etc_bonus/
INCLUDES = -I./includes -I./debug -I./x11_key -I./parse

FILE_BMP =		bmp_maker

FILE_ETC =	bgm_bonus \
			hud_bonus

FILE_RAY =		raycasting_2 \
				init \
				cub3d_utils \
				engine \
				draw_texture \
				draw_untexture \
				draw_sprite \
				error \
				texture

FILE_RAY_BASE = raycasting_1 \
				custom_event_handler_1 \
				custom_event_handler_2 \
				raycasting_sprite \
				init_sprite \
				main

FILE_RAY_BONUS =	raycasting_1_bonus \
					custom_event_handler_1_bonus \
					custom_event_handler_2_bonus \
					raycasting_sprite_bonus \
					init_sprite_bonus \
					main_bonus

FILE_PARSE =	valid \
				parse_main \
				parse_type \
				valid_map \
				valid_map_dfs \
				valid_map_utils \
				parse_map \
				parse_utils


### LINUX && MAC COMPILATION DIFFERENT ###
LINUXOBJFLAG = -I/usr/include -I../../mlx_linux -O3
LINUXLINKFLAG = -L./mlx_linux -lmlx_Linux -L/usr/lib -I../../mlx_linux -lXext -lX11 -lm -lz

MACOBJFLAG = -I../../mlx
MACLINKFLAG = -L../../mlx -lmlx -framework OpenGL -framework AppKit
###										###

GNL_LIBFLAG = -L./gnl -lgnl
LIBFT_LIBFLAG = -L./libft -lft

SRCS_BMP = $(addsuffix .c, $(addprefix $(SRCSDIR_BMP), $(FILE_BMP)))
OBJS_BMP = $(SRCS_BMP:.c=.o)
SRCS_RAY_BASE = $(addsuffix .c, $(addprefix $(SRCSDIR_RAY), $(FILE_RAY_BASE)))
OBJS_RAY_BASE = $(SRCS_RAY_BASE:.c=.o)
SRCS_RAY = $(addsuffix .c, $(addprefix $(SRCSDIR_RAY), $(FILE_RAY)))
OBJS_RAY = $(SRCS_RAY:.c=.o)
SRCS_RAY_BONUS = $(addsuffix .c, $(addprefix $(SRCSDIR_RAY), $(FILE_RAY_BONUS)))
OBJS_RAY_BONUS = $(SRCS_RAY_BONUS:.c=.o)
SRCS_ETC = $(addsuffix .c, $(addprefix $(SRCSDIR_ETC), $(FILE_ETC)))
OBJS_ETC = $(SRCS_ETC:.c=.o)

SRCS_PARSE = $(addsuffix .c, $(addprefix $(SRCSDIR_PARSE), $(FILE_PARSE)))
OBJS_PARSE = $(SRCS_PARSE:.c=.o)

NAME = cub3D

BONUS = cub3D_bonus

$(NAME): $(OBJS_BMP) $(OBJS_RAY) $(OBJS_PARSE) $(OBJS_RAY_BASE)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(MAKE) all -C ./mlx_linux
	cp ./mlx_linux/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS_BMP) $(SRCS_PARSE) $(SRCS_RAY) $(SRCS_RAY_BASE) -o $(NAME) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

$(BONUS) : $(OBJS_BMP) $(OBJS_RAY) $(OBJS_PARSE) $(OBJS_RAY_BONUS) $(OBJS_ETC)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(MAKE) all -C ./mlx_linux
	cp ./mlx_linux/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS_BMP) $(SRCS_ETC) $(SRCS_PARSE) $(SRCS_RAY) $(SRCS_RAY_BONUS) -o $(BONUS) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LINUXOBJFLAG) -c $< -o $@

all : $(NAME)

bonus: $(BONUS)

clean :
	rm -rf $(OBJS_BMP) $(OBJS_PARSE) $(OBJS_RAY) $(OBJS_RAY_BONUS) $(OBJS_RAY_BASE) $(OBJS_ETC)

fclean :
	rm -rf $(NAME)

all_clean: clean fclean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	$(MAKE) fclean -C ./gnl
	$(MAKE) clean -C ./gnl
	$(MAKE) clean -C ./mlx_linux
	rm libmlx_Linux.a

re :
	fclean
	all
