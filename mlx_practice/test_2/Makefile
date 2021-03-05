cc = gcc

CFLAGS = -Wall -Wextra -Werror

TESTSRCSDIR = .

TESTFILE = test

TESTSRCS = $(addsuffix .c, $(addprefix $(TESTSRCSDIR), $(TESTFILE)))
TESTOBJS = $(TESTSRCS:.c=.o)

NAME = test

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): test.o
	$(CC) test.c -o $(NAME) -L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all :
	$(NAME)

clean :
	rm -rf test.o
	rm -rf $(NAME)

re :
	clean
	all
