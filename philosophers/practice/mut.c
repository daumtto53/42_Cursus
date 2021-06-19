#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_THREAD	5

static int			shared_resource;
pthread_mutex_t		mutex;

void	*thread_entry(void *arg)
{
	pthread_t	tid;
	int			i;
	int			*a;

	tid = pthread_self();
	i = 0;
	a = (int *)arg;
	while (i < 1000000)
	{
		shared_resource++;
		pthread_mutex_unlock(&mutex);
		printf("tid_%d : %lx\t\t shared_resource : %d\n", *((int *)arg), (unsigned long)tid % 10, shared_resource);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int		main()
{
	shared_resource = 0;

	int			thread_count;
	int			i;
	pthread_t	tid[TOTAL_THREAD];

	thread_count = 0;
	i = 0;

	pthread_mutex_init(&mutex, NULL);
	while (thread_count < TOTAL_THREAD)
	{
		pthread_create(tid + thread_count, NULL, (void *)thread_entry, (void *)&thread_count);
		thread_count++;
	}

	thread_count = 0;
	while (thread_count < TOTAL_THREAD)
	{
		pthread_join(tid[thread_count], NULL);
		thread_count++;
	}
	printf("IN MAIN_THREAD : final shared resource == %d\n", shared_resource);

}
