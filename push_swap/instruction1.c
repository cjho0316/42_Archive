/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:12:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/27 12:14:25 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// enque(), deque() (스택간 또는 스택내부에서 삽입/삭제과정 거치는 함수)
// swap(), rotate(), reverse() (말그대로 deque의 동작 + enque/deque 함수로)구현
// ------------------------------------------------------------------

#include "deque.h"

void	swap(t_deque *p)
{
	int	tmp1;
	int	tmp2;

	if (dqisempty(p) || p->dqcnt == 1)
		return ;
	tmp1 = dqpopfirst(p);
	tmp2 = dqpopfirst(p);
	dqaddfirst(p, tmp1);
	dqaddfirst(p, tmp2);
}

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
	data = dqpopfirst(p);
	dqaddlast(p, data);
}

void	reverse_rotate(t_deque *p)
{
	int	data;

	if (dqisempty(p))
		return ;
	data = dqpoplast(p);
	dqaddfirst(p, data);
}
