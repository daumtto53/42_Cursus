# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:22:34 by mchun             #+#    #+#              #
#    Updated: 2021/11/13 13:44:56 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
		Dog.cpp \
		Cat.cpp \
		Animal.cpp \
		Brain.cpp

OBJS = $(SRCS:.c=.o)

NAME = ex01

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : clean fclean all
