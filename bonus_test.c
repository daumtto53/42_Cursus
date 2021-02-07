#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
int main()
{
	unsigned long long 	a;

	a = 123456789LL;
	a &= UCHAR_MAX;

	printf("%d\n", ft_printf("%12.x\n", 123456789));
	printf("%d\n", printf("%12.6x\n", 123456789));
}
