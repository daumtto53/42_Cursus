CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes -I./libft

SRCSDIR = ./srcs/
OBJSDIR = ./srcs/

AR = ar -rcs

SRCS =	ft_printf.c \
		pf_parse.c \
		print_handler_1.c \
		print_handler_2.c

LIBFT = -L./libft -lft

FILES = $(addprefix $(SRCSDIR), $(SRCS))
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

NAME = libftprintf.a

$(NAME) : $(OBJS)
		$(MAKE) all -C ./libft
		cp libft/libft.a $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
