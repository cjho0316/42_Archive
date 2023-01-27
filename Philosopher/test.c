#include "philo.h"

void ft_intermission(long long wait_time, t_info info)
{
	long long		past;
	long long		curr;

	past = ft_gettime();
	while (!info.finish)
	{
		curr = ft_gettime();
		if (curr-past >= wait_time)
			break;
	}
}

long long ft_gettime(void)
{
	struct timeval 	tv1;
	long long		time;
	
	gettimeofday(&tv1, NULL);
	time = tv1.tv_sec % 10000 * 1000000 + tv1.tv_usec;
	return (time);
}

int ft_mutex_print(t_info info, int id, char *str)
{
	long long cur;
	
	cur = ft_gettime();
	pthread_mutex_lock(&(info.print));
	if (info.finish != 1)
		printf("%lld, %d, %s\n",(cur-info.start_time), id + 1, str);
	pthread_mutex_unlock(&(info.print));
	return (0);
}

int main(void)
{
	t_info	info;	
	int i = 0;
	int s;
	int e;
	int l;

	
	while (i < 1)
		i++;
	l = ft_gettime();
	// printf("%d start time\n", l);
	ft_intermission(100000, info);
	e = ft_gettime();
	printf("%d leantime\n", e-l);

	// printf("%d lean time double check\n", e-l);
}