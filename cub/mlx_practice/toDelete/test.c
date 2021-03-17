#include <stdio.h>

struct b
{
	int x;
};

struct c
{
	int x;
};

struct a
{
	struct b b1;
	struct c *c1;
};

void	change_struct_struct(struct a *a1)
{
	a1->b1.x = 3;
}

int		main()
{
	struct a a1;
	a1.b1.x = 1;
	printf("%d\n", a1.b1.x);
	a1.b1.x = 2;
	printf("%d\n", a1.b1.x);
	change_struct_struct(&a1);
	printf("%d\n", a1.b1.x);

}
