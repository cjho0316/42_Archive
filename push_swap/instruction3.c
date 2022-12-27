/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/27 19:17:51 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "deque.h"

void	pa(t_deque *b, t_deque *a)
{	
	ft_putstr_fd("pa\n", 1);
	push(a, b);
}

void	pb(t_deque *a, t_deque *b)
{
	ft_putstr_fd("pb\n", 1);
	push(a, b);
}

void	sa(t_deque *p)
{
	ft_putstr_fd("sa\n", 1);
	swap(p);
}

void	sb(t_deque *p)
{
	ft_putstr_fd("sb\n", 1);
	swap(p);
}
