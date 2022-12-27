/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/27 12:02:34 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "deque.h"

void	ra(t_deque *p)
{
	ft_putstr_fd("ra\n", 1);
	rotate(p);
}

void	rb(t_deque *p)
{
	ft_putstr_fd("rb\n", 1);
	rotate(p);
}

void	rra(t_deque *p)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(p);
}

void	rrb(t_deque *p)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(p);
}
