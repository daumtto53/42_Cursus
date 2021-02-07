#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int main()
{
	printf("%d\n", ft_printf("[%+.i]", 0));
	printf("%d\n", printf("[%+.i]", 0));

	printf("%d\n", ft_printf("[%#04.*x]", -4, 13));
	printf("%d\n", printf("[%#04.*x]", -4, 13));
	printf("%d\n", ft_printf("[%#X]", -1234));
	printf("%d\n", printf("[%#X]", -1234));
	ft_putchar_fd('\n', 1);
}
