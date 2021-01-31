#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("len : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n",3, 8, 3, -12, 3, 123456789, 3, 0, 3, -12345678, 3, 97, 3, -2147483648, 3, 2147483647));
	printf("len : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*ld, %0*d\n",3, 8, 3, -12, 3, 123456789, 3, 0, 3, -12345678, 3, 97, 3, -2147483648, 3, 2147483647));
	// printf(" --- Return : %d\n", ft_printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", ft_printf("%d\n", -2147483648));
}
