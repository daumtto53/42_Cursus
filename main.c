#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("ret_val : %d\n", ft_printf("%c\t", '5'));
	printf("ret_val : %d\n", ft_printf("%c\t", 'b'));
	printf("ret_val : %d\n", ft_printf("%c\t", 'A'));
	printf("ret_val : %d\n", ft_printf("%c%c\t", 'a' ,'5'));
	printf("ret_val : %d\n", ft_printf("%c%c\t", 'b', '5'));
}
