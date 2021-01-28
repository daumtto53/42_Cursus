CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./
OBJSDIR = ./
BONUSDIR = ./

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		pf_parse.c \
		print_handler_1.c \
		print_handelr_2.c

FILES = $(addprefix $(SRCSDIR), $(SRCS))
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

NAME = libft
