#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int		main()
{
	int	a;
	int	*p;
	p = &a;
	ft_printf("-->|%-15p|<--\n", NULL);
	ft_printf("-->|%-16.p|<--\n", p);
	ft_printf("-->|%-16p|<--\n", p);
	ft_printf("-->|%-16.p|<--\n", p);
	ft_printf("-->|%-16.p|<--\n", p);

	ft_printf("-->|%-15.p|<--\n", p);
	ft_printf("-->|%-15p|<--\n", p);
	ft_printf("-->|%-16.p|<--\n", p);
	ft_printf("-->|%-16.p|<--\n", p);
	ft_printf("-->|%-16p|<--\n", p);

	printf("\n--------------------\n");
	printf("-->|%-15p|<--\n", NULL);
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16p|<--\n", p);
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16.p|<--\n", p);

	printf("-->|%-15.p|<--\n", p);
	printf("-->|%-15p|<--\n", p);
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16.p|<--\n", p);
	printf("-->|%-16p|<--\n", p);

}
