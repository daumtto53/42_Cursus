# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 21:26:31 by mchun             #+#    #+#              #
#    Updated: 2021/10/24 13:59:35 by mchun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++ -std=c++98 -pedantic-errors
CPPFLAGS = -Wall -Wextra -Werror

SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

OBJS = $(SRCS:.c=.o)

NAME = PhoneBook

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean : rm -rf $(NAME)

fclean : rm -rf $(NAME)

re : clean fclean all
