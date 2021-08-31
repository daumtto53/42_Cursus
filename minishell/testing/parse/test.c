#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int		main(int argc, char **argv, char **envp)
{
	int	status;
	char	*s[2] = {"ls", NULL};

	if (fork() == 0)
	{
		execve("/bin/ls", s, envp);
	}
	wait(&status);
	return (0);
}
