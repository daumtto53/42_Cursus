#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
int main()
{
	unsigned long long 	a;

	a = 123456789LL;
	a &= UCHAR_MAX;
	int		p;
 	printf("-->|%-16.p|<--\n", &p);
	ft_printf("-->|%-16.p|<--\n", &p);


}
