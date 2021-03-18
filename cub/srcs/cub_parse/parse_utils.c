#include "../../includes/parse.h"

void	free_all_ptr(char **splitstr, char *str)
{
	free(str);
	ft_split_free(splitstr);
}
