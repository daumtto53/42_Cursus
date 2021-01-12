#include <stdio.h>
#include "get_next_line.h"
#include "fcntl.h"
#include "sys/types.h"

int		main()
{
	char	*line;
	int		fd;

	printf("GNL #########\tBUFFER_SIZE : %d\t##############\n", BUFFER_SIZE);
	if ((fd = open("test.txt", O_RDWR, 0644)) <= 0)
	{
		perror("open error\n");
		return (-1);
	}

	int i;
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%d th line : %s\n", i++, line);
		free(line);
		line = NULL;
	}
	return (0);
}

