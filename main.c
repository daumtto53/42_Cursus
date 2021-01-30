#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("ret_val : %d\n", ft_printf("%.d\t", 0));
	printf("ret_val : %d\n", ft_printf("%d\t", 0));
	printf("ret_val : %d\n", ft_printf("%3d\t", -123));

	printf("ret_val : %d\n", printf("%.d\t", 0));
	printf("ret_val : %d\n", printf("%d\t", 0));
	printf("ret_val : %d\n", printf("%3d\t", -123));
}
