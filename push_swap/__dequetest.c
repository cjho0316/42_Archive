#include <stdio.h>
#include "deque.h"

int	main(void)
{
	int		v;
	t_deque	*a;
	t_deque	*b;

	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	dequeinit(a);
	dequeinit(b);

	dqaddlast(a, 1);
	dqaddlast(a, 2);
	dqaddlast(a, 3);
	dqaddlast(a, 4);
	v = dqchkfirst(a);
	printf("addhead : %d\n", v);
	v = dqchklast(a);
	printf("addlast : %d\n", v);

	pb(a, b);
	pb(a, b);
	v = dqchkfirst(b);
	printf("pb head : %d\n", v);
	v = dqchklast(b);
	printf("pb last : %d\n", v);
	pa(a, b);
	pa(a, b);
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
