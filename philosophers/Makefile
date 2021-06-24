CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDES = -I./includes
ASAN = -g -fsanitize=address

SRCSDIR = ./srcs/

SRCS =		philo_act.c \
			philo_attr_init.c \
			philo_thread_init.c \
			philo_thread_start.c \
			philo_utils.c \
			philo_time.c \
			philo.c

FILES = 	$(addprefix $(SRCSDIR), $(SRCS))

NAME = philo

$(NAME) : $(FILES)
	$(CC) -o $@ $? -lpthread $(INCLUDES)


all : $(NAME)

clean :
	rm -f $(NAME)

fclean :
	rm -f $(NAME)

re : clean fclean all
