CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

SRCSDIR = ./srcs/
OBJSDIR = ./srcs/

AR = ar -rcs

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		pf_parse.c \
		print_handler_1.c \
		print_handelr_2.c

FILES = $(addprefix $(SRCSDIR), $(SRCS))
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

NAME = libftprintf.a

$(NAME) : $(OBJS)
		$(MAKE) all -C ./libft
		cp ./libft/libft.a $(NAME)
		$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
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
