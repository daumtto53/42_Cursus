cc = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

AR = ar -rcs

FILES = get_next_line \
		get_next_line_utils \

SRCSDIR = ./srcs/
SRCS = $(addsuffix .c, $(addprefix $(SRCSDIR), $(FILES)))
OBJS = $(SRCS:.c=.o)

NAME = libgnl.a

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)

re : clean all
