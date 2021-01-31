#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("len : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n",8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 0xfffffff4, 0xFFFFFFF4));
	printf("len : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %lu, %x, %X\n",8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 0xfffffff4, 0xFFFFFFF4));
	// printf(" --- Return : %d\n", ft_printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", ft_printf("%d\n", -2147483648));
}
