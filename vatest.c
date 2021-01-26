#include <stdio.h>
#include <stdarg.h>

void	va_test2(va_list *ap)
{
	int i;
	char c;
	char *str;
	double d;

	i = va_arg(*ap, int);
	c = va_arg(*ap, int);
	c = (char)c;
	str = va_arg(*ap, char *);
	d = va_arg(*ap, double);

	printf("%d %c %s %lf\n", i, c, str, d);
}

void	va_test(int i, ...)
{
	va_list ap;
	va_start(ap, i);
	va_test2(&ap);
	va_end(ap);
}

int		main()
{
	va_test(1, 1,'c',"string",0.1);

	printf("%d\n", 11 & (~2));
}
