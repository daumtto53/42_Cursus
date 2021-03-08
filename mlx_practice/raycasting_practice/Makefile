cc = gcc

CFLAGS = -Wall -Wextra -Werror

TESTSRCSDIR = ./srcs/
INCLUDES = -I./includes -I./debug

TESTFILE =	raycasting \
			init \
			cub3d_utils \
			debug

### LINUX && MAC COMPILATION DIFFERENT ###
LINUXOBJFLAG = -I/usr/include -I../../mlx_linux -O3
LINUXLINKFLAG = -L../../mlx_linux -lmlx_Linux -L/usr/lib -I../../mlx_linux -lXext -lX11 -lm -lz

MACOBJFLAG = -I../../mlx
MACLINKFLAG = -L../../mlx -lmlx -framework OpenGL -framework AppKit
###										###

TESTSRCS = $(addsuffix .c, $(addprefix $(TESTSRCSDIR), $(TESTFILE)))
TESTOBJS = $(TESTSRCS:.c=.o)

NAME = raycasting

$(NAME): $(TESTOBJS)
	$(CC) $(TESTSRCS) -o $(NAME) $(LINUXLINKFLAG)

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(INCLUDES) $(LINUXOBJFLAG) -c $< -o $@

all :
	$(NAME)

clean :
	rm -rf raycasting.o
	rm -rf $(NAME)

re :
	clean
	all
