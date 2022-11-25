/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:12:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/11/25 22:53:41 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// enque(), deque() (스택간 또는 스택내부에서 삽입/삭제과정 거치는 함수)
// swap(), rotate(), reverse() (말그대로 deque의 동작 + enque/deque 함수로)구현
// ------------------------------------------------------------------

#include "deque.h"

void	swap(t_deque *p)
{
	t_Node	*s;

	if (dqisempty(p) || p->dqcnt == 1)
		return ;
	s = p->head->prev;
	p->head->prev = p->head->next;
	p->head->next = s;
}
// 이거 마즘??
// tmp = stack->next;
// stack->next = stack->next->next;
// tmp->next = stack;
// stack = tmp;

void	push(t_deque *from, t_deque *to)
{
	int		pop;

	if (dqisempty(from))
		return ;
	pop = dqpopfirst(from);
	dqaddfirst(to, pop);
}

void	rotate(t_deque *p)
{
	int	data;

	if (dqisempty(p))
		return ;
	data = dqpoplast(p);
	dqaddfirst(p, data);
}

void	reverse_rotate(t_deque *p)
{
	int	data;

	if (dqisempty(p))
		return ;
	data = dqpopfirst(p);
	dqaddlast(p, data);
}
