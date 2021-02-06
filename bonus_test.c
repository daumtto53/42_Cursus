#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
int main()
{

	printf("%d\n", ft_printf("%12.6d\n", -12));
	printf("%d\n", printf("%12.6d\n", -12));
}
