#include "./libft.h"

void	ft_split_free(char **splitptr)
{
	int		i;

	i = -1;
	while (!splitptr[++i])
		free(splitptr[i]);
	free(splitptr);
}
