# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 02:04:18 by mchun             #+#    #+#              #
#    Updated: 2021/10/29 15:07:49 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow

SRCS = ClapTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp \
		DiamondTrap.cpp \
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
