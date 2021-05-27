CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./srcs/
INCLUDES = -I./includes

SRCS_NAME	=	arg_input \
				linked_list \
				main \
				utils \
				inst \
				inst_2

LIBFT_LIBFLAG = -L./libft -lft

SRCS = $(addsuffix .c, $(addprefix $(SRCSDIR), $(SRCS_NAME)))
OBJS = $(SRCS:.c=.o)

NAME = push_swap

$(NAME) : $(OBJS)
			$(MAKE) all -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_LIBFLAG)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean :
	rm -rf $(NAME)
	$(MAKE) fclean -C ./libft

re : clean fclean all
