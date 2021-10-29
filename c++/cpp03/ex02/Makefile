# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 02:04:18 by mchun             #+#    #+#              #
#    Updated: 2021/10/29 13:02:41 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS = ClapTrap.cpp \
		FragTrap.cpp \
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
