cc = gcc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = ./

FILE =	main \
		valid \
		parse_main \
		parse_type \
		valid_map \
		parse_map

GNL_LIBFLAG = -L../raycasting_practice/gnl -lgnl
LIBFT_LIBFLAG = -L../raycasting_practice/libft -lft

SRCS = $(addsuffix .c, $(addprefix $(SRCSDIR), $(FILE)))
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
	$(MAKE) fclean -C ../raycasting_practice/libft
	$(MAKE) clean -C ../raycasting_practice/libft
	$(MAKE) fclean -C ../raycasting_practice/gnl
	$(MAKE) clean -C ../raycasting_practice/gnl
