cc = gcc

CFLAGS = -Wall -Wextra -Werror

TESTSRCSDIR = ./srcs/
INCLUDES = -I./includes -I./debug -I./x11_key

TESTFILE =	raycasting \
			init \
			cub3d_utils \
			custom_event_handler \
			engine \
			draw \
			error \
			texture \
			debug

### LINUX && MAC COMPILATION DIFFERENT ###
LINUXOBJFLAG = -I/usr/include -I../../mlx_linux -O3
LINUXLINKFLAG = -L../../mlx_linux -lmlx_Linux -L/usr/lib -I../../mlx_linux -lXext -lX11 -lm -lz

MACOBJFLAG = -I../../mlx
MACLINKFLAG = -L../../mlx -lmlx -framework OpenGL -framework AppKit
###										###

GNL_LIBFLAG = -L./gnl -lgnl
LIBFT_LIBFLAG = -L./libft -lft

TESTSRCS = $(addsuffix .c, $(addprefix $(TESTSRCSDIR), $(TESTFILE)))
TESTOBJS = $(TESTSRCS:.c=.o)

NAME = raycasting

$(NAME): $(TESTOBJS)
	$(MAKE) all -C ./libft
	$(MAKE) all -C ./gnl
	$(CC) $(TESTSRCS) -o $(NAME) $(LINUXLINKFLAG) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(INCLUDES) $(LINUXOBJFLAG) -c $< -o $@

all :
	$(NAME)

clean :
	rm -rf $(TESTOBJS)

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
