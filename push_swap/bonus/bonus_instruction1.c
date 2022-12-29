/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instruction1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 17:37:07 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "../deque.h"

void	bonus_ss(t_deque *p, t_deque *s)
{
	swap(p);
	swap(s);
}

void	bonus_rr(t_deque *p, t_deque *s)
{
	rotate(p);
	rotate(s);
}

void	rbonus_rr(t_deque *p, t_deque *s)
{
	reverse_rotate(p);
	reverse_rotate(s);
}
