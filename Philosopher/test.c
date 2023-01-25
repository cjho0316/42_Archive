#include "philo.h"

int main(void)
{
	int i = 0;
	struct timeval tv1;
	struct timeval tv2;

	gettimeofday(&tv1, NULL);
	while(i < 1000000000)
		i++;
	gettimeofday(&tv2, NULL);
	printf("millisec1: tv2 - tv1 : %d\n", tv2.tv_usec-tv1.tv_usec);
	printf("millisec2 tv2 - tv1 : %ld", (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec));

}