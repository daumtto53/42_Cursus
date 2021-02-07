#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
int main()
{

	printf("%d\n", ft_printf("[%-4.*hhu]", 4, -1));
	printf("%d\n", printf("[%-4.*hhu]", 4, -1));



}
