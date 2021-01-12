#include <stdio.h>
#include "get_next_line.h"
#include "fcntl.h"
#include "sys/types.h"

int		main()
{
	char	**line;
	int		fd;

	if ((fd = open("test.txt", O_RDWR, 0644)) <= 0)
	{
		perror("open error\n");
		return (-1);
	}
	if (get_next_line(fd, line) < 0)
	{
		printf("get_next_line_error\n");
		return (-1);
	}
	printf("%s\n", *line);
	return (0);
}
