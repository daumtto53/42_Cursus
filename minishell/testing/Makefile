# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 16:14:26 by mchun             #+#    #+#              #
#    Updated: 2021/08/29 16:20:27 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
CFLAGS = -Wall -Wextra -Werror

SRCS =	env.c \
		env.h \
		main.c

OBJS =  $(SRCS:.c=.o)

NAME = ./env_test

$(NAME) : $(OBJS)
	$(MAKE) all -C ../../libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lft -L../../libft

all : $(NAME)
