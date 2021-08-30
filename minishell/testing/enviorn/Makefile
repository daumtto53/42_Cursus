# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 16:14:26 by mchun             #+#    #+#              #
#    Updated: 2021/08/30 21:30:43 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

SRCS =	env.c \
		main.c

OBJS =  $(SRCS:.c=.o)

NAME = env

$(NAME) : $(OBJS)
	$(MAKE) all -C ../../../libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lft -L../../../libft

all : $(NAME)

clean :
	rm -rf *.o
