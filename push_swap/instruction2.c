/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/11/25 22:54:29 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "deque.h"

void	dequeinit(t_deque *p)
{
	p->head = NULL;
	p->tail = NULL;
	p->dqcnt = 0;
}

void	ss(t_deque *p, t_deque *s)
{
	swap(p);
	swap(s);
}

void	rr(t_deque *p, t_deque *s)
{
	rotate(p);
	rotate(s);
}

void	rrr(t_deque *p, t_deque *s)
{
	reverse_rotate(p);
	reverse_rotate(s);
}
