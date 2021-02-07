#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int main()
{
	printf("%d\n", ft_printf("[%1.x]", 0xffffff79));
	printf("%d\n", printf("[%1.x]", 0xffffff79));
	printf("%d\n", ft_printf("[%#X]", -1234));
	printf("%d\n", printf("[%#X]", -1234));
	ft_putchar_fd('\n', 1);
}
