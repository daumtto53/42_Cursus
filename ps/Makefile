CC = gcc
CFLAGS = -Wall -Wextra -Werror
ASAN = -g -fsanitize=address

SRCSDIR = ./srcs/
SRCSDIR_BONUS = ./srcs_bonus/
INCLUDES = -I./includes

SRCS_NAME	=	arg_input \
				linked_list \
				utils \
				inst \
				inst_2 \
				pivot_array \
				pivot_array_2 \
				sort_a_less_n_equal_3 \
				sort_a \
				sort_b_less_n_equal_3 \
				sort_b \
				sort_utils

SRCS_BONUS_NAME =	checker	\
					checker_utils \
					checker_inst \
					checker_inst_2


LIBFT_LIBFLAG = -L./libft -lft
GNL_LIBFLAG = -L./gnl -lgnl
PUSH_SWAP_LIBFLAG = -L./ -lpush_swap

SRCS = $(addsuffix .c, $(addprefix $(SRCSDIR), $(SRCS_NAME)))
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = $(addsuffix .c, $(addprefix $(SRCSDIR_BONUS), $(SRCS_BONUS_NAME)))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap

BONUS = checker

$(NAME) : $(OBJS) ./srcs/main.o
			$(MAKE) all -C ./libft
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) ./srcs/main.c $(SRCS) $(LIBFT_LIBFLAG)

$(BONUS) : $(OBJS_BONUS) $(OBJS)
			$(MAKE) all -C ./libft
			$(MAKE) all -C ./gnl
			$(MAKE) $(NAME) -C ./
			ar -rcs libpush_swap.a $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS) $(SRCS_BONUS) $(LIBFT_LIBFLAG) $(GNL_LIBFLAG) $(PUSH_SWAP_LIBFLAG)


%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./gnl

fclean :
	rm -rf $(NAME)
	rm -rf $(BONUS)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./gnl
	rm -rf libpush_swap.a

re : clean fclean all
