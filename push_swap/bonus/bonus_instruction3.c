/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instruction3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/30 12:24:12 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "../deque.h"

void	bonus_ra(t_deque *p)
{
	rotate(p);
}

void	bonus_rb(t_deque *p)
{
	rotate(p);
}

void	bonus_rra(t_deque *p)
{
	reverse_rotate(p);
}

void	bonus_rrb(t_deque *p)
{
	reverse_rotate(p);
}

void	bonus_rrr(t_deque *p, t_deque *s)
{
	reverse_rotate(p);
	reverse_rotate(s);
}
