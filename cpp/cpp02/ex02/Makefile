# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 15:46:57 by mchun             #+#    #+#              #
#    Updated: 2021/10/28 16:37:07 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS = Fixed.cpp \
		main.cpp

OBJS = $(SRCS:.c=.o)

NAME = fixed

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : clean fclean all
