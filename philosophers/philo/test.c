
#include <stdio.h>
#include "./includes/philo.h"

int		main(int	argc, char **argv)
{
	struct timeval	tv;
	uint			time;
	uint64_t			time_past;

	gettimeofday(&tv, NULL);
	printf("sec : %ld\tusec : %d\n", tv.tv_sec, tv.tv_usec);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("tv_time ; %ld\n", time);
	usleep(1000 * 1000 * 2);
	gettimeofday(&tv, NULL);
	time_past = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("tv_time ; %ld\n", time_past);
	printf("intersection : %ld\n", time_past - time);
}
