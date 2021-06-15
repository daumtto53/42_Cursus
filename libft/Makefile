CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./
OBJSDIR = ./
BONUSDIR = ./

PART_1 =	ft_memmove.c \
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
			ft_calloc.c

PART_2 =	ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c

CUSTOM =	ft_isspace.c \
			ft_numtox.c \
			ft_utox.c \
			ft_utoa.c \
			ft_ltoa.c \
			ft_putnbr_base_fd.c \
			ft_putunbr_base_fd.c \
			ft_digitlen_base.c \
			ft_digitlen_ubase.c



BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

FILES = $(PART_1) $(PART_2) $(CUSTOM)
SRCS = $(addprefix $(SRCSDIR), $(FILES))
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))
BONUSSRCS = $(addprefix $(BONUSDIR), $(BONUS))
BONUSOBJS = $(BONUSSRCS:.c=.o)

NAME = libft.a

$(NAME) : $(OBJS)
		ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(OBJS) $(BONUSOBJS)
	ar rc $(NAME) $^

clean :
	rm -f $(OBJS) $(BONUSOBJS)

fclean :
	rm -f $(NAME)

re : clean all

# Remove this When submitting.
so:
	$(CC) -fPIC $(CFLAGS) -c libft.h $(SRCS) $(BONUSSRCS)
	$(CC) -shared  -o libft.so $(OBJS) $(BONUSOBJS)

soclean :
	rm -f libft.so

allclean: soclean fclean clean

.PHONY  : all clean fclean so soclean allclean re bonus
