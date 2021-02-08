#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"

int main()
{
  int c;
  long x;
  ft_printf("geeks for %n geeks ", &c);
  printf("%d\n", c);
  ft_printf("geeks for %ln geeks ", &x);
  printf("%ld\n", x);
  return 0;
}
