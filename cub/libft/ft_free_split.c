#include "libft.h"

void	ft_split_free(char **splitstr)
{
	int		i;

	i = 0;
	while (splitstr[i])
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
}
