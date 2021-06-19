#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

void	*thread_entry(void *arg)
{
	int			i;
	pthread_t	tid;
	int			thread_number;

	tid = pthread_self();
	thread_number = *((int *)arg);
	i  = 0;
	while (i < 7)
	{
		printf("new_thread tid : %lx\t\t incremented : %d\n", (unsigned long)tid - 0x700000000000, i);
		i++;
	}
	if (i ==7)
		printf("tid : %lx completed\n", (unsigned long)tid - 0x700000000000);
	return NULL;
}

int		main()
{
	pthread_t	tid[5];
	int			thread_count;
	int			i;

	i = 0;
	thread_count = 0;

	while (thread_count < 5)
	{
		pthread_create(tid + thread_count, NULL, (void *)thread_entry, (void *)&thread_count);
		thread_count++;
	}
	while (i < 10)
	{
		printf("main_thread's tid : %lx\t\t, incremented : %d\n", (unsigned long)pthread_self(), i);
		i++;
	}
	i = 0;
	thread_count = 0;
	while (thread_count < 5)
	{
		pthread_join(tid[thread_count], NULL);
		thread_count++;
	}
	while (i < 5)
	{
		printf("MAIN_THREAD : subthread id : %lx\t", (unsigned long)tid[i] - 0x700000000000);
		i++;
	}
	printf("\n");
}
