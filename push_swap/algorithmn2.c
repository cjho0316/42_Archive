/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmn2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:23:28 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 09:24:28 by jang-cho         ###   ########.fr       */
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
	free(tmp);
}

void	indexing_all(t_deque *a)
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
}

void	sort_b(t_deque *b, int total)
{
	int		i;
	t_Node	*p;

	p = b->tail;
	i = 0;
	while (i < b->dqcnt && p->data != total)
	{
		i++;
		p = p->prev;
	}
	while (i < b->dqcnt / 2 && i >= 0)
	{
		rrb(b);
		i--;
	}
	while (i >= b->dqcnt / 2 && i < b->dqcnt - 1)
	{
		rb(b);
		i++;
	}
}
