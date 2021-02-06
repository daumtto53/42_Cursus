#include <stdio.h>
#include "includes/ft_printf.h"

int		main()
{
	printf("%d\n\n",ft_printf("%*d\n", 13, 3123));
	printf("%d\n\n",ft_printf("%d\n", 3123));
}
