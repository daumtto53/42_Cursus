cc = gcc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = ./

FILE =	parse \
		valid \
		parse_1 \
		parse_2 \
		main

GNL_LIBFLAG = -L../raycasting_practice/gnl/ -lgnl
LIBFT_LIBFLAG = -L../raycasting_practice/libft -lft

SCRS = $(addsuffix .c, $(addprefix $(SRCSDIR), $(FILE)))
OBJS = $(SRCS:.c=.o)

NAME = parse

$(NAME) : $(OBJS)
	$(MAKE) all -C ../raycasting_practice/libft
	$(MAKE) all -C ../raycasting_practice/gnl
	$(CC) $(SRCS) -o $(NAME) $(GNL_LIBFLAG) $(LIBFT_LIBFLAG)

%.o : %.c
	$(CC) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)

all_clean: clean fclean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	$(MAKE) fclean -C ./gnl
	$(MAKE) clean -C ./gnl
