#include <stdio.h>
#include "deque.h"

int	main(void)
{
	t_deque	*a;

	a = malloc(sizeof(t_deque));
	dequeinit(a);
	dqaddfirst(a, 1);
	dqaddfirst(a, 2);
	dqaddfirst(a, 3);
	dqaddfirst(a, 4);

	printf("the count is: %d\n", a->dqcnt);
	printf("%d", dqpopfirst(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d", dqpoplast(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d", dqpopfirst(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d", dqpoplast(a));
}
