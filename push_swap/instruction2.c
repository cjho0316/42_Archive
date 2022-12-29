/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:50 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 09:27:59 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 나머지 짜바리 (sa, sb)->swap / (pa, pb)->push (ra, rb) -> rotate /
// (rra, rrb)-> rrotate
// ss, rr, rrr 구현하기
//--------------------------------------------------------------------
#include "deque.h"

void	p_error(int i)
{
	ft_putstr_fd("Error\n", i);
	exit(1);
}

void	ss(t_deque *p, t_deque *s)
{
	ft_putstr_fd("ss\n", 1);
	swap(p);
	swap(s);
}

void	rr(t_deque *p, t_deque *s)
{
	ft_putstr_fd("rr\n", 1);
	rotate(p);
	rotate(s);
}

void	rrr(t_deque *p, t_deque *s)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate(p);
	reverse_rotate(s);
}
