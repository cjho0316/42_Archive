/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmn2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:23:28 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/28 14:25:46 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

void	drop_and_make(t_deque *a, int total, int *tmp)
{
	int	i;

	i = -1;
	while (++i < total)
		dqpoplast(a);
	i = -1;
	while (++i < total)
	{
		dqaddlast(a, tmp[i]);
	}
}

void	indexing_all(t_deque *a) // calloc대체하기
{
	int		i;
	int		j;
	int		*tmp;
	t_Node	*p;
	t_Node	*q;

	i = -1;
	p = a->head;
	tmp = (int *)malloc(sizeof(int) * a->dqcnt);
	if (tmp == NULL)
		p_error(1);
	printf("dqcnt1 : %d\n", a->dqcnt);
	while (++i < a->dqcnt)
	{
		j = -1;
		tmp[i] = 0;
		q = a->head;
		while (++j < a->dqcnt)
		{
			if (p->data > q->data)
				tmp[i]++;
			q = q->next;
		}
		p = p->next;
	}
	drop_and_make(a, a->dqcnt, tmp);
	free(tmp);
}

int	get_mid_result(t_deque *a)
{
	int		i;
	int		j;
	int		k;
	t_Node	*p;
	t_Node	*q;

	i = -1;
	p = a->head;
	while (++i < a->dqcnt)
	{
		k = 0;
		j = 0;
		q = a->head;
		while (j < a->dqcnt)
		{
			if (q->data - p->data > 0)
				k++;
			j++;
			q = q->next;
		}
		if (k == 2)
			return (p->data);
		p = p->next;
	}
	return (1);
}

// 1 3 2 -> rra / sa ra
// 2 1 3 -> ra / sa
// 2 3 1 -> sa ra / rra
// 3 1 2 -> sa / ra
// 3 2 1 -> 바깥(sa) / sa rra
void	sort_two_three(t_deque *p)
{
	int	mid;

	mid = p->head->next->data;
	if (aligned_check(p))
		return ;
	if (p->dqcnt == 2)
		sa(p);
	else if (dqchklast(p) > dqchkfirst(p) && mid > dqchklast(p))
	{
		sa(p);
		ra(p);
	}
	else if (dqchkfirst(p) > mid && dqchklast(p) > dqchkfirst(p))
		sa(p);
	else if (dqchkfirst(p) > dqchklast(p) && mid > dqchkfirst(p))
		rra(p);
	else if (dqchklast(p) > mid && dqchkfirst(p) > dqchklast(p))
		ra(p);
	else if (dqchkfirst(p) > mid && mid > dqchklast(p))
	{
		sa(p);
		rra(p);
	}
	printf("first: %d\n", dqchkfirst(p));
	printf("second: %d\n", p->head->next->data);
	printf("last: %d\n", p->head->next->next->data);
}

void	sort_b(t_deque *b, int total)
{
	int		i;
	t_Node	*p;
	
	// while (p->data != total)
	// {
	// 	printf("this is b data: ");
	// 	printf("%d \n", p->data);
	// 	p = p->next;
	// }
	p = b->tail;
	i = 0;
	while (i < b->dqcnt && p->data != total)
	{
		// printf("val1: %d\n", i);
		// printf("arr1: %d\n", p->data);
		i++;
		p = p->prev;
	}
	while (i < b->dqcnt / 2 && i >= 0)
	{
		rrb(b);
		// printf("val2: %d\n", i);
		i--;
	}
	while (i >= b->dqcnt / 2 && i < b->dqcnt - 1)
	{
		rb(b);
		// printf("val3: %d\n", i);
		i++;
	}
}