#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	va_test2(va_list *ap)
{
	int i;
	char c;
	char *str;
	double d;
	void *p;

	i = va_arg(*ap, int);
	c = va_arg(*ap, int);
	c = (char)c;
	str = va_arg(*ap, char *);
	d = va_arg(*ap, double);
	p = va_arg(*ap, void *);
	printf("%d %c %s %lf %p\n", i, c, str, d, p);
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
	int		a;
	char *b = "%";
	va_test(1, 1,'c',"string",0.1, &a);
	write(1, b, 2);
	printf("%d\n", 11 & (~2));
}
