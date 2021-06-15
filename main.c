#include <stdio.h>
#include "includes/ft_printf.h"

int		main()
{
	printf("%d\n\n",ft_printf("%0*.*d\n", 3, 2, 8));
	printf("%d\n\n",ft_printf("%d\n", 3123));
}
