# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 21:29:07 by mchun             #+#    #+#              #
#    Updated: 2021/07/30 17:47:26 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDES = -I./includes
ASAN = -g -fsanitize=address

SRCSDIR = ./srcs/
SRCSDIR_LINUX = ./linux/

SRCS =		philo_act.c \
			philo_attr_init.c \
			philo_philosopher.c \
			philo_utils.c \
			philo_time.c \
			philo.c

FILES = 		$(addprefix $(SRCSDIR), $(SRCS))
FILES_LINUX =	$(addprefix $(SRCSDIR_LINUX), $(SRCS))

OBJS =			$(FILES:.c=.o)
OBJS_LINUX =	$(FILES_LINUX:.c=.o)

NAME = philo

NAME_LINUX = philo_linux

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -lpthread

$(NAME_LINUX) : $(OBJS_LINUX)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -lpthread

all : $(NAME)

all_linux : $(NAME_LINUX)

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_LINUX)

fclean :
	rm -f $(NAME)
	rm -f $(NAME_LINUX)

re : clean fclean all
