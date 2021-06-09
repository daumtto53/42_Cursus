CC = gcc
CFLAG = -Werror -Wextra -Wall
INCLUDES = -I./includes/
LIBFT_FLAG = -L./libft -lft

FILE =		initiate \
			main \
			redirection

SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(FILE)))
OBJS = $(SRCS:.c=.o)

NAME = pipex

$(NAME) : $(SRCS)
	$(MAKE) all -C ./libft
	$(CC) $(CFLAG) -o $@ $^ $(LIBFT_FLAG) $(INCLUDES)

%.o : %.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $<

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean :
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : clean fclean all

output_clean:
	rm -rf output_*

.PHONY = all clean fclean
