#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	printf("ret_val : %d\n", ft_printf("%-20.5s\t", "1ADSADSDD"));
	printf("ret_val : %d\n", ft_printf("%20.3s\t", "safsdffasdf"));
	printf("ret_val : %d\n", ft_printf("%20s\t", "dfasdfsdfdf"));
	printf("ret_val : %d\n", ft_printf("%20s\t", "1312323213123"));
	printf("ret_val : %d\n", printf("%-20.5s\t", "1ADSADSDD"));
	printf("ret_val : %d\n", printf("%20.3s\t", "safsdffasdf"));
	printf("ret_val : %d\n", printf("%20s\t", "dfasdfsdfdf"));
	printf("ret_val : %d\n", printf("%20s\t", "1312323213123"));
}
