# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 21:29:07 by mchun             #+#    #+#              #
#    Updated: 2021/07/02 13:46:43 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
OBJS =		$(FILES:.c=.o)

NAME = philo

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -lpthread

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : clean fclean all
