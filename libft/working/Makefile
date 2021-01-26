CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES =	ft_memmove.c \
		ft_strnstr.c \
		ft_strlen.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_memset.c \
		ft_bzero.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isspace.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \

SRCS = $(FILES)
OBJS = $(SRCS:.c=.o)

NAME = libft.a

$(NAME) : $(OBJS)
		ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : clean all

# Remove this When submitting.
so:
	$(CC) -fPIC $(CFLAGS) -c libft.h $(SRCS)
	$(CC) -shared  -o libft.so $(OBJS)

soclean :
	rm -f libft.so

allclean: soclean fclean clean

.PHONY  : all clean fclean
