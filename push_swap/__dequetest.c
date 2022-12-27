#include <stdio.h>
#include "deque.h"

int	main(void)
{
	int		v;
	t_deque	*a;

	a = malloc(sizeof(t_deque));
	dequeinit(a);
	dqaddfirst(a, 1);
	dqaddfirst(a, 2);
	dqaddfirst(a, 3);
	dqaddfirst(a, 4);

	v = dqchkfirst(a);
	printf("head : %d\n", v);
	v = dqchklast(a);
	printf("last : %d\n", v);

	printf("the count is: %d\n", a->dqcnt);
	printf("%d\n", dqpopfirst(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d\n", dqpoplast(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d\n", dqpopfirst(a));
	printf("the count is: %d\n", a->dqcnt);
	printf("%d\n", dqpoplast(a));
}
