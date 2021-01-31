#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("len : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n",8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647));
	printf("len : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n",8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647));
	// printf(" --- Return : %d\n", ft_printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", ft_printf("%d\n", -2147483648));
}
