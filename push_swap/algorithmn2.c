/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmn2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:23:28 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/25 04:46:17 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

// void	indexing_arr(t_deque *a)
// {
// 	int	i;
// 	int	j;
// 	int	*tmp;

// 	i = 0;
// 	tmp = (int *)malloc(sizeof(int) * a->length);
// 	if (tmp == NULL)
// 		occur_error(1);
// 	while (i < a->length)
// 	{
// 		j = 0;
// 		tmp[i] = 0;
// 		while (j < a->length)
// 		{
// 			if (a->arr[i] > a->arr[j])
// 			{
// 				tmp[i]++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(a->arr);
// 	a->arr = NULL;
// 	a->arr = tmp;
// }


// int	get_mid_result(t_deque *p)
// {
// 	int	i;
// 	int	j;
// 	int	pb;

// 	i = 0;
// 	while (i < p->dqcnt)
// 	{
// 		j = 0;
// 		pb = 0;
// 		while (j < p->dqcnt)
// 		{
// 			if (p->arr[j] - p->arr[i] > 0)
// 			{
// 				pb++;
// 			}
// 			j++;
// 		}
// 		if (pb == 2) // b 스택에 2개가 쌓였을 경우
// 		{
// 			return (p->arr[i]);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

void	sort_two_three(t_deque *p)
{
	t_Node	*mid;

	mid = p->head->next->data;
	// if (check_input(p)) 정렬되어있는지 상태체크
	// 	return ;
	if (p->dqcnt == 2)
		sa(p);
	else if (dqchkfirst(p) > dqchklast(p) && mid > dqchkfirst(p))
	{
		sa(p);
		ra(p);
	}
	else if (dqchklast(p) > mid && dqchkfirst(p) > dqchklast(p))
		sa(p);
	else if (dqchklast(p) > dqchkfirst(p) && mid > dqchklast(p))
		rra(p);
	else if (dqchkfirst(p) > mid && dqchklast(p) > dqchkfirst(p))
		ra(p);
	else
	{
		sa(p);
		rra(p);
	}
}

void	sort_b(t_deque *b, int length)
{
	int	i;

	i = 0;
	while (i < b->dqcnt && b->head->data != length)
	{
		i++;
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
