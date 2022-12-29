/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instruction2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 17:39:35 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "../deque.h"

void	bonus_pa(t_deque *b, t_deque *a)
{	
	push(a, b);
}

void	bonus_pb(t_deque *a, t_deque *b)
{
	push(a, b);
}

void	bonus_sa(t_deque *p)
{
	swap(p);
}

void	bonus_sb(t_deque *p)
{
	swap(p);
}
