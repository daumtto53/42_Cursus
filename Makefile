cc = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR_BMP = ./srcs/cub_bmp/
SRCSDIR_PARSE = ./srcs/cub_parse/
SRCSDIR_RAY = ./srcs/cub_ray/
INCLUDES = -I./includes -I./debug -I./x11_key -I./parse

FILE_BMP =		bmp_maker

FILE_RAY =		raycasting_2 \
				init \
				cub3d_utils \
				custom_event_handler_1 \
				custom_event_handler_2 \
				engine \
				draw_texture \
				draw_untexture \
				draw_sprite \
				error \
				texture \
				main \

FILE_RAY_BASE = raycasting_1 \
				raycasting_sprite

FILE_RAY_BONUS =	raycasting_1_bonus \
					raycasting_sprite_bonus

FILE_PARSE =	valid \
				parse_main \
				parse_type \
				valid_map \
				valid_map_dfs \
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

SRCS_PARSE = $(addsuffix .c, $(addprefix $(SRCSDIR_PARSE), $(FILE_PARSE)))
OBJS_PARSE = $(SRCS_PARSE:.c=.o)

NAME = cub3d

BONUS = cub3d_bonus

$(NAME): $(OBJS_BMP) $(OBJS_RAY) $(OBJS_PARSE) $(OBJS_RAY_BASE)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(MAKE) all -C ./mlx_linux
	cp ./mlx_linux/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS_BMP) $(SRCS_PARSE) $(SRCS_RAY) $(SRCS_RAY_BASE) -o $(NAME) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)


$(BONUS) : $(OBJS_BMP) $(OBJS_RAY) $(OBJS_PARSE) $(OBJS_RAY_BONUS)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(MAKE) all -C ./mlx_linux
	cp ./mlx_linux/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS_BMP) $(SRCS_PARSE) $(SRCS_RAY) $(SRCS_RAY_BONUS) -o $(NAME) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LINUXOBJFLAG) -c $< -o $@

all : $(NAME)

bonus: $(BONUS)

clean :
	rm -rf $(OBJS_BMP) $(OBJS_PARSE) $(OBJS_RAY) $(OBJS_RAY_BONUS) $(OBJS_RAY_BASE)

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
	clean
	all
