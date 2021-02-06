#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
int main()
{
	int	a;
	a = 1;

	printf("%d\n", ft_printf("%12d\n", -12));
	printf("%d\n", printf("%12d\n", -12));
	printf("%d\n", a);
}
