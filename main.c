#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	ft_printf("%0*d\n",4, 8);
	// printf(" --- Return : %d\n", ft_printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", printf("%*.*d\n",4, 4, -12));
	// printf(" --- Return : %d\n", ft_printf("%d\n", -2147483648));
}
