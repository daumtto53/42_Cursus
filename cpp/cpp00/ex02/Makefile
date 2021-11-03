# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:27:55 by mchun             #+#    #+#              #
#    Updated: 2021/10/26 13:28:47 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS = Account.cpp \
		test.cpp

OBJS = $(SRCS:.c=.o)

NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean : rm -rf $(NAME)

fclean : rm -rf $(NAME)

re : clean fclean all
