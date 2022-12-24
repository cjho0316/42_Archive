/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmn1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:23:28 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/25 03:30:20 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

void	under_five(t_deque *a, t_deque *b)
{
	while (a->dqcnt > 3)
	{
		while (dqchkfirst(a) >= get_mid_result(a))
		{
			ra(a);
		}
		pb(a, b);
	}
	if (a->dqcnt == 2 || a->dqcnt == 3)
	{
		sort_two_three(a);
	}
	while (b->dqcnt > 0)
	{
		pa(a, b);
	}
	if (dqchkfirst(a) > dqchklast(a))
	{
		sa(a);
	}
}

void	over_five(t_deque *a, t_deque *b)
{
	int	i;
	int	x;
	int	chunk;

	i = 0;
	x = a->dqcnt;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	atob(a, b, chunk, i);
	btoa(a, b);
}

void	atob(t_deque *a, t_deque *b, int chunk, int i)
{
	int	length;

	length = a->dqcnt - 1;
	while (a->dqcnt != 0)
	{
		if (dqchkfirst(a) <= i)
		{
			pb(a, b);
			i++;
		}
		else if (dqchkfirst(a) > i && dqchkfirst(a) <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (dqchkfirst(a) > (i + chunk)) // 최악의 경우일때 상정
		{
			if (i < a->dqcnt / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
		length--;
	}
}

void	btoa(t_deque *a, t_deque *b)
{
	int	length;

	length = b->dqcnt - 1;
	while (b->dqcnt != 0)
	{
		sort_b(b, length);
		pa(a, b);
		length--;
	}
}

void	sorting_deque(t_deque *deq1, t_deque *deq2)
{
	if (deq1->dqcnt <= 5)
	{
		under_five(deq1, deq2);
	}
	else
	{
		over_five(deq1, deq2);
	}
}