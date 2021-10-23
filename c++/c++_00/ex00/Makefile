# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 21:26:17 by mchun             #+#    #+#              #
#    Updated: 2021/10/23 21:26:18 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.c=.o)

NAME = megaphone

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean : rm -rf $(NAME)

fclean : rm -rf $(NAME)

re : clean fclean all
