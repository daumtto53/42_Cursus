#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int main()
{
	printf("%d\n", ft_printf("[%#x]", -1234));
	printf("%d\n", printf("[%#x]", -1234));
	printf("%d\n", ft_printf("[%#X]", -1234));
	printf("%d\n", printf("[%#X]", -1234));
	ft_putchar_fd('\n', 1);
}
