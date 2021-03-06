cc = gcc

CFLAGS = -Wall -Wextra -Werror

TESTSRCSDIR = ./srcs/

TESTFILE = mlx_test

### LINUX && MAC COMPILATION DIFFERENT ###
LINUXOBJFLAG = -I/usr/include -Imlx_linux -O3
LINUXLINKFLAG = -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MACOBJFLAG = -Imlx
MACLINKFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
###										###

TESTSRCS = $(addsuffix .c, $(addprefix $(TESTSRCSDIR), $(TESTFILE)))
TESTOBJS = $(TESTSRCS:.c=.o)

NAME = test

#LINUX COMPILATION & MAC COMPILATION
%.o: %.c
	$(CC) $(MACOBJFLAG) -c $< -o $@

$(NAME): test.o
	$(CC) test.c -o $(NAME) $(MACLINKFLAG)

all :
	$(NAME)

clean :
	rm -rf test.o
	rm -rf $(NAME)

re :
	clean
	all
