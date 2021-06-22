#include <pthread.h>
#include <stdio.h>

void		*thread_func(void *arg)
{
	int		n = *(int *)arg;
	printf("%d\n", n);
	return (NULL);
}

int			main()
{
	pthread_t	tid;
	int		i;

	i = 20;
	pthread_create(&tid, NULL, (void *)thread_func, (void *)&i);
	i++;
	pthread_join(tid, NULL);
	return (0);
}
