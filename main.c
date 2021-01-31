#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	int	a;
	printf(" --- Return : %d\n", ft_printf("[%-15p]\n", &a));
	printf(" --- Return : %d\n", printf("[%-15p]\n", &a));
}
